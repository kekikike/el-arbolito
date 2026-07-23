import tkinter as tk
from tkinter import ttk, messagebox
import joblib
import numpy as np

MATERIAS_POR_SEMESTRE = 6
ESCALA_NOTA_USUARIO = 100
ESCALA_NOTA_MODELO = 20

# ============================================================
# MAPEOS PARA LA UI
# ============================================================

ESTADO_CIVIL_VALORES = {
    1: "Soltero/a",
    2: "Casado/a",
    3: "Viudo/a",
    4: "Divorciado/a",
    5: "Union de hecho",
    6: "Separado/a legalmente",
}

MODALIDAD_VALORES = {
    1: "1ra fase - contingente general",
    2: "Mayor de 23 anos",
    3: "Estudiante internacional",
    4: "Cambio de carrera/institucion",
    5: "Otra via de ingreso",
}

CARRERA_VALORES = {
    33: "Tecnologias de biocombustibles",
    171: "Animacion y diseno multimedia",
    8014: "Servicio social (vespertino)",
    9003: "Agronomia",
    9070: "Diseno de comunicacion",
    9085: "Enfermeria veterinaria",
    9119: "Ingenieria informatica",
    9130: "Equinicultura",
    9147: "Gestion",
    9238: "Servicio social",
    9254: "Turismo",
    9500: "Enfermeria",
    9556: "Higiene oral",
    9670: "Gestion publicidad y marketing",
    9773: "Periodismo y comunicacion",
    9853: "Educacion basica",
    9991: "Gestion (vespertino)",
}

NIVEL_EDUC_VALORES = {
    1: "Sin estudios/no sabe leer",
    2: "Educacion basica",
    3: "Educacion secundaria",
    4: "Educacion superior (grado/licenciatura)",
    5: "Postgrado (maestria/doctorado)",
    6: "Desconocido",
}

OCUPACION_VALORES = {
    1: "Profesional/tecnico",
    2: "Comerciante/independiente",
    3: "Obrero/operario",
    4: "Desempleado",
    5: "Otro/no especificado",
}

# ============================================================
# EJEMPLO
# ============================================================

EJEMPLO = {
    "estado_civil": 1,
    "modalidad_admision": 1,
    "carrera": 9119,
    "turno": 1,
    "genero": 1,
    "internacional": 0,
    "beca": 1,
    "desplazado": 1,
    "pagos_al_dia": 1,
    "nivel_educ_padre": 2,
    "nivel_educ_madre": 3,
    "ocupacion_padre": 3,
    "ocupacion_madre": 3,
    "inscritas_1er_sem": 6,
    "nota_1er_sem": 70.0,
    "aprobadas_1er_sem": 5,
    "inscritas_2do_sem": 6,
    "nota_2do_sem": 67.5,
    "aprobadas_2do_sem": 5,
}

# ============================================================
# SECCIONES Y CAMPOS
# ============================================================

SECCIONES = [
    {
        "titulo": "Datos generales",
        "fields": [
            {"key": "estado_civil", "label": "Estado civil", "type": "combo", "values": ESTADO_CIVIL_VALORES},
            {"key": "modalidad_admision", "label": "Modalidad de admision", "type": "combo", "values": MODALIDAD_VALORES},
            {"key": "carrera", "label": "Carrera", "type": "combo", "values": CARRERA_VALORES},
            {"key": "turno", "label": "Turno", "type": "yesno_custom", "si_label": "Diurno", "no_label": "Vespertino"},
            {"key": "genero", "label": "Genero", "type": "yesno_custom", "si_label": "Masculino", "no_label": "Femenino"},
            {"key": "internacional", "label": "Estudiante internacional", "type": "yesno"},
            {"key": "beca", "label": "Tiene beca", "type": "yesno"},
            {"key": "desplazado", "label": "Desplazado", "type": "yesno", "hint": "Se mudó de su residencia habitual para estudiar"},
            {"key": "pagos_al_dia", "label": "Pagos al dia", "type": "yesno"},
        ],
    },
    {
        "titulo": "Datos familiares",
        "fields": [
            {"key": "nivel_educ_padre", "label": "Nivel educativo del padre", "type": "combo", "values": NIVEL_EDUC_VALORES},
            {"key": "nivel_educ_madre", "label": "Nivel educativo de la madre", "type": "combo", "values": NIVEL_EDUC_VALORES},
            {"key": "ocupacion_padre", "label": "Ocupacion del padre", "type": "combo", "values": OCUPACION_VALORES},
            {"key": "ocupacion_madre", "label": "Ocupacion de la madre", "type": "combo", "values": OCUPACION_VALORES},
        ],
    },
    {
        "titulo": "1er semestre",
        "fields": [
            {"key": "inscritas_1er_sem", "label": f"Unidades inscritas (0-{MATERIAS_POR_SEMESTRE})", "type": "int_entry", "min": 0, "max": MATERIAS_POR_SEMESTRE},
            {"key": "nota_1er_sem", "label": "Nota promedio (0-100)", "type": "float_entry", "min": 0.0, "max": 100.0},
            {"key": "aprobadas_1er_sem", "label": f"Unidades aprobadas (0-{MATERIAS_POR_SEMESTRE})", "type": "int_entry", "min": 0, "max": MATERIAS_POR_SEMESTRE},
        ],
    },
    {
        "titulo": "2do semestre",
        "fields": [
            {"key": "inscritas_2do_sem", "label": f"Unidades inscritas (0-{MATERIAS_POR_SEMESTRE})", "type": "int_entry", "min": 0, "max": MATERIAS_POR_SEMESTRE},
            {"key": "nota_2do_sem", "label": "Nota promedio (0-100)", "type": "float_entry", "min": 0.0, "max": 100.0},
            {"key": "aprobadas_2do_sem", "label": f"Unidades aprobadas (0-{MATERIAS_POR_SEMESTRE})", "type": "int_entry", "min": 0, "max": MATERIAS_POR_SEMESTRE},
        ],
    },
]

# ============================================================
# FUENTES
# ============================================================

FONT_LABEL = ("Segoe UI", 13)
FONT_ENTRY = ("Segoe UI", 13)
FONT_HEADER = ("Segoe UI", 18, "bold")
FONT_SECTION = ("Segoe UI", 14, "bold")
FONT_BTN = ("Segoe UI", 13, "bold")
FONT_RESULT = ("Segoe UI", 22, "bold")
FONT_PROB = ("Segoe UI", 14)
FONT_HINT = ("Segoe UI", 10, "italic")


# ============================================================
# APP
# ============================================================

class AppDesercion:
    def __init__(self, root):
        self.root = root
        self.root.title("Prediccion de Desercion Estudiantil")
        self.root.configure(bg="#f0f0f0")

        sw = root.winfo_screenwidth()
        sh = root.winfo_screenheight()
        w = int(sw * 0.6)
        h = int(sh * 0.88)
        x = (sw - w) // 2
        y = (sh - h) // 2
        self.root.geometry(f"{w}x{h}+{x}+{y}")
        self.root.minsize(700, 600)
        self.root.resizable(True, True)

        self.entries = {}
        self._load_model()
        self._build_ui()

    def _load_model(self):
        try:
            artifact = joblib.load("modelo_desercion.pkl")
            self.model = artifact["model"]
            self.le = artifact["label_encoder"]
            self.feature_names = artifact.get("feature_names", [])
        except FileNotFoundError:
            messagebox.showerror("Error", "No se encontro modelo_desercion.pkl\nEjecute: python train_model_expandido.py")
            self.root.destroy()
            return

    def _build_ui(self):
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)

        canvas = tk.Canvas(self.root, borderwidth=0, bg="#f0f0f0")
        scrollbar = ttk.Scrollbar(self.root, orient="vertical", command=canvas.yview)
        scroll_frame = ttk.Frame(canvas)

        scroll_frame.bind("<Configure>", lambda e: canvas.configure(scrollregion=canvas.bbox("all")))
        canvas.create_window((0, 0), window=scroll_frame, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)

        canvas.pack(side="left", fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")

        main = scroll_frame
        main.columnconfigure(0, weight=1)
        main.columnconfigure(1, weight=1)
        main.columnconfigure(2, weight=0)

        ttk.Label(main, text="Prediccion de Desercion Estudiantil", font=FONT_HEADER).grid(
            row=0, column=0, columnspan=3, pady=(5, 2), sticky="w"
        )
        ttk.Label(main, text="Complete los datos del estudiante", font=("Segoe UI", 12)).grid(
            row=1, column=0, columnspan=3, pady=(0, 10), sticky="w"
        )

        current_row = 2

        for seccion in SECCIONES:
            frame = ttk.LabelFrame(main, text=f" {seccion['titulo']} ", padding=10)
            frame.grid(row=current_row, column=0, columnspan=3, sticky="ew", padx=5, pady=5)
            frame.columnconfigure(0, weight=1)
            frame.columnconfigure(1, weight=1)
            frame.columnconfigure(2, weight=0)

            for i, cfg in enumerate(seccion["fields"]):
                r = i
                frame.rowconfigure(r, minsize=35)

                lbl = ttk.Label(frame, text=cfg["label"], font=FONT_LABEL)
                lbl.grid(row=r, column=0, sticky="w", padx=(10, 15), pady=3)

                widget = self._create_widget(frame, cfg)
                widget.grid(row=r, column=1, sticky="w", padx=5, pady=3)

                if cfg.get("hint"):
                    hint = ttk.Label(frame, text=cfg["hint"], font=FONT_HINT, foreground="#666666")
                    hint.grid(row=r, column=2, sticky="w", padx=5, pady=3)

            current_row += 1

        btn_frame = ttk.Frame(main)
        btn_frame.grid(row=current_row, column=0, columnspan=3, pady=15)
        ttk.Button(btn_frame, text="PREDECIR", command=self._predecir, style="Big.TButton").pack(side="left", padx=10)
        ttk.Button(btn_frame, text="Cargar ejemplo", command=self._cargar_ejemplo).pack(side="left", padx=10)
        ttk.Button(btn_frame, text="Limpiar", command=self._limpiar).pack(side="left", padx=10)

        current_row += 1
        self.result_frame = ttk.LabelFrame(main, text=" Resultado ", padding=15)
        self.result_frame.grid(row=current_row, column=0, columnspan=3, sticky="ew", padx=5, pady=(5, 0))
        self.result_frame.columnconfigure(0, weight=1)

        self.result_label = ttk.Label(
            self.result_frame,
            text="Complete los campos y presione PREDECIR",
            font=FONT_RESULT,
        )
        self.result_label.grid(row=0, column=0, pady=(0, 10), sticky="w")

        self.prob_frame = ttk.Frame(self.result_frame)
        self.prob_frame.grid(row=1, column=0, sticky="ew")
        self.prob_frame.columnconfigure(0, weight=1)
        self.prob_frame.columnconfigure(1, weight=1)
        self.prob_frame.columnconfigure(2, weight=1)

        self.prob_labels = {}
        colors = {"Abandono": "#c0392b", "Matriculado": "#d68910", "Graduado": "#1e8449"}
        for i, cls in enumerate(["Abandono", "Matriculado", "Graduado"]):
            lbl = ttk.Label(self.prob_frame, text=f"{cls}: --", font=FONT_PROB, foreground=colors[cls])
            lbl.grid(row=0, column=i, padx=10, sticky="w")
            self.prob_labels[cls] = lbl

        def _on_mousewheel(event):
            canvas.yview_scroll(int(-1 * (event.delta / 120)), "units")
        canvas.bind_all("<MouseWheel>", _on_mousewheel)

    def _create_widget(self, parent, cfg):
        ftype = cfg["type"]

        if ftype == "int_entry":
            var = tk.StringVar()
            entry = ttk.Entry(parent, textvariable=var, width=12, font=FONT_ENTRY)
            vcmd = (self.root.register(self._validate_int), "%P")
            entry.configure(validate="key", validatecommand=vcmd)
            self.entries[cfg["key"]] = ("entry", var, "int")
            return entry

        elif ftype == "float_entry":
            var = tk.StringVar()
            entry = ttk.Entry(parent, textvariable=var, width=12, font=FONT_ENTRY)
            vcmd = (self.root.register(self._validate_float), "%P")
            entry.configure(validate="key", validatecommand=vcmd)
            self.entries[cfg["key"]] = ("entry", var, "float")
            return entry

        elif ftype == "yesno":
            var = tk.StringVar(value="Si")
            frame = ttk.Frame(parent)
            ttk.Radiobutton(frame, text="Si", variable=var, value="Si").pack(side="left", padx=5)
            ttk.Radiobutton(frame, text="No", variable=var, value="No").pack(side="left", padx=5)
            self.entries[cfg["key"]] = ("yesno", var, None)
            return frame

        elif ftype == "yesno_custom":
            var = tk.StringVar(value=cfg.get("si_value", "Si"))
            frame = ttk.Frame(parent)
            ttk.Radiobutton(frame, text=cfg["si_label"], variable=var, value=cfg.get("si_value", "Si")).pack(side="left", padx=5)
            ttk.Radiobutton(frame, text=cfg["no_label"], variable=var, value=cfg.get("no_value", "No")).pack(side="left", padx=5)
            self.entries[cfg["key"]] = ("yesno", var, cfg)
            return frame

        elif ftype == "combo":
            var = tk.StringVar()
            values = [f"{k} - {v}" for k, v in cfg["values"].items()]
            combo = ttk.Combobox(parent, textvariable=var, values=values, width=35, state="readonly", font=FONT_ENTRY)
            self.entries[cfg["key"]] = ("combo", var, cfg)
            return combo

    def _validate_int(self, value):
        if value == "" or value == "-":
            return True
        try:
            int(value)
            return True
        except ValueError:
            return False

    def _validate_float(self, value):
        if value == "" or value == "-" or value == ".":
            return True
        try:
            float(value)
            return True
        except ValueError:
            return False

    def _get_values(self):
        values = []

        for seccion in SECCIONES:
            for cfg in seccion["fields"]:
                key = cfg["key"]
                wtype, var, subtype = self.entries[key]

                if key == "turno":
                    values.append(1 if var.get() == "Si" else 0)
                elif key == "genero":
                    values.append(1 if var.get() == "Si" else 0)
                elif wtype == "entry":
                    raw = var.get()
                    if not raw:
                        messagebox.showwarning("Campo incompleto", f"Ingrese: {cfg['label']}")
                        return None
                    if subtype == "int":
                        val = int(raw)
                        if val < cfg["min"] or val > cfg["max"]:
                            messagebox.showwarning("Valor invalido", f"{cfg['label']}: entre {cfg['min']} y {cfg['max']}")
                            return None
                        if key in ("inscritas_1er_sem", "aprobadas_1er_sem", "inscritas_2do_sem", "aprobadas_2do_sem"):
                            if val > MATERIAS_POR_SEMESTRE:
                                messagebox.showwarning("Valor invalido", f"Maximo {MATERIAS_POR_SEMESTRE} unidades por semestre")
                                return None
                        values.append(val)
                    else:
                        val = float(raw)
                        if val < cfg["min"] or val > cfg["max"]:
                            messagebox.showwarning("Valor invalido", f"{cfg['label']}: entre {cfg['min']} y {cfg['max']}")
                            return None
                        values.append(round(val / ESCALA_NOTA_USUARIO * ESCALA_NOTA_MODELO, 2))
                elif wtype == "yesno":
                    if key == "pagos_al_dia":
                        values.append(1 if var.get() == "Si" else 0)
                    elif key == "internacional":
                        values.append(1 if var.get() == "Si" else 0)
                    elif key == "beca":
                        values.append(1 if var.get() == "Si" else 0)
                    elif key == "desplazado":
                        values.append(1 if var.get() == "Si" else 0)
                elif wtype == "combo":
                    raw = var.get()
                    if not raw:
                        messagebox.showwarning("Campo incompleto", f"Seleccione: {cfg['label']}")
                        return None
                    val = int(raw.split(" - ")[0])
                    values.append(val)

        if len(values) != len(self.feature_names):
            messagebox.showerror("Error interno", f"Se esperaban {len(self.feature_names)} features, se obtuvieron {len(values)}")
            return None

        return np.array([values])

    def _predecir(self):
        X = self._get_values()
        if X is None:
            return

        pred = self.model.predict(X)[0]
        proba = self.model.predict_proba(X)[0]

        colors = {"Abandono": "#c0392b", "Matriculado": "#d68910", "Graduado": "#1e8449"}
        self.result_label.config(text=f"Prediccion: {pred}", foreground=colors.get(pred, "black"), font=FONT_RESULT)

        for cls in ["Abandono", "Matriculado", "Graduado"]:
            idx = list(self.le.classes_).index(cls)
            pct = proba[idx] * 100
            bar_len = int(pct / 5)
            bar = "#" * bar_len + "-" * (20 - bar_len)
            self.prob_labels[cls].config(text=f"{cls}: {pct:5.1f}%  {bar}", foreground=colors[cls])

    def _cargar_ejemplo(self):
        for seccion in SECCIONES:
            for cfg in seccion["fields"]:
                key = cfg["key"]
                if key not in EJEMPLO:
                    continue
                val = EJEMPLO[key]
                wtype, var, subtype = self.entries[key]

                if wtype == "entry":
                    var.set(str(int(val)) if isinstance(val, int) else str(val))
                elif wtype == "yesno":
                    if key == "turno":
                        var.set("Si" if val == 1 else "No")
                    elif key == "genero":
                        var.set("Si" if val == 1 else "No")
                    else:
                        var.set("Si" if val == 1 else "No")
                elif wtype == "combo":
                    label = cfg["values"].get(val, str(val))
                    var.set(f"{val} - {label}")

    def _limpiar(self):
        for seccion in SECCIONES:
            for cfg in seccion["fields"]:
                self.entries[cfg["key"]][1].set("")
        self.result_label.config(text="Complete los campos y presione PREDECIR", foreground="black", font=FONT_RESULT)
        for cls in ["Abandono", "Matriculado", "Graduado"]:
            self.prob_labels[cls].config(text=f"{cls}: --")


if __name__ == "__main__":
    root = tk.Tk()
    app = AppDesercion(root)
    root.mainloop()
