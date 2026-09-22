#ifdef __cplusplus
extern "C" {
#endif

    // 0x002bcabc - Despachador de Matrices de Mirada y Tracking del Player
    void gf_CameraPlayer_updateLookState(void* this_ptr) {}


    // 0x002bcfa4 - Capturador e Interrogador del Descriptor del Objetivo del Player
    void* gf_CameraPlayer_getTargetDescriptor(void* this_ptr, int target_id) {return nullptr;}

    // 0x002bd0cc - Resolvedor de Instancias y Objetivos Activos en la Lente del Player
    void* gf_CameraPlayer_resolveTargetInstance(void* this_ptr, int target_id) {return nullptr;}

    // 0x002bd248 - Resolvedor y Capturador de Descriptores de Script del Player
    void* gf_CameraPlayer_getScriptDescriptor(void* this_ptr, int script_id) {return nullptr;}

    // 0x002bd2dc - Constructor de la Clase CameraPlayer
    void gf_CameraPlayer_ctor(void* this_ptr) {}

    // 0x002bdd68 - Variante Secundaria de Capturador de Descriptores de Script del Player
    void* gf_CameraPlayer_getScriptDescriptor2(void* this_ptr, int script_id) {return nullptr;}

    // 0x002bff78 - Resolvedor y Capturador de Parámetros Superiores (Upper) del Player
    void* gf_CameraPlayer_getUpperDescriptor(void* this_ptr, int param_id) {return nullptr;}

    // FUN_002c063c
    void* gf_CameraPlayer_getPlayerTarget(void* this_ptr, int player_id) {return nullptr;}

#ifdef __cplusplus
}
#endif
