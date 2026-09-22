import csv

# Rutas locales en tu carpeta D:\xenoblade2-decomp
archivo_entrada = 'simbolos_ghidra.csv'  # Tu archivo exportado de Ghidra
archivo_salida = 'symbols.txt'

# Tu arsenal de la Phase 2 con sus identidades legítimas cazadas en el silicio
identidades_cazadas = {
    "00368760": "BTL_Skill_GetCharacterTablePointer", 
    "003a14c8": "MNU_SkillTree_UpdateNodeLayoutUI",    
    "003a47f0": "Shop_Transaction_Handler",            
    "000c53dc": "gf_String_formatArgs",                 
    "00196928": "gf_AssetManager_validatePackHeader"   
}

with open(archivo_entrada, mode='r', encoding='utf-8') as f_in:
    reader = csv.DictReader(f_in)
    
    with open(archivo_salida, mode='w', encoding='utf-8') as f_out:
        f_out.write("// =============================================================================\n")
        f_out.write("// MAPA DE SÍMBOLOS OFICIAL - XENOBLADE CHRONICLES 2 / TORNA DECOMPILATION\n")
        f_out.write("// BUILD ID: A75512BE30BB2A8C880177505D7A0B3E (Segmento main)\n")
        f_out.write("// =============================================================================\n\n")
        
        for row in reader:
            name = row["Name"]
            location = row["Location"]
            symbol_type = row["Type"]
            
            # Purgamos los residuos estéticos y etiquetas temporales de Ghidra
            if any(x in name for x in ["switchD", "default", "caseD", "LAB_", "EXT_FUN_"]):
                continue
                
            try:
                # Extraemos la dirección virtual y limpiamos corchetes
                clean_addr = location.split('[')[-1].replace(']', '').strip().lower()
                
                # Forzamos formato universal de 8 caracteres (offsets ARM64 de la scene)
                if len(clean_addr) > 8:
                    clean_addr = clean_addr[-8:]
                elif len(clean_addr) < 8:
                    clean_addr = clean_addr.zfill(8)

                # =====================================================================
                # LA ASIGNACIÓN DE ESTADO (Todo entra como Non-Matching para .cpp)
                # =====================================================================
                status_flag = "non_matching"
                
                if clean_addr in identidades_cazadas:
                    # Si es una de tus inmensas victorias, le inyectamos su nombre legítimo
                    final_name = identidades_cazadas[clean_addr]
                    comment = "Identity verified by masterofshadow90. Ready for .cpp matching split"
                else:
                    # Si no, conserva el nombre genérico de Ghidra como tarea pendiente
                    final_name = name
                    comment = "todo: isolate function boundaries"

                # Escribimos con la sintaxis exacta de decomp.dev: Nombre = 0xDirección;
                f_out.write(f"{final_name:<50} = 0x{clean_addr}; // type:{symbol_type.lower().replace(' ', '_')} status:{status_flag} notes:{comment}\n")
                
            except Exception:
                continue

print("¡Metamorfosis completada con éxito, comandante jefe! Todo el andamio está en NON_MATCHING.")
