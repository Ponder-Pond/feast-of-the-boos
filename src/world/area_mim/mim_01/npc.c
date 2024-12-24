#include "mim_01.h"

// #include "world/common/enemy/PiranhaPlant.inc.c"

#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

EvtScript N(EVS_Cutscene1) = {
    Call(AwaitPlayerApproach, GEN_CUTSCENE1_X, GEN_CUTSCENE1_Z, 250)
    Call(DisablePlayerInput, TRUE)
    Wait(5)
    Call(DisablePartnerAI, 0)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Add(LVar0, 60)
    Add(LVar2, 1)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(5)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Sub(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(5)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(5)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Sub(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(5)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(5)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_0000)
    Wait(5)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(5)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_0001)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Laugh, ANIM_WorldBow_Laugh, 0, MSG_FotB_0002)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Sub(LVar0, 30)
    Add(LVar2, 1)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(5)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

// NpcData N(NpcData_PiranhaPlant)[] = {
//     {
//         .id = NPC_PiranhaPlant,
//         .pos = { 135.0f, 0.0f, -300.0f },
//         .yaw = 0,
//         .territory = {
//             .wander = {
//                 .isFlying = TRUE,
//                 .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
//                 .wanderShape = SHAPE_CYLINDER,
//                 .centerPos  = { 135, 0, -300 },
//                 .wanderSize = { 30 },
//                 .detectShape = SHAPE_CYLINDER,
//                 .detectPos  = { 0, 0, 0 },
//                 .detectSize = { 400 },
//             }
//         },
//         .settings = &N(NpcSettings_PiranhaPlant),
//         .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
//         .drops = PIRANHA_PLANT_DROPS,
//         .animations = PIRANHA_PLANT_ANIMS,
//         .aiDetectFlags = AI_DETECT_SIGHT,
//     },
//     PIRANHA_PLANT_HITBOX(NPC_PiranhaPlant_Hitbox)
// };

NpcData N(NpcData_FreezyFuzzy) = {
    .id = NPC_FreezyFuzzy,
    .pos = { GEN_FREEZY_FUZZY_VEC },
    .yaw = GEN_FREEZY_FUZZY_DIR,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 400 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 400 },
        }
    },
    .settings = &N(NpcSettings_FreezyFuzzy_Wander),
    .flags = 0,
    .drops = FREEZY_FUZZY_DROPS,
    .animations = FREEZY_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    // NPC_GROUP(N(NpcData_PiranhaPlant), BTL_TST_FORMATION_00, BTL_TST_STAGE_00),
    NPC_GROUP(N(NpcData_FreezyFuzzy), BTL_TST_FORMATION_00, BTL_TST_STAGE_00),
    {}
};
