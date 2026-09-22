#ifndef BF2_SYMBOLS_H
#define BF2_SYMBOLS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file gf_camera_script.cpp
 * @brief Subsystem: Camera Script Entity Components
 */

/* 0x002cb568 */
int gf_CameraScript_selectRandom(void* this_ptr, unsigned int priority);

/* 0x002cb750 */
void gf_CameraScript_parseParam(void* this_ptr, int param_id, void* out_struct);

/* 0x002cd170 - Reserva memoria en el Heap de Monolith Soft e incrementa el contador de referencias del script activo. */
void gf_CameraScript_allocateManager(void* context, void* param_2, void* param_3, int flag);

/**
 * @file gf_camera_player.cpp
 * @brief Subsystem: Controls Player Camera
 */

/* 0x002bcabc */
void gf_CameraPlayer_updateLookState(void* this_ptr);

/* 0x002bcfa4 */
void* gf_CameraPlayer_getTargetDescriptor(void* this_ptr, int target_id);

/* 0x002bd0cc */
void* gf_CameraPlayer_resolveTargetInstance(void* this_ptr, int target_id);

/* 0x002bd248 */
void* gf_CameraPlayer_getScriptDescriptor(void* this_ptr, int script_id);

/* 0x002bd2dc */
void gf_CameraPlayer_ctor(void* this_ptr);

/* 0x002bdd68 */
void* gf_CameraPlayer_getScriptDescriptor2(void* this_ptr, int script_id);

/* 0x002bff78 */
void* gf_CameraPlayer_getUpperDescriptor(void* this_ptr, int param_id);

/* 0x002c063c */
void* gf_CameraPlayer_getPlayerTarget(void* this_ptr, int player_id);

/**
 * @file gf_camera_chain_attack.cpp
 * @brief Subsystem: Chain Attack Cinematic Camera Management
 */

/* 0x002b516c */
void gf_CameraChainAttack_setupTracking(void* this_ptr, void* heap, const char* file, int line, const char* tag);

/* 0x002b51d8 */
void gf_CameraChainAttack_updateState(void* this_ptr);

/* 0x002b5878 */
int gf_CameraChainAttack_findAnimationIndex(void* this_ptr, void* anim, void* context, int id);

/* 0x002b5934 */
void gf_CameraChainAttack_formatDebugString(char* dest_buffer, int format_id, const char* param1, const char* param2);

/* 0x002b5a34 */
void gf_CameraChainAttack_setupSpecialMode(void* this_ptr, int mode_id, const char* tag, void* context, int priority);

/* 0x002b5e08 */
void gf_CameraChainAttack_initSpecialArts(void* this_ptr, int arts_count, int mode_flag, int priority);

/* 0x002b5f7c */
void gf_CameraChainAttack_initSingleArts(void* this_ptr, int art_id, int priority);

/* 0x002b606c */
void gf_CameraChainAttack_ctor(void* this_ptr);

/* 0x002b808c */
void* gf_CameraChainAttack_getPilotDescriptor(void* this_ptr, int pilot_id);

/* 0x002b8120 */
void gf_CameraChainAttack_initCollisionCam(void* this_ptr, void* stage, void* context);

/* 0x002b8764 */
void gf_CameraChainAttack_initPilotStance(void* this_ptr, int pilot_id);

/* 0x002b8834 */
void gf_CameraChainAttack_initPilotLerp(void* this_ptr, void* lerp_data, void* context);

/* 0x002bcff8 */
void* gf_CameraChainAttack_resolveTargetInstance(void* this_ptr, int target_id);

/* 0x002bd4e4 */
void gf_CameraChainAttack_initCameraModes(void* this_ptr, void* mode_data, void* context);

/* 0x002bdcb0 */
void* gf_CameraChainAttack_resolveDistanceTarget(void* this_ptr, int target_id);

/* 0x002bde38 */
void gf_CameraChainAttack_initDefaultParams(void* this_ptr, void* param_data, void* context);

/* 0x002bebd8 */
void gf_CameraChainAttack_interpolatePilot2(void* this_ptr, void* lerp_data, void* context);

/* 0x002bf51c */
void gf_CameraChainAttack_interpolatePilot3(void* this_ptr, void* lerp_data, void* context);

/**
 * @file gf_camera_fusion_combo.cpp
 * @brief Subsystem: Fusion Combo Cinematic Camera Management
 */

/* 0x002b60ac */
void gf_CameraFusionCombo_dispatchArtsTransition(void* this_ptr, void* heap, void* context);

/* 0x002b78e8 */
void gf_CameraFusionCombo_formatEventString(void* this_ptr, int event_id, int priority, int code, int flag);

/**
 * @file gf_camera_gimmick.cpp
 * @brief Subsystem: Gimmick and Environment Camera Management
 */

/* 0x002c06b0 */
void gf_CameraGimmick_ctor(void* this_ptr);

/* 0x002c06e8 */
void gf_CameraGimmick_initGimmickCam(void* this_ptr, void* gimmick_data, void* context);

/**
 * @file gf_camera_player_target.cpp
 * @brief Subsystem: Player Target Cam (Enemy Lock-on) Management
 */

/* 0x002c0968 */
void gf_CameraPlayerTarget_initArtsTracking(void* this_ptr, void* param_2, void* param_3);

/* 0x002c0b84 */
void* gf_CameraPlayerTarget_updateState(void* this_ptr);

 /**
 * @file gf_camera_subview.cpp
 * @brief Subsystem: Subview Camera Management
 */

/* 0x002c0c74 */
void gf_CameraSubview_syncBdatDistance(void* this_ptr, void* param_2, void* param_3, unsigned long flags);

/* 0x002c0dc0 */
void* gf_CameraSubview_updateState(void* this_ptr);

/**
 * @file gf_camera_plugin_ship_roll.cpp
 * @brief Subsystem: Camera Ship Roll Plugin Management
 */

/* 0x002c0eb0 */
void* gf_CameraPlugin_updateState(void* this_ptr);

/* 0x002c0fa0 */
void* gf_CameraPlugin_updateState2(void* this_ptr);

/* 0x002c10c8 */
void gf_CameraPlugin_ctor(void* this_ptr);

/* 0x002c1130 */
void* gf_CameraPlugin_updateState3(void* this_ptr, void* param_2, void* param_3);

/**
 * @file gf_asset_manager.cpp
 * @brief Subsystem: Global Resource RAM/VRAM Allocator and Manager
 */

/* 0x00296928 */
void* gf_AssetManager_validatePackHeader(void* header_ptr);

/* 0x00296998 */
void gf_AssetManager_clearContainers(void* this_ptr);

/* 0x002969e8 */
void gf_AssetManager_flushContainers(void* this_ptr);

/* 0x00296a5c */
void gf_AssetManager_setupContainers(void* this_ptr, int param_2, int param_3, void* context_ptr);

/* 0x00296b28 */
void gf_AssetManager_teardownContainers(void* this_ptr);

/* 0x002978cc */
void gf_AssetManager_initStreamDescriptor(void* this_ptr);

/* 0x00297dcc */
void gf_AssetManager_commitStreamNodes(void* this_ptr, long param_2, void* context_ptr);

/* 0x00297fc8 */
void gf_AssetManager_initializeStreamQueue(void* this_ptr, unsigned int queue_id, void* context_ptr);

/**
 * @file gf_asset_pack.cpp
 */
/* 0x002981a8 */
void gf_AssetPack_initializeStreamQueue(void* context_ptr, void* param_2, void* param_3);

/**
 * @file gf_asset_resource.cpp
 */
/* 0x002983ac */
void gf_AssetResource_dtor(void* this_ptr);

/* 0x00298428 */
void* gf_AssetResource_getNextResource(void* this_ptr);

/**
 * @file gf_asset_setup.cpp
 * @brief Subsystem: Asset Loading Buffer Setup and Configuration
 */
/* 0x0029df34 */
void gf_AssetSetup_ctor(void* this_ptr);

/**
 * @file gf_asset_filesize_pool.cpp
 * @brief Subsystem: Resource File Size Guard and Pool Validator
 */
/* 0x002ab7c0 */
void gf_AssetFilesizePool_initializeExtendResource(float param_1, void* this_ptr, unsigned int param_3, void* param_4, unsigned char flag);

/**
 * @file gf_asset_slot.cpp
 * @brief Subsystem: Character and Blade RAM Load Slot Administrator
 */

/* 0x002ac76c */
void gf_AssetSlot_ctor(void* this_ptr, void* context_ptr);

/**
 * @file gf_asset_slot_mapping.cpp
 * @brief Subsystem: Character ID to Physical RAM Slot Translation Mapper
 */

/* 0x002c5718 */
void gf_AssetSlotMapping_indexActiveDescriptors(void* this_ptr, unsigned int limit);

/**
 * @file gf_bdat_bgm.cpp
 * @brief Subsystem: Background Music Data Table Indexer
 */
/* 0x002d20e0 */ void FUN_002d20e0(void *this_ptr, unsigned int bgm_id);

/**
 * @file gf_bdat_blade.cpp
 * @brief Subsystem: Blade Parameter and Affinity Data Table Indexer
 */
/* 0x002d212c */ void FUN_002d212c(void *this_ptr, unsigned int blade_id);

/**
 * @file gf_bdat_btl.cpp
 * @brief Subsystem: Battle Mechanics and Math Data Table Indexer
 */
/* 0x002d2170 */ void FUN_002d2170(void *this_ptr, unsigned int btl_param_id);

/**
 * @file gf_bdat_chrbl.cpp
 * @brief Subsystem: Character Blade Parameter Data Table Indexer
 */
/* 0x002d21b8 */ void FUN_002d21b8(void *this_ptr, unsigned int chrbl_id);

/**
 * @file gf_bdat_chrdr.cpp
 * @brief Subsystem: Driver Parameter Data Table Indexer
 */
/* 0x002d2200 */ void FUN_002d2200(void *this_ptr, unsigned int driver_id);

/**
 * @file gf_bdat_chrenarrange.cpp
 * @brief Subsystem: Driver Equipment Arrange Data Table Indexer
 */
/* 0x002d2248 */ void FUN_002d2248(void *this_ptr, unsigned int arrange_id);

/**
 * @file gf_bdat_chrenparam.cpp
 * @brief Subsystem: Character Enemy Parameter Data Table Indexer
 */
/* 0x002d2290 */ void FUN_002d2290(void *this_ptr, unsigned int param_id);

/**
 * @file gf_bdat_cond.cpp
 * @brief Subsystem: Battle Condition and Status Effect Data Table Indexer
 */
/* 0x002d22d8 */ void FUN_002d22d8(void *this_ptr, unsigned int condition_id);

/**
 * @file gf_bdat_item.cpp
 * @brief Subsystem: Item Database Data Table Indexer
 */
/* 0x002d2320 */ void FUN_002d2320(void *this_ptr, unsigned int item_id);

/**
 * @file gf_bdat_lookat.cpp
 * @brief Subsystem: Look-At Tracking Parameters Data Table Indexer
 */
/* 0x002d2368 */ void FUN_002d2368(void *this_ptr, unsigned int lookat_id);

/**
 * @file gf_bdat_maplist.cpp
 * @brief Subsystem: Map and Region Directory Data Table Indexer
 */
/* 0x002d23b0 */ void FUN_002d23b0(void *this_ptr, unsigned int map_id);

/**
 * @file gf_bdat_msg.cpp
 * @brief Subsystem: Message and Dialogue String Data Table Indexer
 */
/* 0x002d23f8 */ void FUN_002d23f8(void *this_ptr, unsigned int msg_id);

/**
 * @file gf_bdat_quest.cpp
 * @brief Subsystem: Quest Progression and Rewards Data Table Indexer
 */
/* 0x002d2440 */ void FUN_002d2440(void *this_ptr, unsigned int quest_id);

/**
 * @file gf_bdat_rsc.cpp
 * @brief Subsystem: Resource Configuration and Parameter Data Table Indexer
 */
/* 0x002d2488 */ void FUN_002d2488(void *this_ptr, unsigned int rsc_id);

/**
 * @file gf_bdat_shop.cpp
 * @brief Subsystem: Shop Inventories and Regions Development Data Table Indexer
 */
/* 0x002d24d0 */ void FUN_002d24d0(void *this_ptr, unsigned int shop_id);

/**
 * @file gf_bdat_unique_motion.cpp
 * @brief Subsystem: Unique Combat Motion and Animation Data Table Indexer
 */
/* 0x002d2518 */ void FUN_002d2518(void *this_ptr, unsigned int motion_id);

/**
 * @file gf_data_aoc.cpp
 * @brief Subsystem: Add-On Content and DLC Data Table Indexer
 */
/* 0x002d2560 */ void FUN_002d2560(void *this_ptr, unsigned int aoc_id);

/**
 * @file gf_data_bdat.cpp
 * @brief Subsystem: Core Binary Data Table File Stream Manager
 */
/* 0x002d25a8 */ void FUN_002d25a8(void *this_ptr, unsigned int bdat_stream_id);

/**
 * @file gf_data_manager.cpp
 * @brief Subsystem: Global Data Subsystem Marshaller and Administrator
 */
/* 0x002d25f0 */ void FUN_002d25f0(void *this_ptr, unsigned int manager_id);

/**
 * @file gf_data_obj.cpp
 * @brief Subsystem: Game World Dynamic Entity Object Registrar
 */
/* 0x002d2638 */ void FUN_002d2638(void *this_ptr, unsigned int obj_data_id);

/**
 * @file gf_data_store.cpp
 * @brief Subsystem: Persistent Save-Data and Permanent Storage Registry
 */
/* 0x002d2680 */ void FUN_002d2680(void *this_ptr, unsigned int store_id);

/**
 * @file gf_game_flag.cpp
 * @brief Subsystem: Bitmask Scenario Progress and Quest Flag Evaluation
 */
/* 0x002d26c8 */ void FUN_002d26c8(void *this_ptr, unsigned int flag_id);

// =========================================================================
// --- SECCIÓN: gf/field/ (Subsistema del Mundo Abierto de Alrest) ---
// =========================================================================

/**
 * @file gf_field_bgm.cpp
 * @brief Subsystem: Field Background Music and Environment Audio Initializer
 */
/* 0x003150d8 */
void gf_FieldBgm_initializeStaticDatabase(void* this_ptr);

/**
 * @file gf_field_collect.cpp
 * @brief Subsystem: Field Collectable Resource Node Evaluator
 */
/* 0x003177ec */
unsigned int gf_FieldCollect_queryBladeSkillStatus(void* this_ptr, unsigned int skill_id);

/**
 * @file gf_field_dmg.cpp
 * @brief Subsystem: Field Fall Damage and Terrain Hazard Evaluator
 */
/* 0x00317ff0 */
void* gf_FieldDmg_queryEnvironmentalDamageStatus(void* this_ptr, unsigned int trigger_id);

/**
 * @file gf_field_gimmick.cpp
 * @brief Subsystem: Field Interactive Object Gimmick Evaluator
 */
/* 0x0035f1a4 */
void gf_FieldGimmick_initializeStaticDatabase(long param_1);

/* 0x00360880 */
int gf_FieldGimmick_evaluateCollisionTrigger(long param_1, unsigned int param_2, int param_3);

/**
 * @file gf_field_locator.cpp
 * @brief Subsystem: Field Position and Spawn Locator Node Evaluator
 */

/* 0x003614e8 */
void gf_FieldLocator_dtor(void* this_ptr);

/**
 * @file gf_field_lod.cpp
 * @brief Subsystem: Field Level of Detail (LOD) Graphics Evaluator
 */
/* 0x003175cc */ void FUN_003175cc(void *this_ptr);

/**
 * @file gf_field_manager.cpp
 * @brief Subsystem: Global Field Subsystem Marshaller and Administrator
 */
/* 0x00315040 */ void FUN_00315040(void *this_ptr);

/**
 * @file gf_field_mapse.cpp
 * @brief Subsystem: Field Map Static Sound Effects Node Evaluator
 */
/* 0x00317a94 */ void FUN_00317a94(void *this_ptr);

/**
 * @file gf_field_map_gimmick.cpp
 * @brief Subsystem: Field Map Mesh Gimmick Trigger Evaluator
 */
/* 0x00317874 */ void FUN_00317874(void *this_ptr);

/**
 * @file gf_field_sound.cpp
 * @brief Subsystem: Field Environment Dynamic Sound Trigger Evaluator
 */
/* 0x00317984 */ void FUN_00317984(void *this_ptr);

/**
 * @file gf_field_tbox.cpp
 * @brief Subsystem: Field Treasure Box (Tbox) Container Evaluator
 */
/* 0x00317f68 */ void FUN_00317f68(void *this_ptr);

/**
 * @file gf_field_time.cpp
 * @brief Subsystem: Field Time Clock and Day-Night Cycle Evaluator
 */
/* 0x0031817c */ void FUN_0031817c(void *this_ptr);

/**
 * @file gf_field_weather.cpp
 * @brief Subsystem: Field Dynamic Weather State Evaluator
 */
/* 0x0031825c */ void FUN_00318200(void *this_ptr);

/**
 * @file gf_field_weather_obj.cpp
 * @brief Subsystem: Field Weather Entity Object Administrator Evaluator
 */
/* 0x0031833c */ void FUN_00318284(void *this_ptr);

/**
 * @file gf_field_zone.cpp
 * @brief Subsystem: Field Zone Management System Evaluator
 * @note Dynamic validation block synchronized via Ghidra alignment
 */
/* 0x00318308 */ void FUN_00318308(void *this_ptr);

/**
 * @file gf_field_zone_script.cpp
 * @brief Subsystem: Field Zone Script Engine Evaluator
 */
/* 0x0031838c */ void FUN_0031838c(void *this_ptr);

/**
 * @file gf_field_zone_se.cpp
 * @brief Subsystem: Field Zone Dynamic Sound Effects Evaluator
 */
/* 0x00318414 */ void FUN_00318414(void *this_ptr);

/**
 * @file gf_fobj_manager.cpp
 * @brief Subsystem: Field Object (Fobj) Global Administrator Manager
 */
/* 0x00318498 */ void FUN_00318498(void *this_ptr);

/**
 * @address 0x002b3540
 * @brief Registra e inserta dinámicamente un descriptor de comportamiento en el pool activo de la cámara.
 */
bool gf_Camera_registerDescriptor(void* this_ptr, uint32_t descriptor_id, void* context);

// =========================================================================
// INFRAESTRUCTURA GLOBAL (Símbolos de bajo nivel de Monolith Soft)
// =========================================================================

/**
 * @address 0x0042cbbc
 * @brief Indexador matemático y desreferenciador de descriptores en el Pool de memoria.
 */
void* gf_Memory_getPoolBlock(uint32_t block_index);

/**
 * @address 0x0042d58c
 * @brief Operador sobrecargado global 'new[]' con inyección de telemetría de depuración.
 */
void* gf_Memory_allocNewDebug(uint64_t size, void* heap, int alignment, int line, const char* tag);

/**
 * @address 0x002aee80
 * @brief Interroga el Bitset global del sistema para validar si el índice de objeto sigue activo en memoria.
 */
bool gf_Object_isActiveIndex(uint32_t object_id);

/**
 * @address 0x001c53dc
 * @brief Formatea una cadena de texto utilizando un buffer intermedio seguro y argumentos variables (va_list).
 */
int gf_String_formatArgs(char* buffer, size_t max_len, const char* format, ...);

/**
 * @file Unknown Modules (Camera Related Math / Structure)
 * @note Pending source file identification via Ghidra XREFs
 */

/* 0x002b1b38 */ void *gf_Camera_findActiveEntry(void *p_cam_context, uint32_t target_cam_id);
/* 0x002c599c */
void FUN_002c599c(void *sub_structure);

/* 0x002c79ec */
void FUN_002c79ec(void **param_1);

#ifdef __cplusplus
}
#endif

#endif /* BF2_SYMBOLS_H */
