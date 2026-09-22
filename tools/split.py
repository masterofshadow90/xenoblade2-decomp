#!/usr/bin/env python3
import os
import sys
import subprocess
from pathlib import Path

def main():
    # Geolocalizamos las cotas físicas del taller de masterofshadow90
    tools_dir = Path(__file__).parent.resolve()
    repo_dir = tools_dir.parent
    config_file = repo_dir / "config" / "splat.yaml"
    
    print("=============================================================================")
    # Mensaje de bitácora oficial en la terminal
    print(" XENOBLADE CHRONICLES 2 DECOMPILATION PIPELINE - SPLITTING MONOLITH BINARY")
    print("=============================================================================")
    
    if not config_file.exists():
        print(f"[-] ERROR BALÍSTICO: No se encuentra el plano de configuración en: {config_file}")
        sys.exit(1)
        
    # Comando militar para invocar el binario de splat a través del intérprete
    # Le ordenamos que lea el perfil yaml de la carpeta config
    cmd = [sys.executable, "-m", "splat", "split", str(config_file)]
    
    try:
        print("[+] Lanzando la orden de fuego por hardware a Splat...")
        result = subprocess.run(cmd, cwd=str(repo_dir), check=True)
        if result.returncode == 0:
            print("[+] ¡METAMORFOSIS COMPLETADA! El binario se ha troceado en la carpeta /asm")
    except subprocess.CalledProcessError as e:
        print(f"[-] CRASH EN EL MONTON: Splat devolvió un error de ejecución: {e}")
        print("[!] Asegúrate de tener instalado splat localmente: pip install splat")
        sys.exit(1)
    except FileNotFoundError:
        print("[-] ERROR DE TOOLCHAIN: No se pudo invocar el módulo. Ejecuta: pip install splat")
        sys.exit(1)

if __name__ == "__main__":
    main()
