// =============================================================
// Prediccion de Desercion Estudiantil - ESP32
// WiFi Access Point + servidor web con formulario de 19 campos
// Modelo: RandomForest (19 features, 10 arboles, depth 5)
// =============================================================

#include <WiFi.h>
#include <WebServer.h>
#include "modelo_desercion.h"

const char* SSID = "DesercionPredict";
const char* PASS = "";
WebServer server(80);

// =============================================================
// MAPEOS: HTML value -> Codigo que el modelo espera
// =============================================================

// MODALIDAD DE ADMISION
// HTML: 1=1ra fase, 2=Mayor 23, 3=Internacional, 4=Cambio, 5=Otra via
// Modelo: 1, 39, 15, 42, 7
int mapearModalidad(int v) {
  switch(v) {
    case 1: return 1;
    case 2: return 39;
    case 3: return 15;
    case 4: return 42;
    case 5: return 7;
    default: return 7;
  }
}

// NIVEL EDUCATIVO (padres y madre)
// HTML: 1=Sin estudios, 2=Basica, 3=Secundaria, 4=Superior, 5=Postgrado, 6=Desconocido
// Modelo: 35, 37, 1, 40, 43, 34
int mapearEducacion(int v) {
  switch(v) {
    case 1: return 35;
    case 2: return 37;
    case 3: return 1;
    case 4: return 40;
    case 5: return 43;
    case 6: return 34;
    default: return 34;
  }
}

// OCUPACION (padres y madre)
// HTML: 1=Profesional, 2=Comerciante, 3=Obrero, 4=Desempleado, 5=Otro
// Modelo: 1, 19, 37, 29, 34
int mapearOcupacion(int v) {
  switch(v) {
    case 1: return 1;
    case 2: return 19;
    case 3: return 37;
    case 4: return 29;
    case 5: return 34;
    default: return 34;
  }
}

// =============================================================
// HTML DEL FORMULARIO (19 campos, 3 secciones)
// =============================================================

const char* HTML = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Prediccion de Desercion</title>
<style>
*{box-sizing:border-box;margin:0;padding:0}
body{font-family:Arial,sans-serif;background:#f5f5f5;padding:10px}
.c{max-width:700px;margin:0 auto;background:#fff;border-radius:8px;padding:20px;box-shadow:0 2px 6px rgba(0,0,0,.15)}
h1{font-size:1.4em;color:#2c3e50;margin-bottom:5px}
.sub{color:#666;font-size:.9em;margin-bottom:15px}
.s{background:#f9f9f9;border:1px solid #ddd;border-radius:6px;padding:12px;margin-bottom:12px}
.s h2{font-size:1.05em;color:#2c3e50;margin-bottom:10px;border-bottom:1px solid #ddd;padding-bottom:5px}
.f{margin-bottom:10px}
.f label{display:block;font-weight:bold;margin-bottom:3px;font-size:.9em}
.f select,.f input{width:100%;padding:7px;border:1px solid #bbb;border-radius:4px;font-size:.9em}
.f .h{font-size:.75em;color:#888;font-style:italic;margin-top:2px}
.rg{display:flex;gap:15px;margin-top:3px}
.rg label{font-weight:normal;display:flex;align-items:center;gap:4px;font-size:.9em}
.b{display:flex;gap:10px;margin:15px 0}
.b button{flex:1;padding:10px;border:none;border-radius:5px;font-size:1em;font-weight:bold;cursor:pointer}
.bp{background:#2980b9;color:#fff}.bp:hover{background:#1a6fa0}
.be{background:#27ae60;color:#fff}.be:hover{background:#1e8449}
.bc{background:#95a5a6;color:#fff}.bc:hover{background:#7f8c8d}
#r{display:none;border-radius:6px;padding:15px;margin-top:10px}
.cl{font-size:1.5em;font-weight:bold;margin-bottom:10px}
.pb{margin:5px 0;font-size:.9em}
.pb .bar{height:14px;border-radius:3px;background:#eee;margin-top:2px}
.pb .fl{height:100%;border-radius:3px}
.ca{color:#c0392b}.cm{color:#d68910}.cg{color:#1e8449}
.fa{background:#c0392b}.fm{background:#d68910}.fg{background:#1e8449}
</style>
</head>
<body>
<div class="c">
<h1>Prediccion de Desercion Estudiantil</h1>
<p class="sub">Complete los datos del estudiante</p>
<form id="f" onsubmit="return pre(event)">

<div class="s">
<h2>Datos generales</h2>
<div class="f"><label>Estado civil</label>
<select name="estado_civil" required>
<option value="1">Soltero/a</option><option value="2">Casado/a</option>
<option value="3">Viudo/a</option><option value="4">Divorciado/a</option>
<option value="5">Union de hecho</option><option value="6">Separado/a legalmente</option>
</select></div>
<div class="f"><label>Modalidad de admision</label>
<select name="modalidad_admision" required>
<option value="1">1ra fase - contingente general</option>
<option value="2">Mayor de 23 anos</option>
<option value="3">Estudiante internacional</option>
<option value="4">Cambio de carrera/institucion</option>
<option value="5">Otra via de ingreso</option>
</select></div>
<div class="f"><label>Carrera</label>
<select name="carrera" required>
<option value="33">Tecnologias de biocombustibles</option>
<option value="171">Animacion y diseno multimedia</option>
<option value="8014">Servicio social (vespertino)</option>
<option value="9003">Agronomia</option>
<option value="9070">Diseno de comunicacion</option>
<option value="9085">Enfermeria veterinaria</option>
<option value="9119">Ingenieria informatica</option>
<option value="9130">Equinicultura</option>
<option value="9147">Gestion</option>
<option value="9238">Servicio social</option>
<option value="9254">Turismo</option>
<option value="9500">Enfermeria</option>
<option value="9556">Higiene oral</option>
<option value="9670">Gestion publicidad y marketing</option>
<option value="9773">Periodismo y comunicacion</option>
<option value="9853">Educacion basica</option>
<option value="9991">Gestion (vespertino)</option>
</select></div>
<div class="f"><label>Turno</label><div class="rg">
<label><input type="radio" name="turno" value="1" checked> Diurno</label>
<label><input type="radio" name="turno" value="0"> Vespertino</label>
</div></div>
<div class="f"><label>Genero</label><div class="rg">
<label><input type="radio" name="genero" value="1" checked> Masculino</label>
<label><input type="radio" name="genero" value="0"> Femenino</label>
</div></div>
<div class="f"><label>Internacional</label><div class="rg">
<label><input type="radio" name="internacional" value="1"> Si</label>
<label><input type="radio" name="internacional" value="0" checked> No</label>
</div></div>
<div class="f"><label>Tiene beca</label><div class="rg">
<label><input type="radio" name="beca" value="1"> Si</label>
<label><input type="radio" name="beca" value="0" checked> No</label>
</div></div>
<div class="f"><label>Desplazado</label><div class="rg">
<label><input type="radio" name="desplazado" value="1"> Si</label>
<label><input type="radio" name="desplazado" value="0" checked> No</label>
</div><div class="h">Se mud&oacute; de su residencia habitual para estudiar</div></div>
<div class="f"><label>Pagos al dia</label><div class="rg">
<label><input type="radio" name="pagos_al_dia" value="1" checked> Si</label>
<label><input type="radio" name="pagos_al_dia" value="0"> No</label>
</div></div>
</div>

<div class="s">
<h2>Datos familiares</h2>
<div class="f"><label>Nivel educativo del padre</label>
<select name="nivel_educ_padre" required>
<option value="1">Sin estudios/no sabe leer</option>
<option value="2">Educacion basica</option>
<option value="3" selected>Educacion secundaria</option>
<option value="4">Educacion superior (grado/licenciatura)</option>
<option value="5">Postgrado (maestria/doctorado)</option>
<option value="6">Desconocido</option>
</select></div>
<div class="f"><label>Nivel educativo de la madre</label>
<select name="nivel_educ_madre" required>
<option value="1">Sin estudios/no sabe leer</option>
<option value="2">Educacion basica</option>
<option value="3" selected>Educacion secundaria</option>
<option value="4">Educacion superior (grado/licenciatura)</option>
<option value="5">Postgrado (maestria/doctorado)</option>
<option value="6">Desconocido</option>
</select></div>
<div class="f"><label>Ocupacion del padre</label>
<select name="ocupacion_padre" required>
<option value="1">Profesional/tecnico</option>
<option value="2">Comerciante/independiente</option>
<option value="3">Obrero/operario</option>
<option value="4">Desempleado</option>
<option value="5">Otro/no especificado</option>
</select></div>
<div class="f"><label>Ocupacion de la madre</label>
<select name="ocupacion_madre" required>
<option value="1">Profesional/tecnico</option>
<option value="2">Comerciante/independiente</option>
<option value="3">Obrero/operario</option>
<option value="4">Desempleado</option>
<option value="5">Otro/no especificado</option>
</select></div>
</div>

<div class="s">
<h2>1er semestre</h2>
<div class="f"><label>Unidades inscritas (max 6)</label>
<input type="number" name="inscritas_1er_sem" min="0" max="6" value="6" required></div>
<div class="f"><label>Nota promedio (0-100)</label>
<input type="number" name="nota_1er_sem" min="0" max="100" step="0.1" value="70" required></div>
<div class="f"><label>Unidades aprobadas (max 6)</label>
<input type="number" name="aprobadas_1er_sem" min="0" max="6" value="5" required></div>
</div>

<div class="s">
<h2>2do semestre</h2>
<div class="f"><label>Unidades inscritas (max 6)</label>
<input type="number" name="inscritas_2do_sem" min="0" max="6" value="6" required></div>
<div class="f"><label>Nota promedio (0-100)</label>
<input type="number" name="nota_2do_sem" min="0" max="100" step="0.1" value="67.5" required></div>
<div class="f"><label>Unidades aprobadas (max 6)</label>
<input type="number" name="aprobadas_2do_sem" min="0" max="6" value="5" required></div>
</div>

</form>

<div class="b">
<button class="bp" onclick="pre(event)">PREDECIR</button>
<button class="be" onclick="ej()">Cargar ejemplo</button>
<button class="bc" onclick="document.getElementById('f').reset();document.getElementById('r').style.display='none'">Limpiar</button>
</div>

<div id="r">
<div class="cl" id="cl"></div>
<div class="pb"><span class="ca">Abandono</span><div class="bar"><div class="fl fa" id="ba"></div></div><span id="pa"></span></div>
<div class="pb"><span class="cm">Matriculado</span><div class="bar"><div class="fl fm" id="bm"></div></div><span id="pm"></span></div>
<div class="pb"><span class="cg">Graduado</span><div class="bar"><div class="fl fg" id="bg"></div></div><span id="pg"></span></div>
</div>
</div>
<script>
function pre(e){e.preventDefault();var fd=new FormData(document.getElementById('f'));
var cs=['inscritas_1er_sem','aprobadas_1er_sem','inscritas_2do_sem','aprobadas_2do_sem'];
for(var i=0;i<cs.length;i++){var v=parseInt(fd.get(cs[i]));if(v>6){alert('Maximo 6 unidades en: '+cs[i]);return false;}}
fetch('/predecir',{method:'POST',body:fd}).then(function(r){return r.json()}).then(function(d){
var el=document.getElementById('r');el.style.display='block';
var co={Abandono:'#c0392b',Matriculado:'#d68910',Graduado:'#1e8449'};
document.getElementById('cl').textContent='Prediccion: '+d.clase;
document.getElementById('cl').style.color=co[d.clase]||'#000';
document.getElementById('ba').style.width=(d.abandono*100).toFixed(1)+'%';
document.getElementById('pa').textContent=(d.abandono*100).toFixed(1)+'%';
document.getElementById('bm').style.width=(d.matriculado*100).toFixed(1)+'%';
document.getElementById('pm').textContent=(d.matriculado*100).toFixed(1)+'%';
document.getElementById('bg').style.width=(d.graduado*100).toFixed(1)+'%';
document.getElementById('pg').textContent=(d.graduado*100).toFixed(1)+'%';});return false;}
function ej(){var f=document.getElementById('f');
f.estado_civil.value='1';f.modalidad_admision.value='1';f.carrera.value='9119';
f.turno.value='1';f.genero.value='1';f.internacional.value='0';f.beca.value='1';
f.desplazado.value='1';f.pagos_al_dia.value='1';f.nivel_educ_padre.value='2';
f.nivel_educ_madre.value='3';f.ocupacion_padre.value='3';f.ocupacion_madre.value='3';
f.inscritas_1er_sem.value='6';f.nota_1er_sem.value='70';f.aprobadas_1er_sem.value='5';
f.inscritas_2do_sem.value='6';f.nota_2do_sem.value='67.5';f.aprobadas_2do_sem.value='5';}
</script>
</body></html>
)rawliteral";

// =============================================================
// HANDLER: Pagina principal
// =============================================================

void handleRoot() {
  server.send(200, "text/html", HTML);
}

// =============================================================
// HANDLER: Predecir (POST)
// =============================================================

void handlePredecir() {
  int estado_civil     = server.arg("estado_civil").toInt();
  int modalidad_html   = server.arg("modalidad_admision").toInt();
  int carrera          = server.arg("carrera").toInt();
  int turno            = server.arg("turno").toInt();
  int genero           = server.arg("genero").toInt();
  int internacional    = server.arg("internacional").toInt();
  int beca             = server.arg("beca").toInt();
  int desplazado       = server.arg("desplazado").toInt();
  int pagos_al_dia     = server.arg("pagos_al_dia").toInt();
  int educ_padre_html  = server.arg("nivel_educ_padre").toInt();
  int educ_madre_html  = server.arg("nivel_educ_madre").toInt();
  int occ_padre_html   = server.arg("ocupacion_padre").toInt();
  int occ_madre_html   = server.arg("ocupacion_madre").toInt();
  int inscritas_1er    = server.arg("inscritas_1er_sem").toInt();
  String nota1_raw     = server.arg("nota_1er_sem");
  int aprobadas_1er    = server.arg("aprobadas_1er_sem").toInt();
  int inscritas_2do    = server.arg("inscritas_2do_sem").toInt();
  String nota2_raw     = server.arg("nota_2do_sem");
  int aprobadas_2do    = server.arg("aprobadas_2do_sem").toInt();

  // Validaciones: max 6 unidades
  if (inscritas_1er > 6) inscritas_1er = 6;
  if (aprobadas_1er > 6) aprobadas_1er = 6;
  if (inscritas_2do > 6) inscritas_2do = 6;
  if (aprobadas_2do > 6) aprobadas_2do = 6;

  // Conversiones
  float nota1 = nota1_raw.toFloat() / 5.0;
  float nota2 = nota2_raw.toFloat() / 5.0;
  int modalidad    = mapearModalidad(modalidad_html);
  int educ_padre   = mapearEducacion(educ_padre_html);
  int educ_madre   = mapearEducacion(educ_madre_html);
  int occ_padre    = mapearOcupacion(occ_padre_html);
  int occ_madre    = mapearOcupacion(occ_madre_html);

  // VECTOR DE ENTRADA (19 features)
  // Orden exacto como en entrenamiento Python (dataset_reducido.csv):
  //  [0]  estado_civil
  //  [1]  modalidad_admision
  //  [2]  carrera
  //  [3]  turno
  //  [4]  genero
  //  [5]  internacional
  //  [6]  beca
  //  [7]  desplazado
  //  [8]  pagos_al_dia
  //  [9]  nivel_educ_padre
  //  [10] nivel_educ_madre
  //  [11] ocupacion_padre
  //  [12] ocupacion_madre
  //  [13] inscritas_1er_sem
  //  [14] nota_1er_sem
  //  [15] aprobadas_1er_sem
  //  [16] inscritas_2do_sem
  //  [17] nota_2do_sem
  //  [18] aprobadas_2do_sem

  double input[19] = {
    (double)estado_civil,
    (double)modalidad,
    (double)carrera,
    (double)turno,
    (double)genero,
    (double)internacional,
    (double)beca,
    (double)desplazado,
    (double)pagos_al_dia,
    (double)educ_padre,
    (double)educ_madre,
    (double)occ_padre,
    (double)occ_madre,
    (double)inscritas_1er,
    (double)nota1,
    (double)aprobadas_1er,
    (double)inscritas_2do,
    (double)nota2,
    (double)aprobadas_2do
  };

  // Prediccion
  double output[3];
  score(input, output);

  int mejor = 0;
  if (output[1] > output[mejor]) mejor = 1;
  if (output[2] > output[mejor]) mejor = 2;
  const char* clases[] = {"Abandono", "Graduado", "Matriculado"};

  // JSON
  String json = "{\"clase\":\"" + String(clases[mejor]) + "\",";
  json += "\"abandono\":" + String(output[0], 4) + ",";
  json += "\"graduado\":" + String(output[1], 4) + ",";
  json += "\"matriculado\":" + String(output[2], 4) + "}";
  server.send(200, "application/json", json);
}

// =============================================================
// SETUP / LOOP
// =============================================================

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("\n=== Prediccion de Desercion Estudiantil ===");
  Serial.println("Iniciando WiFi AP...");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(SSID, PASS);
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());
  server.on("/", handleRoot);
  server.on("/predecir", HTTP_POST, handlePredecir);
  server.begin();
  Serial.println("Servidor listo en http://192.168.4.1");
}

void loop() {
  server.handleClient();
  delay(2);
}
