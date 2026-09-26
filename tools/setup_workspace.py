#!/usr/bin/env python3
# =============================================================================
# 📦 XENOENGINE WORKSPACE SCAFOLDING GENERATOR - REAL TXT SOURCE PARSER
# =============================================================================
import os
from pathlib import Path

def main():
    repo_dir = Path(__file__).parent.resolve().parent
    # 🎯 APUNTAMOS ESTRICTAMENTE AL NUEVO ARCHIVO GENERADO POR TU DISCO DURO
    txt_path = repo_dir / "data" / "rutas.txt"
    src_base_dir = repo_dir / "src"

    print("=============================================================================")
    print("   XENOENGINE AUTOMATED WORKSPACE ORCHESTRATOR - REAL TXT SOLVER ACTIVE")
    print("=============================================================================")

    if not txt_path.exists():
        print(f"[-] ERROR DIGITAL: No se encuentra tu mapa en: {txt_path}")
        print("[!] Por favor, ejecuta primero: dir /b /s src\\*.cpp src\\*.h > data\\rutas.txt")
        return

    print(f"[+] Cargando hilos de rutas reales desde {txt_path.name}...")
    files_to_create = []
    with open(txt_path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            clean_line = line.strip()
            if not clean_line:
                continue
                
            # Si el comando guardó la ruta absoluta (D:\xenoblade2-decomp\src\...),
            # nos quedamos estrictamente con la porción relativa para no duplicar carpetas
            if "src" + os.sep in clean_line:
                parts = clean_line.split("src" + os.sep)
                clean_line = parts[-1]
                
            if clean_line and clean_line not in files_to_create:
                files_to_create.append(clean_line)

    print(f"[+] Indexados {len(files_to_create)} casilleros legítimos únicos basados en tu disco.")
    created_folders = 0
    file_count = 0

    for rel_file_path in files_to_create:
        # Forzamos las barras nativas del sistema operativo de Windows
        full_file_path = src_base_dir / rel_file_path
        target_dir = full_file_path.parent
        
        # Si la subcarpeta no existe físicamente, la levantamos por hardware de inmediato
        if not target_dir.exists():
            os.makedirs(target_dir, exist_ok=True)
            created_folders += 1

        # Hacemos nacer el archivo .cpp o .h completamente vacío (0 KB) para objdiff
        if not full_file_path.exists():
            with open(full_file_path, "w", encoding="utf-8") as f_empty:
                pass 
            file_count += 1

    print("=============================================================================")
    print(f"[+] ¡PERÍMETRO TOTALMENTE AMURALLADO CON EXCLUSIVIDAD INDUSTRIAL!")
    print(f"[+] Saneadas y levantadas {created_folders} subcarpetas recursivas en src/")
    print(f"[+] Generados {file_count} archivos espejo (.cpp/.h) listos para Objdiff")
    print("=============================================================================")

if __name__ == "__main__":
    main()
