#include "mim_07.h"

#include "world/common/enemy/BooBully.inc.c"

EvtScript N(EVS_BooBully_SpookPlayer) = {
    Call(SetPlayerAnimation, ANIM_MarioW2_Panic)
    Loop(5)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.5))
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_BooBullyChestScene) = {
    WaitSecs(2)
    SetF(LVar0, Float(0.0))
    Call(SetNpcImgFXParams, NPC_BooBully, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(PlayerFaceNpc, NPC_BooBully, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(GetNpcPos, NPC_BooBully, LVar0, LVar1, LVar2)
    Add(LVar1, 40)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Mario1_Question)
    WaitSecs(2)
    Call(GetNpcPos, NPC_BooBully, LVar0, LVar1, LVar2)
    Add(LVar1, 40)
    Call(SetNpcPos, NPC_BooBully, LVar0, LVar1, LVar2)
    Call(NpcFacePlayer, NPC_BooBully, 0)
    Call(SetNpcFlagBits, NPC_BooBully, NPC_FLAG_INVISIBLE, FALSE)
    Call(PlaySoundAtNpc, NPC_BooBully, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
    SetF(LVar0, Float(0.0))
    Loop(10)
        AddF(LVar0, Float(24.0))
        Call(SetNpcImgFXParams, NPC_BooBully, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_BooBully, ANIM_BooBully_Laugh)
    Call(PlaySoundAtNpc, NPC_BooBully, SOUND_BOO_SPOOK, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_BooBully_SpookPlayer))
    Call(SetNpcVar, NPC_BooBully, 0, 1)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_BooBully) = {
    // Exec(N(EVS_BooBullyChestScene))
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_BooBully) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_MIM07_DefeatedBooBully, TRUE)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_BooBully) = {
    IfEq(GF_MIM07_DefeatedBooBully, FALSE)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_BooBully)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_BooBully)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_BooBully) = {
    .id = NPC_BooBully,
    .pos = { -284, -10, 201 },
    .yaw = GEN_CHEST_FORMATION2_DIR,
    .init = &N(EVS_NpcInit_BooBully),
    .settings = &N(NpcSettings_BooBully),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BOO_BULLY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BooBully), BTL_FOB_FORMATION_01, BTL_FOB_STAGE_00),
    {}
};
