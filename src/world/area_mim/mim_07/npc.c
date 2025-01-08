#include "mim_07.h"

#include "world/common/enemy/BooBully.inc.c"

EvtScript N(EVS_BooBullyChestScene) = {
    WaitSecs(2)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
//     Call(SetNpcYaw, NPC_Oaklie, 180)
//     Call(SetNpcFlagBits, NPC_Oaklie, NPC_FLAG_INVISIBLE, FALSE)
//     Wait(15)
//     Call(SetNpcPos, NPC_Oaklie, GEN_CHEST_OAKLIE_X, -10, GEN_CHEST_OAKLIE_Z)
//    Thread
//         Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
//         Wait(15)
//         Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
//     EndThread
//     Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
//     Call(SetNpcJumpscale, NPC_Oaklie, Float(1.0))
//     Call(GetPlayerPos, LVar0, 0, LVar2)
//     Add(LVar0, 50)
//     Add(LVar2, 50)
//     Call(NpcJump0, NPC_Oaklie, LVar0, 33, LVar2, 20)
//     Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
//     Call(PlayerFaceNpc, NPC_Oaklie, 0)
//     Call(NpcFaceNpc, NPC_PARTNER, NPC_Oaklie, 0)
//     Wait(5)
//     Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Idle)
//     Wait(15)
//     Call(GetPlayerPos, LVar0, LVar1, LVar2)
//     Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
//     Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
//     Call(SetCamDistance, CAM_DEFAULT, 300)
//     Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
//     Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
//     Call(SpeakToNpc, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, NPC_Oaklie, MSG_FotB_001B)
//     Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_001C)
//     Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
//     Call(ShowEmote, NPC_Oaklie, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
//     Wait(25)
//     Call(NpcFacePlayer, NPC_Oaklie, 0)
//     Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_FotB_001D)
//     Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_Oaklie, MSG_FotB_001E)
//     Call(GetNpcYaw, NPC_Oaklie, LVar3)
//     Sub(LVar3, 180)
//     Call(InterpNpcYaw, NPC_Oaklie, LVar3, 12)
//     Wait(20)
//     WaitSecs(1)
//     Call(SpeakToNpc, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, NPC_Oaklie, MSG_FotB_001F)
//     Call(GetNpcYaw, NPC_Oaklie, LVar3)
//     Add(LVar3, 180)
//     Call(InterpNpcYaw, NPC_Oaklie, LVar3, 12)
//     Wait(20)
//     Call(GetNpcYaw, NPC_Oaklie, LVar3)
//     Sub(LVar3, 180)
//     Call(InterpNpcYaw, NPC_Oaklie, LVar3, 12)
//     Wait(20)
//     Call(SpeakToNpc, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, NPC_Oaklie, MSG_FotB_0020)
//     Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_0021)
//     Call(NpcFacePlayer, NPC_Oaklie, 0)
//     Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_FotB_0022)
//     Call(GetNpcYaw, NPC_Oaklie, LVar3)
//     Sub(LVar3, 180)
//     Call(InterpNpcYaw, NPC_Oaklie, LVar3, 12)
//     Wait(20)
//     Call(SpeakToNpc, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, NPC_Oaklie, MSG_FotB_0023)
//     Call(FadeOutMusic, 0, 1500)
//     Call(GotoMapSpecial, Ref("mim_03"), mim_03_ENTRY_5, TRANSITION_STANDARD)
//     Wait(100)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_BooBully) = {
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
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
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
