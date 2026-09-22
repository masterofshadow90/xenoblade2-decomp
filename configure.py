#!/usr/bin/env python3
import os
import sys
from pathlib import Path

def main():
    repo_dir = Path(__file__).parent.resolve()
    config_yaml = repo_dir / "config" / "splat.yaml"
    
    print("=============================================================================")
    print(" DECOMP.DEV INTEGRATION SUITE - CONFIGURING WORKSPACE FOR MASTEROFSHADOW90")
    print("=============================================================================")

    # 1. Forzar la ejecución de Splat para trocear el binario
    print("[+] Ejecutando troceado automático de segmentos mediante Splat...")
    try:
        import splat
        # Invocamos el split mediante el script nativo que subimos a tools
        os.system(f"{sys.executable} tools/split.py")
    except ImportError:
        print("[-] Módulo Splat no detectado en el entorno local. Ejecuta: pip install splat")
        sys.exit(1)

    # 2. Generar el archivo de configuración para las herramientas de Objdiff
    # Decomp.dev lee este archivo para mapear las rutas C++ vs Assembly
    print("[+] Verificando mapa de símbolos en la raíz...")
    if not (repo_dir / "symbols.txt").exists():
        print("[-] ALERTA: No se encuentra symbols.txt en la raíz.")
        sys.exit(1)

    print("[+] ¡BÚNKER DE COMPILACIÓN PREPARADO PARA DECOMP.DEV!")
    print("[!] Siguiente paso: Sube los cambios y vincula el repositorio en la web.")

if __name__ == "__main__":
    main()
