#include "mim_03.h"

#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

#include "world/common/enemy/PiranhaPlant.inc.c"

#include "world/common/enemy/RedPanser.inc.c"

#include "world/common/npc/Oaklie.inc.c"

EvtScript N(EVS_Bow_SpookNpc) = {
    ChildThread
        Loop(0)
            Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.5))
            Wait(1)
        EndLoop
    EndChildThread
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_SpookLoop, ANIM_WorldBow_SpookLoop, 0, NPC_PARTNER, MSG_FotB_0009)
    Return
    End
};

EvtScript N(EVS_Cutscene3) = {
    Call(DisablePlayerInput, TRUE)
    Call(PlayerFaceNpc, NPC_DupiOaklie, TRUE)
    Call(func_802D1270, 110, -315, Float(4.0))
    Wait(5)
    Call(DisablePartnerAI, 0)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Sub(LVar0, 30)
    Call(SetNpcSpeed, NPC_PARTNER, Float(4.0))
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 0, 0, EASING_LINEAR)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_0007)
    WaitSecs(3)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(25)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_0008)
    Call(SetCamLeadPlayer, CAM_DEFAULT, TRUE)
    Wait(1)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetNpcPos, NPC_DupiOaklie, LVar0, 0, LVar2)
    Sub(LVar0, 40)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBow_SpookBegin)
    Wait(6)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBow_SpookLoop)
    Thread
        Call(SetNpcScale, NPC_PARTNER, Float(2.0), Float(2.0), Float(2.0))
    EndThread
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_BOW_SPOOK, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_Bow_SpookNpc))
    Call(SetNpcScale, NPC_PARTNER, Float(2.0), Float(2.0), Float(2.0))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.9), Float(1.9), Float(1.9))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.8), Float(1.8), Float(1.8))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.7), Float(1.7), Float(1.7))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.6), Float(1.6), Float(1.6))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.5), Float(1.5), Float(1.5))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.4), Float(1.4), Float(1.4))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.3), Float(1.3), Float(1.3))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.2), Float(1.2), Float(1.2))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.1), Float(1.1), Float(1.1))
    Wait(1)
    Call(SetNpcScale, NPC_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    Wait(1)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBow_Idle)
    WaitSecs(3)
   Thread
        Call(SetNpcAnimation, NPC_DupiOaklie, ANIM_Oaklie_Dupi_Jump)
        Wait(10)
        Call(SetNpcAnimation, NPC_DupiOaklie, ANIM_Oaklie_Dupi_Fall)
    EndThread
    Call(PlaySoundAtNpc, NPC_DupiOaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_DupiOaklie, LVar0, LVar1, LVar2)
    Add(LVar0, 120)
    Add(LVar1, 10)
    Call(NpcJump0, NPC_DupiOaklie, LVar0, LVar1, LVar2, 10)
    Call(SetNpcAnimation, NPC_DupiOaklie, ANIM_Oaklie_Dupi_Land)
    Call(SetNpcPos, NPC_DupiOaklie, NPC_DISPOSE_LOCATION)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Flail, ANIM_WorldBow_Flail, 0, NPC_PARTNER, MSG_FotB_000A)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 25)
    Wait(10)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_000B)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Sub(LVar0, 30)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 25)
    Wait(10)
    Call(ResetCam, CAM_DEFAULT, 6)
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
                .detectSize = { 180 },
            }
        },
        .settings = &N(NpcSettings_RedPanser),
        .flags = ENEMY_FLAG_FLYING,
        .drops = RED_PANSER_DROPS,
        .animations = RED_PANSER_ANIMS,
    },
    RED_PANSER_FIREBALL_HITBOX(NPC_RedPanser_Fireball),
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
    NPC_GROUP(N(NpcData_RedPanser), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_PiranhaPlant), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_DupiOaklie)),
    NPC_GROUP(N(NpcData_Oaklie)),
    {}
};
