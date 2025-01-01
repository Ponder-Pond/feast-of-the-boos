#include "mim_03.h"

#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

#include "world/common/enemy/PiranhaPlant.inc.c"

#include "world/common/enemy/RedPanser.inc.c"

#include "world/common/npc/Oaklie.inc.c"

EvtScript N(EVS_Cutscene3) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcPos, NPC_DupiOaklie, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_DupiOaklie, NPC_FLAG_INVISIBLE, TRUE)
    // Call(GetPlayerPos, LVar0, LVar1, LVar2)
    // Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    // Call(SetCamDistance, CAM_DEFAULT, 250)
    // Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    // Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    // Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    // Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, Float(-275.0), Float(15.0), Float(-6.0))
    Call(func_802D1270, GEN_MARIO_CUTSCENE3_X, GEN_MARIO_CUTSCENE3_Z, Float(4.0))
    // Call(SetZoneEnabled, ZONE_north, FALSE)
    // Call(SetZoneEnabled, ZONE_stage, FALSE)
    Exec(N(EVS_UseGate_North))
    Wait(30)
    // Call(GetPlayerPos, LVar0, LVar1, LVar2)
    // Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, GEN_MARIO_CUTSCENE3_VEC)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(SetPanTarget, CAM_DEFAULT, GEN_MARIO_CUTSCENE3_VEC)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Set(LVar0, 116)
    Set(LVar2, -306)
    Call(func_802D1270, LVar0, LVar2, Float(4.0))
    Wait(15)
    Call(UseSettingsFrom, CAM_DEFAULT, GEN_CUTSCENE3_VEC)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(SetPanTarget, CAM_DEFAULT, GEN_CUTSCENE3_VEC)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(5)
    Call(DisablePartnerAI, 0)
    // Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    // Call(GetPlayerPos, LVar0, 0, LVar2)
    // Add(LVar0, 30)
    // Add(LVar2, 0)
    // Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Call(SetNpcFlagBits, NPC_DupiOaklie, NPC_FLAG_INVISIBLE, FALSE)
    Call(SetNpcPos, NPC_DupiOaklie, 185, 0, -280)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(5)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25)
    // Call(GetNpcYaw, NPC_PARTNER, LVar3)
    // Sub(LVar3, 180)
    // Call(InterpNpcYaw, NPC_PARTNER, LVar3, 12)
    // Wait(20)
    // Call(GetNpcYaw, NPC_PARTNER, LVar3)
    // Add(LVar3, 180)
    // Call(InterpNpcYaw, NPC_PARTNER, LVar3, 12)
    // Wait(20)
    // Call(InterpPlayerYaw, 180)
    // Wait(20)
    // Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_0005)
    // Wait(5)
    // Call(GetNpcYaw, NPC_PARTNER, LVar3)
    // Sub(LVar3, 180)
    // Call(InterpNpcYaw, NPC_PARTNER, LVar3, 12)
    // Wait(20)
    // Call(GetNpcYaw, NPC_PARTNER, LVar3)
    // Add(LVar3, 180)
    // Call(InterpNpcYaw, NPC_PARTNER, LVar3, 12)
    // Wait(20)
    // Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_0006)
    // Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    // Call(GetPlayerPos, LVar0, 0, LVar2)
    // Sub(LVar0, 30)
    // Sub(LVar2, 1)
    // Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    // Call(GetNpcYaw, NPC_PARTNER, LVar3)
    // Add(LVar3, 180)
    // Call(InterpNpcYaw, NPC_PARTNER, LVar3, 25)
    // Wait(10)
    Wait(30)
    // Call(SetZoneEnabled, ZONE_north, TRUE)
    // Call(SetZoneEnabled, ZONE_stage, TRUE)
    Call(ResetCam, CAM_DEFAULT, 3)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

NpcData N(NpcData_FreezyFuzzy) = {
    .id = NPC_FreezyFuzzy,
    .pos = { GEN_FREEZY_FUZZY_VEC },
    .yaw = GEN_FREEZY_FUZZY_DIR,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { GEN_FREEZY_FUZZY_VEC },
            .wanderSize = { 400 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { GEN_FREEZY_FUZZY_VEC },
            .detectSize = { 400 },
        }
    },
    .settings = &N(NpcSettings_FreezyFuzzy_Wander),
    .flags = 0,
    .drops = FREEZY_FUZZY_DROPS,
    .animations = FREEZY_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_RedPanser)[] = {
    {
        .id = NPC_RedPanser,
        .pos = { GEN_RED_PANSER_VEC },
        .yaw = GEN_RED_PANSER_DIR,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { GEN_RED_PANSER_VEC },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { GEN_RED_PANSER_VEC },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_RedPanser),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = RED_PANSER_DROPS,
        .animations = RED_PANSER_ANIMS,
    },
    RED_PANSER_FIREBALL_HITBOX(NPC_RedPanser_Fireball_1),
    RED_PANSER_FIREBALL_HITBOX(NPC_RedPanser_Fireball_2),
};

NpcData N(NpcData_PiranhaPlant)[] = {
    {
        .id = NPC_PiranhaPlant,
        .pos = { GEN_PIRANHA_PLANT_VEC },
        .yaw = GEN_PIRANHA_PLANT_DIR,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { GEN_PIRANHA_PLANT_VEC },
                .wanderSize = { 400 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { GEN_PIRANHA_PLANT_VEC },
                .detectSize = { 400 },
            }
        },
        .settings = &N(NpcSettings_PiranhaPlant),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = PIRANHA_PLANT_DROPS,
        .animations = PIRANHA_PLANT_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    PIRANHA_PLANT_HITBOX(NPC_PiranhaPlant_Hitbox)
};

NpcData N(NpcData_DupiOaklie) = {
    .id = NPC_DupiOaklie,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 180,
    // .init = &N(EVS_NpcInit_Oaklie),
    .settings = &N(NpcSettings_Oaklie),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = DUPI_OAKLIE_ANIMS,
    .tattle = MSG_NpcTattle_Oaklie,
};

EvtScript N(EVS_NpcInteract_Oaklie) = {
    Call(DisablePlayerInput, TRUE)
    // Switch(GB_StoryProgress)
    //     CaseLt(STORY_CH3_BOW_JOINED_PARTY)
    //         IfEq(AF_MIM03_Oaklie_DialogueToggle, FALSE)
    //             Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0009)
    //             Set(AF_MIM03_Oaklie_DialogueToggle, TRUE)
    //         Else
    //             Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000A)
    //             Set(AF_MIM03_Oaklie_DialogueToggle, FALSE)
    //         EndIf
    //     CaseLt(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
    //         IfEq(AF_MIM03_Oaklie_DialogueToggle, FALSE)
    //             Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000B)
    //             Set(AF_MIM03_Oaklie_DialogueToggle, TRUE)
    //         Else
    //             Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000C)
    //             Set(AF_MIM03_Oaklie_DialogueToggle, FALSE)
    //         EndIf
    //     CaseGe(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
    //         IfEq(AF_MIM03_Oaklie_DialogueToggle, FALSE)
    //             Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000D)
    //             Set(AF_MIM03_Oaklie_DialogueToggle, TRUE)
    //         Else
    //             Call(SpeakToPlayer, NPC_SELF, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_000E)
    //             Set(AF_MIM03_Oaklie_DialogueToggle, FALSE)
    //         EndIf
    // EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Oaklie) = {
    IfGe(GB_StoryProgress, STORY_MOD_CUTSCENE_7)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Oaklie)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

NpcData N(NpcData_Oaklie) = {
    .id = NPC_Oaklie,
    .pos = { GEN_OAKLIE_VEC },
    .yaw = GEN_OAKLIE_DIR,
    .init = &N(EVS_NpcInit_Oaklie),
    .settings = &N(NpcSettings_Oaklie),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = OAKLIE_ANIMS,
    .tattle = MSG_NpcTattle_Oaklie,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_FreezyFuzzy), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    // NPC_GROUP(N(NpcData_RedPanser), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_PiranhaPlant), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_DupiOaklie)),
    NPC_GROUP(N(NpcData_Oaklie)),
    {}
};
