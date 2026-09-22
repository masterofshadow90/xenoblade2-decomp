#ifdef __cplusplus
extern "C" {
#endif

void gf_CameraChainAttack_setupTracking(void* this_ptr, void* heap, const char* file, int line, const char* tag) {}
void gf_CameraChainAttack_updateState(void* this_ptr) {}
int gf_CameraChainAttack_findAnimationIndex(void* this_ptr, void* anim, void* context, int id) {return 0;}
void gf_CameraChainAttack_formatDebugString(void* this_ptr, int format_id, const char* param1, const char* param2) {}
void gf_CameraChainAttack_setupSpecialMode(void* this_ptr, int mode_id, const char* tag, void* context, int priority) {}
void gf_CameraChainAttack_initSpecialArts(void* this_ptr, int arts_count, int mode_flag, int priority) {}
void gf_CameraChainAttack_initSingleArts(void* this_ptr, int art_id, int priority) {}
void gf_CameraChainAttack_ctor(void* this_ptr) {}
void* gf_CameraChainAttack_getPilotDescriptor(void* this_ptr, int pilot_id) {return nullptr;}
void gf_CameraChainAttack_initCollisionCam(void* this_ptr, void* stage, void* context) {}
void gf_CameraChainAttack_initPilotStance(void* this_ptr, int pilot_id) {}
void gf_CameraChainAttack_initPilotLerp(void* this_ptr, void* lerp_data, void* context) {}
void* gf_CameraChainAttack_resolveTargetInstance(void* this_ptr, int target_id) {return nullptr;}
void gf_CameraChainAttack_initCameraModes(void* this_ptr, void* mode_data, void* context) {}
void* gf_CameraChainAttack_resolveDistanceTarget(void* this_ptr, int target_id) {return nullptr;}
void gf_CameraChainAttack_initDefaultParams(void* this_ptr, void* param_data, void* context) {}
void gf_CameraChainAttack_interpolatePilot2(void* this_ptr, void* lerp_data, void* context) {}
void gf_CameraChainAttack_interpolatePilot3(void* this_ptr, void* lerp_data, void* context) {}

#ifdef __cplusplus
}
#endif
