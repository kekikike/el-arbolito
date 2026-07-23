/*
 * Prediccion de Desercion Estudiantil - ESP32
 * 
 * WiFi Access Point + Servidor Web
 * Modelo RandomForest exportado con m2cgen
 * 
 * Conectarse al WiFi: "DesercionPredict" (sin clave)
 * Abrir en navegador: http://192.168.4.1
 */

#include <WiFi.h>
#include <WebServer.h>
#include "modelo_desercion.h"

// ========== CONFIGURACION WiFi AP ==========
const char* AP_SSID = "DesercionPredict";
const char* AP_PASS = "";  // Sin clave

const IPAddress AP_IP(192, 168, 4, 1);
const IPAddress AP_GATEWAY(192, 168, 4, 1);
const IPAddress AP_SUBNET(255, 255, 255, 0);

WebServer server(80);

// ========== CONSTANTE DE CONVERSION ==========
// En la universidad hay maximo 6 materias por semestre
#define MATERIAS_POR_SEMESTRE 6

// Escala de notas: usuario ingresa 0-100, modelo espera 0-20
#define ESCALA_USUARIO 100.0
#define ESCALA_MODELO  20.0

// ========== MAPEO DE OCUPACIONES ==========
// Codigos originales UCI (clasificacion ISCO) -> 5 grupos
//
// Grupo 1 - Profesional/tecnico:
//   Codigos: 1,2,3,4,5,6,11,12,13,14,22
//   Incluye: representantes legislativos, profesionales, cientificos,
//            tecnicos, personal administrativo, docentes
//
// Grupo 2 - Comerciante/independiente:
//   Codigos: 9,10,18,19,20,25,26,27,31,33
//   Incluye: comercio, servicios, ventas, seguridad, transporte
//
// Grupo 3 - Obrero/operario:
//   Codigos: 37,38,39,40,41,42,43,44
//   Incluye: artesanal, operarios, ensambladores, no cualificado
//
// Grupo 4 - Desempleado:
//   Codigo: 29
//
// Grupo 5 - Otro/no especificado:
//   Codigos: 30,34,35,36

int mapearOcupacion(int grupo) {
  // El usuario selecciona 1-5 en el formulario
  // Se mapea al codigo ISCO promedio de cada grupo para que el modelo
  // reciba un valor razonable dentro del rango que vio en entrenamiento
  switch(grupo) {
    case 1: return 1;   // Profesional/tecnico -> codigo UCI 1
    case 2: return 19;  // Comerciante -> codigo UCI 19 (el mas comun del grupo)
    case 3: return 37;  // Obrero -> codigo UCI 37 (el mas comun del grupo)
    case 4: return 29;  // Desempleado -> codigo UCI 29
    case 5: return 34;  // Otro -> codigo UCI 34
    default: return 34;
  }
}

// ========== HTML DEL FORMULARIO ==========
const char* HTML_FORMULARIO = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Prediccion de Desercion</title>
  <style>
    * { box-sizing: border-box; margin: 0; padding: 0; }
    body { font-family: Arial, sans-serif; background: #f5f5f5; padding: 15px; }
    .container { max-width: 600px; margin: 0 auto; background: white; border-radius: 10px; padding: 20px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }
    h1 { color: #2c3e50; font-size: 22px; margin-bottom: 5px; }
    .subtitle { color: #7f8c8d; font-size: 14px; margin-bottom: 20px; }
    .field { margin-bottom: 15px; }
    label { display: block; font-weight: bold; color: #34495e; margin-bottom: 5px; font-size: 14px; }
    input[type="number"], select { width: 100%; padding: 10px; border: 2px solid #ddd; border-radius: 6px; font-size: 16px; }
    input[type="number"]:focus, select:focus { border-color: #3498db; outline: none; }
    .radio-group { display: flex; gap: 20px; }
    .radio-group label { font-weight: normal; display: flex; align-items: center; gap: 5px; }
    .hint { color: #95a5a6; font-size: 12px; margin-top: 3px; }
    .btn { width: 100%; padding: 12px; background: #27ae60; color: white; border: none; border-radius: 6px; font-size: 18px; font-weight: bold; cursor: pointer; margin-top: 10px; }
    .btn:hover { background: #219a52; }
    .btn-ejemplo { background: #3498db; margin-top: 8px; }
    .btn-ejemplo:hover { background: #2980b9; }
    .resultado { margin-top: 20px; padding: 20px; border-radius: 10px; display: none; }
    .resultado h2 { font-size: 24px; margin-bottom: 15px; }
    .prob-bar { margin-bottom: 10px; }
    .prob-label { font-weight: bold; font-size: 14px; }
    .prob-fill { height: 25px; border-radius: 4px; position: relative; background: #ecf0f1; }
    .prob-value { position: absolute; right: 8px; top: 3px; font-weight: bold; font-size: 13px; }
    .abandono .prob-fill { background: linear-gradient(90deg, #e74c3c var(--pct), #ecf0f1 var(--pct)); }
    .graduado .prob-fill { background: linear-gradient(90deg, #27ae60 var(--pct), #ecf0f1 var(--pct)); }
    .matriculado .prob-fill { background: linear-gradient(90deg, #f39c12 var(--pct), #ecf0f1 var(--pct)); }
  </style>
</head>
<body>
  <div class="container">
    <h1>Prediccion de Desercion</h1>
    <p class="subtitle">Complete los datos del estudiante</p>
    
    <form id="form" method="POST" action="/predecir">
      <div class="field">
        <label for="nota1">Nota promedio 1er semestre (0-100)</label>
        <input type="number" id="nota1" name="nota1" min="0" max="100" step="0.1" required>
        <div class="hint">Escala 0-100 (boliviana). Se divide entre 5 para el modelo.</div>
      </div>
      
      <div class="field">
        <label for="nota2">Nota promedio 2do semestre (0-100)</label>
        <input type="number" id="nota2" name="nota2" min="0" max="100" step="0.1" required>
        <div class="hint">Escala 0-100 (boliviana). Se divide entre 5 para el modelo.</div>
      </div>
      
      <div class="field">
        <label for="mat1">Materias aprobadas 1er semestre (0-6)</label>
        <input type="number" id="mat1" name="mat1" min="0" max="6" required>
        <div class="hint">Maximo 6 materias por semestre.</div>
      </div>
      
      <div class="field">
        <label for="mat2">Materias aprobadas 2do semestre (0-6)</label>
        <input type="number" id="mat2" name="mat2" min="0" max="6" required>
        <div class="hint">Maximo 6 materias por semestre.</div>
      </div>
      
      <div class="field">
        <label>Tiene beca</label>
        <div class="radio-group">
          <label><input type="radio" name="beca" value="1" checked> Si</label>
          <label><input type="radio" name="beca" value="0"> No</label>
        </div>
      </div>
      
      <div class="field">
        <label>Pagos al dia</label>
        <div class="radio-group">
          <label><input type="radio" name="pagos" value="1" checked> Si</label>
          <label><input type="radio" name="pagos" value="0"> No</label>
        </div>
      </div>
      
      <div class="field">
        <label for="edad">Edad al ingreso (17-70)</label>
        <input type="number" id="edad" name="edad" min="17" max="70" required>
      </div>
      
      <div class="field">
        <label for="occ_padre">Ocupacion del padre</label>
        <select id="occ_padre" name="occ_padre" required>
          <option value="1">1 - Profesional/tecnico</option>
          <option value="2">2 - Comerciante/independiente</option>
          <option value="3">3 - Obrero/operario</option>
          <option value="4">4 - Desempleado</option>
          <option value="5">5 - Otro/no especificado</option>
        </select>
      </div>
      
      <div class="field">
        <label for="occ_madre">Ocupacion de la madre</label>
        <select id="occ_madre" name="occ_madre" required>
          <option value="1">1 - Profesional/tecnico</option>
          <option value="2">2 - Comerciante/independiente</option>
          <option value="3">3 - Obrero/operario</option>
          <option value="4">4 - Desempleado</option>
          <option value="5">5 - Otro/no especificado</option>
        </select>
      </div>
      
      <button type="submit" class="btn">PREDECIR</button>
      <button type="button" class="btn btn-ejemplo" onclick="cargarEjemplo()">Cargar ejemplo</button>
    </form>
    
    <div class="resultado" id="resultado">
      <h2 id="prediccion"></h2>
      <div class="prob-bar abandono">
        <div class="prob-label">Abandono</div>
        <div class="prob-fill" id="barra-abandono" style="--pct: 0%">
          <span class="prob-value" id="pct-abandono">0%</span>
        </div>
      </div>
      <div class="prob-bar matriculado">
        <div class="prob-label">Matriculado</div>
        <div class="prob-fill" id="barra-matriculado" style="--pct: 0%">
          <span class="prob-value" id="pct-matriculado">0%</span>
        </div>
      </div>
      <div class="prob-bar graduado">
        <div class="prob-label">Graduado</div>
        <div class="prob-fill" id="barra-graduado" style="--pct: 0%">
          <span class="prob-value" id="pct-graduado">0%</span>
        </div>
      </div>
    </div>
    
    <script>
      function cargarEjemplo() {
        document.getElementById('nota1').value = 70;
        document.getElementById('nota2').value = 67.5;
        document.getElementById('mat1').value = 5;
        document.getElementById('mat2').value = 5;
        document.querySelector('input[name="beca"][value="1"]').checked = true;
        document.querySelector('input[name="pagos"][value="1"]').checked = true;
        document.getElementById('edad').value = 19;
        document.getElementById('occ_padre').value = '1';
        document.getElementById('occ_madre').value = '1';
      }
      
      document.getElementById('form').addEventListener('submit', function(e) {
        e.preventDefault();
        var mat1 = parseInt(document.getElementById('mat1').value);
        var mat2 = parseInt(document.getElementById('mat2').value);
        if (mat1 > 6 || mat2 > 6) {
          alert('Maximo 6 materias por semestre');
          return;
        }
        var formData = new FormData(this);
        fetch('/predecir', { method: 'POST', body: formData })
          .then(function(r) { return r.json(); })
          .then(function(d) {
            document.getElementById('resultado').style.display = 'block';
            document.getElementById('prediccion').textContent = 'Prediccion: ' + d.clase;
            var colores = { 'Abandono': '#e74c3c', 'Matriculado': '#f39c12', 'Graduado': '#27ae60' };
            document.getElementById('prediccion').style.color = colores[d.clase] || '#2c3e50';
            document.getElementById('barra-abandono').style.setProperty('--pct', d.abandono + '%');
            document.getElementById('pct-abandono').textContent = d.abandono.toFixed(1) + '%';
            document.getElementById('barra-matriculado').style.setProperty('--pct', d.matriculado + '%');
            document.getElementById('pct-matriculado').textContent = d.matriculado.toFixed(1) + '%';
            document.getElementById('barra-graduado').style.setProperty('--pct', d.graduado + '%');
            document.getElementById('pct-graduado').textContent = d.graduado.toFixed(1) + '%';
          });
      });
    </script>
  </div>
</body>
</html>
)rawliteral";

// ========== HANDLER: Pagina principal ==========
void handleRoot() {
  server.send(200, "text/html", HTML_FORMULARIO);
}

// ========== HANDLER: Predecir (POST) ==========
void handlePredecir() {
  // 1. Obtener valores del formulario
  float nota1_raw = server.arg("nota1").toFloat();
  float nota2_raw = server.arg("nota2").toFloat();
  int mat1 = server.arg("mat1").toInt();
  int mat2 = server.arg("mat2").toInt();
  int beca = server.arg("beca").toInt();
  int pagos = server.arg("pagos").toInt();
  int edad = server.arg("edad").toInt();
  int occ_padre_grupo = server.arg("occ_padre").toInt();
  int occ_madre_grupo = server.arg("occ_madre").toInt();

  // 2. Conversiones (mismo criterio que Python)
  float nota1 = nota1_raw / ESCALA_USUARIO * ESCALA_MODELO;
  float nota2 = nota2_raw / ESCALA_USUARIO * ESCALA_MODELO;
  
  // Limitar materias a maximo 6
  if (mat1 > MATERIAS_POR_SEMESTRE) mat1 = MATERIAS_POR_SEMESTRE;
  if (mat2 > MATERIAS_POR_SEMESTRE) mat2 = MATERIAS_POR_SEMESTRE;
  
  // Mapear ocupaciones de grupos (1-5) a codigos ISCO
  int occ_padre = mapearOcupacion(occ_padre_grupo);
  int occ_madre = mapearOcupacion(occ_madre_grupo);

  // 3. Armar vector de entrada (mismo orden que el modelo)
  // Orden: nota_1er_sem, nota_2do_sem, materias_1er_sem, materias_2do_sem,
  //        tiene_beca, pagos_al_dia, edad_ingreso, ocupacion_padre, ocupacion_madre
  double input[9] = {
    (double)nota1,
    (double)nota2,
    (double)mat1,
    (double)mat2,
    (double)beca,
    (double)pagos,
    (double)edad,
    (double)occ_padre,
    (double)occ_madre
  };

  // 4. Ejecutar modelo
  double output[3];
  score(input, output);

  // 5. Encontrar clase ganadora
  int mejor = 0;
  if (output[1] > output[0]) mejor = 1;
  if (output[2] > output[mejor]) mejor = 2;

  const char* clases[] = {"Abandono", "Graduado", "Matriculado"};

  // 6. Responder en JSON
  String json = "{";
  json += "\"clase\":\"" + String(clases[mejor]) + "\",";
  json += "\"abandono\":" + String(output[0] * 100.0, 1) + ",";
  json += "\"graduado\":" + String(output[1] * 100.0, 1) + ",";
  json += "\"matriculado\":" + String(output[2] * 100.0, 1);
  json += "}";

  server.send(200, "application/json", json);
}

// ========== SETUP ==========
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("=== Prediccion de Desercion Estudiantil ===");

  // Iniciar Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(AP_IP, AP_GATEWAY, AP_SUBNET);
  WiFi.softAP(AP_SSID, AP_PASS);

  Serial.println("Access Point iniciado:");
  Serial.println("  SSID: " + String(AP_SSID));
  Serial.println("  IP:   " + WiFi.softAPIP().toString());
  Serial.println();
  Serial.println("Conectese al WiFi y abra: http://192.168.4.1");

  // Configurar rutas del servidor
  server.on("/", HTTP_GET, handleRoot);
  server.on("/predecir", HTTP_POST, handlePredecir);
  server.begin();

  Serial.println("Servidor web iniciado");
}

// ========== LOOP ==========
void loop() {
  server.handleClient();
}
