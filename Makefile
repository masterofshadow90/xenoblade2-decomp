export DEVKITPRO ?= C:/devkitPro
export TOOLDIR   := $(DEVKITPRO)/devkitA64/bin
export PREFIX    := aarch64-none-elf-

CXX      := $(TOOLDIR)/$(PREFIX)g++
AS       := $(TOOLDIR)/$(PREFIX)as
LD       := $(TOOLDIR)/$(PREFIX)ld

CXXFLAGS := -O2 -march=armv8-a -std=c++14 -fno-rtti -fno-exceptions -c
ASFLAGS  := -march=armv8-a
LDFLAGS  := -shared -Ttext=0x002bcabc -Map=build/main.map

# =========================================================================
# 📦 ARQUITECTURA EN ESPEJO EN PARALELO (100% Seguro contra 'os error 3')
# =========================================================================

MODULE_DIRS := src src/gf/camera src/gf/camera/chain_attack src/gf/camera/fusion_combo \
               src/gf/camera/gimmick src/gf/camera/plugin src/gf/camera/script \
               src/gf/asset src/gf/data src/gf/field asm/gf

ASM_DIRS    := asm asm/gf/camera asm/gf/camera/chain_attack asm/gf/camera/fusion_combo \
               asm/gf/camera/gimmick asm/gf/camera/plugin asm/gf/camera/script \
               asm/gf/asset asm/gf/data asm/gf/field asm/gf

# Descubrimiento plano absoluto e independiente
CPPSOURCES  := $(foreach dir,$(MODULE_DIRS),$(wildcard $(dir)/*.cpp))
ASM_SOURCES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))

# Mapeo simétrico forzado 1:1 (Garantiza que ambas carpetas nazcan en build/)
C_OBJECTS   := $(patsubst src/%.cpp, build/target/%.o, $(CPPSOURCES))
ASM_OBJECTS := $(patsubst asm/%.s, build/base/%.o, $(ASM_SOURCES))

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
