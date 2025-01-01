#include "mim_08.h"

#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

#include "world/common/enemy/PiranhaPlant.inc.c"

#include "world/common/enemy/Beehive.inc.c"

#include "world/common/enemy/BooBully.inc.c"

#include "world/common/npc/Oaklie.inc.c"

EvtScript N(EVS_Cutscene2) = {
    Call(DisablePlayerInput, TRUE)
    Call(func_802D1270, GEN_MARIO_CUTSCENE2_X, GEN_MARIO_CUTSCENE2_Z, Float(4.0))
    Exec(N(EVS_UseGate_South))
    Wait(30)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Set(LVar0, -90)
    Set(LVar2, 307)
    Call(func_802D1270, LVar0, LVar2, Float(4.0))
    Wait(15)
    Call(DisablePartnerAI, 0)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Add(LVar0, 30)
    Add(LVar2, 0)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Wait(10)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Sub(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 12)
    Wait(20)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 12)
    Wait(20)
    Call(InterpPlayerYaw, 180)
    Wait(20)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_0005)
    Wait(5)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Sub(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 12)
    Wait(20)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 12)
    Wait(20)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_0006)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Sub(LVar0, 30)
    Sub(LVar2, 1)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 25)
    Wait(10)
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

EvtScript N(EVS_NpcIdle_Beehive) = {
    Label(100)
    Wait(1)
    IfEq(MV_ShakedTree, FALSE)
        Goto(100)
    EndIf
    Call(SetNpcPos, NPC_SELF, -280, 108, 0)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.0))
    Call(NpcJump1, NPC_SELF, -280, 50, 10, 5)
    Wait(50)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Beehive)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Beehive) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Beehive)))
    Return
    End
};

NpcData N(NpcData_Beehive) = {
    .id = NPC_Beehive,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = GEN_BEEHIVE_DIR,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -300, 60, 0 },
            .wanderSize = { 60 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -300, 60, 0 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Beehive),
    .settings = &N(NpcSettings_Beehive),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = BEEHIVE_ANIMS,
};

EvtScript N(EVS_NpcIdle_BooBully) = {
    Label(100)
    Wait(1)
    IfEq(MV_ShakedTree, FALSE)
        Goto(100)
    EndIf
    Call(SetNpcPos, NPC_SELF, -280, 108, 0)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.0))
    Call(NpcJump1, NPC_SELF, -280, 50, 10, 5)
    Wait(50)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_BooBully)))
    Return
    End
};

EvtScript N(EVS_NpcInit_BooBully) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_BooBully)))
    Return
    End
};

NpcData N(NpcData_BooBully) = {
    .id = NPC_BooBully,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = GEN_BOO_BULLY_DIR,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -300, 60, 0 },
            .wanderSize = { 60 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -300, 60, 0 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_BooBully),
    .settings = &N(NpcSettings_BooBully),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = BOO_BULLY_ANIMS,
};

EvtScript N(EVS_Scene_OaklieFreed) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Wait(40)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcPos, NPC_SELF, GEN_CHEST_OAKLIE_X, -10, GEN_CHEST_OAKLIE_Z)
    Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Call(NpcJump0, NPC_SELF, GEN_CHEST_OAKLIE_X, 0, 0, 20)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Wait(15)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    // Call(SetCamDistance, CAM_DEFAULT, 300)
    // Call(SetCamPosB, CAM_DEFAULT, 800, 245)
    // Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    // Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    // Call(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 5, MSG_CH3_00F6)
    // Wait(15)
    // Call(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 5, MSG_CH3_00F7)
    // Call(ShowChoice, MSG_Choice_000D)
    // IfEq(LVar0, 0)
    //     Call(ContinueSpeech, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00F8)
    // Else
    //     Call(ContinueSpeech, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00F9)
    // EndIf
    // Call(GetPlayerPos, LVar0, LVar1, LVar2)
    // Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    // Call(UseSettingsFrom, CAM_DEFAULT, 740, LVar1, LVar2)
    // Call(SetCamDistance, CAM_DEFAULT, 600)
    // Call(SetCamPosB, CAM_DEFAULT, 800, 245)
    // Call(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
    // Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    // Thread
    //     Set(MF_Sync_YakkeyDialogue, FALSE)
    //     Call(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 517, MSG_CH3_00FA)
    //     Set(MF_Sync_YakkeyDialogue, TRUE)
    // EndThread
    // Call(GetPlayerPos, LVar0, LVar1, LVar2)
    // Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    // Loop(0)
    //     Call(SetCamDistance, CAM_DEFAULT, Float(550.0))
    //     Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    //     Call(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
    //     Wait(1)
    //     Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
    //     Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    //     Call(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
    //     Wait(1)
    //     IfEq(MF_Sync_YakkeyDialogue, TRUE)
    //         BreakLoop
    //     EndIf
    // EndLoop
    // Call(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
    // Call(SetNpcVar, NPC_Tubba, 1, 1)
    // Wait(15)
    // Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim25)
    // Thread
    //     Loop(0)
    //         Call(GetNpcVar, NPC_Tubba, 1, LVar0)
    //         IfEq(LVar0, 2)
    //             BreakLoop
    //         EndIf
    //         Call(RandInt, 40, LVar0)
    //         Call(RandInt, 40, LVar1)
    //         Add(LVar0, 537)
    //         Add(LVar1, 110)
    //         PlayEffect(EFFECT_SMOKE_BURST, 2, LVar0, LVar1, 128, Float(0.3), 24)
    //         Wait(5)
    //     EndLoop
    // EndThread
    // Wait(15)
    // Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim05)
    // Call(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim13, ANIM_WorldTubba_Anim05, 5, MSG_CH3_00FB)
    // Wait(15)
    // Call(DisablePartnerAI, 0)
    // Call(GetCurrentPartnerID, LVar0)
    // Switch(LVar0)
    //     CaseEq(PARTNER_GOOMBARIO)
    //         Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH3_00FC)
    //     CaseEq(PARTNER_KOOPER)
    //         Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH3_00FD)
    //     CaseEq(PARTNER_BOMBETTE)
    //         Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH3_00FE)
    //     CaseEq(PARTNER_PARAKARRY)
    //         Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH3_00FF)
    //     CaseEq(PARTNER_BOW)
    //         Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_0100)
    // EndSwitch
    // Call(EnablePartnerAI)
    // Wait(15)
    // Call(BindNpcAI, NPC_Tubba, Ref(N(EVS_NpcAI_Tubba_WakeUp)))
    // Call(GetPlayerPos, LVar0, LVar1, LVar2)
    // Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    // Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    // Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    // Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    // Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    // Call(GetPlayerPos, LVar0, LVar1, LVar2)
    // Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    // Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    // Sub(LVar1, 10)
    // Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    // Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    // Set(GB_StoryProgress, STORY_CH3_TUBBA_WOKE_UP)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Oaklie) = {
    Call(SetSelfVar, 0, 0)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_OaklieFreed)))
    Return
    End
};

NpcData N(NpcData_Oaklie) = {
    .id = NPC_Oaklie,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = GEN_CHEST_OAKLIE_DIR,
    .init = &N(EVS_NpcInit_Oaklie),
    .settings = &N(NpcSettings_Oaklie),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = OAKLIE_ANIMS,
    .tattle = MSG_NpcTattle_Oaklie,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_FreezyFuzzy), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_PiranhaPlant), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_Beehive), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_BooBully), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_Oaklie)),
    {}
};
