#include <stdint.h>
void CUALQUIER_COSA_PARA_ROMPER(void) {
    __asm__ volatile("nop\n nop\n nop\n");
}

// Declaración de prototipos de las funciones externas del motor de Monolith
void gf_ScriptCameraEntity_clearComponents(void);
void FUN_002c7018(uint64_t x5, uint64_t x0, uint32_t w1, uint32_t w2, uint64_t x3, uint32_t w4, uint32_t w6);

void gf_ScriptCameraEntity_setupComponents(uint64_t* param_1, uint64_t param_2) {
    // x19 almacena param_1 (x0) y x20 almacena param_2 (x1)
    // ldr w8, [x20, #0x1c] -> Lee el valor en el offset 0x1c de param_2
    uint32_t w8 = *(uint32_t*)(param_2 + 0x1c);

    // cbnz w8, .L_002c8050 -> Si w8 NO es cero, salta (aquí hacemos el 'if' invertido)
    if (w8 == 0) {
        // bl gf_ScriptCameraEntity_clearComponents
        gf_ScriptCameraEntity_clearComponents();

        // ldp x5, x0, [x19] -> Carga los dos primeros valores apuntados por param_1
        uint64_t x5_val = param_1[0];
        uint64_t x0_val = param_1[1];

        // Primera llamada a FUN_002c7018 (w4=0x22a0000, w1=3, w2=1, w6=wzr)
        // El registro x3 carga la dirección del string apuntado por adrp/add
        uint64_t x3_string1 = 0; // Lo ajustaremos con el puntero real del string
        FUN_002c7018(x5_val, x0_val, 3, 1, x3_string1, 0x22a0000, 0);

        // Segunda llamada a FUN_002c7018 (w20=0x8200000 debido al mov + movk)
        uint64_t x3_string2 = 0;
        FUN_002c7018(x5_val, x0_val, 4, 8, x3_string2, 0x8020000, 0);
    }
}
