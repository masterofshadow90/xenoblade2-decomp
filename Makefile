export DEVKITPRO ?= C:/devkitPro
export TOOLDIR   := $(DEVKITPRO)/devkitA64/bin
export PREFIX    := aarch64-none-elf-

CXX      := $(TOOLDIR)/$(PREFIX)g++
AS       := $(TOOLDIR)/$(PREFIX)as
LD       := $(TOOLDIR)/$(PREFIX)ld

BASEROM  := baserom/main.elf

CXXFLAGS := -O2 -mcpu=cortex-a57+crc+crypto -mtp=soft -fPIE -std=c++14 -fno-rtti -fno-exceptions -c
ASFLAGS  := -mcpu=cortex-a57+crc+crypto
LDFLAGS  := -shared -Ttext=0x00100194 -Map=build/main.map

# =========================================================================
# 📦 ARQUITECTURA EN ESPEJO EN PARALELO (100% Seguro contra 'os error 3')
# =========================================================================

MODULE_DIRS := src

ASM_DIRS    := asm

# 🎯 RADAR RECURSIVO REVOLUCIONARIO: Busca en la raíz y en CUALQUIER subcarpeta automáticamente
CPPSOURCES  := src/Monolithsoft/BF2/prog/application/BF2/main.cpp
ASM_SOURCES := asm/Monolithsoft/BF2/prog/application/BF2/main.s

C_OBJECTS   := build/target/Monolithsoft/BF2/prog/application/BF2/main.o
ASM_OBJECTS := build/base/Monolithsoft/BF2/prog/application/BF2/main.o

# =========================================================================
# 🏁 REGLAS DE COMPILACIÓN (Enlaza sólo Target para evitar colisiones en main.elf)
# =========================================================================

all: build/main.elf build_base_objects

# El binario ejecutable final sólo se nutre de C++ para no duplicar símbolos globales
build/main.elf: $(C_OBJECTS)
	@mkdir -p "build"
	@echo $(C_OBJECTS) > build/objects.txt
	$(LD) $(LDFLAGS) @build/objects.txt -o $@

# Regla obligatoria que fuerza la existencia de TODA la columna derecha para Objdiff
build_base_objects: $(ASM_OBJECTS)

# Compilación de C++ (Columna Izquierda: Target)
build/target/%.o: src/%.cpp
	@mkdir -p "$(dir $@)"
	$(CXX) $(CXXFLAGS) $< -o $@

# Compilación de Ensamblador (Columna Derecha: Base)
build/base/%.o: asm/%.s
	@mkdir -p "$(dir $@)"
	$(AS) $(ASFLAGS) $< -o $@

clean:
	@rm -rf build
