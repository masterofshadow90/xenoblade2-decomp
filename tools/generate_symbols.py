#!/usr/bin/env python3
import csv
import sys
from pathlib import Path

def main():
    repo_dir = Path(__file__).parent.resolve().parent
    csv_path = repo_dir / "baserom" / "ghidra_export.csv"  # Cambia por el nombre de tu archivo subido
    output_path = repo_dir / "symbols.txt"

    print("=============================================================================")
    print("   XENOENGINE SYMBOL GENERATOR - CONVERTING GHIDRA EXPORT TO PRODUCTION")
    print("=============================================================================")

    # Si el usuario guardó el volcado con otro nombre, lo buscamos en baserom/
    if not csv_path.exists():
        # Intentamos buscar cualquier archivo .csv o .txt en baserom/
        baserom_dir = repo_dir / "baserom"
        files = list(baserom_dir.glob("*.csv")) + list(baserom_dir.glob("*.txt"))
        if files:
            csv_path = files[0]
        else:
            print("[-] ERROR CRÍTICO: Pon el archivo de Ghidra dentro de la carpeta baserom/")
            return

    print(f"[+] Cargando volcado forense desde: {csv_path.name}")
    symbols_count = 0

    with open(csv_path, "r", encoding="utf-8") as f_in, open(output_path, "w", encoding="utf-8") as f_out:
        f_out.write("// =============================================================================\n")
        f_out.write("// 🗺️ MASTER SYMBOLS PROFILE - XENOBLADE CHRONICLES 2 DECOMPILATION PIPELINE\n")
        f_out.write("// TARGET: LEGITIMATE DECRYPTED ELF (0x00100194 CORE LAYOUT)\n")
        f_out.write("// =============================================================================\n\n")

        reader = csv.reader(f_in)
        header = next(reader, None)  # Saltamos la cabecera ("Name","Location",...)

        for row in reader:
            if len(row) < 3:
                continue
            name = row[0].strip()
            location = row[1].strip()
            item_type = row[2].strip()

            # Purgamos etiquetas de saltos dinámicos e imports dinámicos sin dirección fija
            if "switchD" in name or "caseD_" in name or "default" in name or "Thunk" in item_type:
                continue
            if "External" in location or "[ ? ]" in location:
                continue

            # Convertimos la cota de Ghidra en una dirección hexadecimal pura compatible con la scene
            try:
                addr_int = int(location, 16)
                formatted_addr = f"0x{addr_int:08x}"
                f_out.write(f"{name} = {formatted_addr};\n")
                symbols_count += 1
            except ValueError:
                continue

    print(f"[+] ¡ÉXITO! Se han inyectado {symbols_count} funciones reales en symbols.txt")

if __name__ == "__main__":
    main()
