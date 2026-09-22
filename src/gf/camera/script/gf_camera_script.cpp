#include "../../../symbols.h"

// Prototipos locales temporales de las subfunciones del juego llamadas internamente
extern "C" {
    void* FUN_00323360(int param_1);
    int FUN_00755514();
    int FUN_007554e0(void* param_1);
    int FUN_007558f8(void* param_1, const char* path, int index);
    void FUN_00797a88(const char* file, const char* label, int line);
    int FUN_007c0820();
    
    // Declaración de las funciones internas del módulo para la resolución de tipos
    void* FUN_0028285c();
    void* FUN_0029052c(int size, void* ptr, int type, const char* file, int line);
    void* FUN_002cc264();
}

extern "C" {

// =========================================================================
// FUNCIÓN 1: gf_CameraScript_selectRandom (Dirección: 0x002cb5b0)
// =========================================================================
int gf_CameraScript_selectRandom(void* this_ptr, unsigned int priority) {return 0;}

// =========================================================================
// FUNCIÓN 2: gf_CameraScript_parseParam (Dirección: 0x002cb750)
// =========================================================================
void gf_CameraScript_parseParam(void* this_ptr, int param_id, void* out_struct) {}


// =========================================================================
// FUNCIÓN 3: gf_CameraScript_allocateManager - Asignador y Mánager del Pool de Scripts de Cámara (Dirección: 0x002cd170)
// =========================================================================
void gf_CameraScript_allocateManager(void* context, void* param_2, void* param_3, int flag) {}

} // extern "C"
