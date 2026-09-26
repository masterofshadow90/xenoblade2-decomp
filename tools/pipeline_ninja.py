#!/usr/bin/env python3
# =============================================================================
# 🥷 XENOENGINE NINJA PIPELINE GENERATOR - EMBEDDED RESPONSE FILE FIXED
# =============================================================================
import os
import re
from pathlib import Path

def find_asm_fallback(clean_rel, repo_dir):
    name_no_ext = Path(clean_rel).stem
    asm_base_dir = repo_dir / "asm"
    
    direct_s_path = asm_base_dir / clean_rel.replace(".cpp", ".s").replace(".c", ".s")
    if direct_s_path.exists():
        return f"asm/{clean_rel.replace('.cpp', '.s').replace('.c', '.s')}".replace("\\", "/")
        
    for root, dirs, files in os.walk(str(asm_base_dir)):
        for file in files:
            if file.lower() == (name_no_ext + ".s").lower():
                full_found_path = Path(root) / file
                rel = os.path.relpath(full_found_path, str(repo_dir))
                return rel.replace("\\", "/")
                
    if name_no_ext.lower() == "main" or name_no_ext.lower() == "crt0":
        crt0_path = asm_base_dir / "gf" / "FUN_00100194.s"
        if crt0_path.exists():
            return "asm/gf/FUN_00100194.s"
            
    return None

def main():
    repo_dir = Path(__file__).parent.resolve().parent
    txt_path = repo_dir / "data" / "rutas.txt"
    ninja_path = repo_dir / "build.ninja"

    print("=============================================================================")
    print("   XENOENGINE NINJA PIPELINE ORCHESTRATOR - CYCLE LOOP REPAIR ACTIVE")
    print("=============================================================================")

    if not txt_path.exists():
        print(f"[-] DIGITAL ERROR: Route map file not found at: {txt_path}")
        return

    # Clean routes without quotes for the Shinobi engine
    tool_dir = "D:/devkitPro/devkitA64/bin/"
    cxx = f"{tool_dir}aarch64-none-elf-g++.exe"
    as_tool = f"{tool_dir}aarch64-none-elf-as.exe"
    ld = f"{tool_dir}aarch64-none-elf-ld.exe"

    cxxflags = "-O2 -mcpu=cortex-a57+crc+crypto -mtp=soft -fPIE -std=c++14 -fno-rtti -fno-exceptions -c"
    asflags = "-mcpu=cortex-a57+crc+crypto"
    ldflags = "-shared -Ttext=0x00100194 -Map=build/main.map"

    with open(ninja_path, "w", encoding="utf-8") as n:
        n.write("# Reconstructed uniaxially via Ninja Build System (Fixed Linker Cycle Bug)\n")
        
        n.write("rule compile_cpp\n")
        n.write(f"  command = {cxx} {cxxflags} $in -o $out\n")
        n.write("  description = [CLANG C++] Compilando $in\n\n")

        n.write("rule assemble_s\n")
        n.write(f"  command = {as_tool} {asflags} $in -o $out\n")
        n.write("  description = [ARM64 AS] Ensamblando $in\n\n")

        # 🚀 CORRECCIÓN REY: Renombramos la variable a $out.rsp para destruir el bucle recursivo fatal de Ninja
        n.write("rule link_elf\n")
        n.write(f"  command = {ld} {ldflags} @$out.rsp -o $out\n")
        n.write("  rspfile = $out.rsp\n")
        n.write("  rspfile_content = $in\n")
        n.write("  description = [LINKER ELF] Enlazando binario ejecutable final $out\n\n")

        print("[+] Acoplando hilos en espejo horizontal por fuerza bruta de disco...")
        cpp_objects = []
        asm_objects = []

        with open(txt_path, "r", encoding="utf-8") as f:
            for line in f:
                rel_path = line.strip()
                if not rel_path:
                    continue
                
                rel_path = re.sub(r"^[a-zA-Z]:", "", rel_path)
                rel_path = rel_path.replace("\\\\", "/").replace("\\", "/")
                
                if "xenoblade2-decomp/" in rel_path:
                    rel_path = rel_path.split("xenoblade2-decomp/")[-1]
                
                if rel_path.startswith("src/"):
                    rel_path = rel_path[4:]

                ext = os.path.splitext(rel_path)[-1]

                if ext.lower() in [".cpp", ".c"]:
                    target_obj = f"build/target/{rel_path.replace(ext, '.o')}"
                    src_file = f"src/{rel_path}"
                    
                    n.write(f"build {target_obj}: compile_cpp {src_file}\n")
                    cpp_objects.append(target_obj)

                    asm_file = find_asm_fallback(rel_path, repo_dir)
                    if asm_file:
                        base_obj = f"build/base/{rel_path.replace(ext, '.o')}"
                        n.write(f"build {base_obj}: assemble_s {asm_file}\n")
                        asm_objects.append(base_obj)

        all_targets_str = " ".join(cpp_objects)
        n.write(f"\nbuild build/main.elf: link_elf {all_targets_str}\n")
        
        n.write("\ndefault build/main.elf " + " ".join(asm_objects) + "\n")

    print("=============================================================================")
    print(f"[+] PERFECT NINJA BLUEPRINT ADAPTED AT: {ninja_path.name}!")
    print(f"[+] Synchronized {len(cpp_objects)} C++ targets and {len(asm_objects)} coupled ASM bases.")
    print("=============================================================================")

if __name__ == "__main__":
    main()
