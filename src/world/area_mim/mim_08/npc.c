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

EvtScript N(EVS_BooBully_SpookPlayer) = {
    Loop(5)
        // Call(SetCamDistance, CAM_DEFAULT, 400)
        // Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        // Wait(1)
        // Call(SetCamDistance, CAM_DEFAULT, 450)
        // Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.5))
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBow_Flail)
    Wait(30)
    // Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Spook, ANIM_Bootler_Spook, 0, MSG_CH3_0002)
    // Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBow_Idle)
    // Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_Cutscene4) = {
    SetF(LVar0, Float(0.0))
    Call(NpcFacePlayer, NPC_BooBully_1, 0)
    Call(SetNpcImgFXParams, NPC_BooBully_1, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_BooBully_2, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
    Call(DisablePlayerInput, TRUE)
    Call(func_802D1270, 40, -30, Float(4.0))
    Wait(5)
    Call(DisablePartnerAI, 0)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Sub(LVar0, 20)
    Sub(LVar2, 20)
    Call(SetNpcSpeed, NPC_PARTNER, Float(4.0))
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 0, 0, EASING_LINEAR)
    Call(PlayerFaceNpc, NPC_DupiOaklie, 0)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_DupiOaklie, 0)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_000C)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_000D)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(20)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_000E)
    WaitSecs(1)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_000F)
    Call(NpcFacePlayer, NPC_DupiOaklie, 0)
    WaitSecs(3)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_0010)
    WaitSecs(1)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    // Sub(LVar0, 50)
    // Sub(LVar2, 50)
    Call(SetNpcPos, NPC_BooBully_1, 1, LVar1, -75)
    Call(PlaySoundAtNpc, NPC_BooBully_1, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
    Thread
        SetF(LVar0, Float(0.0))
        Loop(20)
            AddF(LVar0, Float(12.0))
            Call(SetNpcImgFXParams, NPC_BooBully_1, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
        EndLoop
    EndThread
    // Wait(25)
    Call(SetNpcAnimation, NPC_BooBully_1, ANIM_BooBully_Scare)
    Call(PlaySoundAtNpc, NPC_BooBully_1, SOUND_BOO_SPOOK, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_BooBully_SpookPlayer))
    Call(GetNpcPos, NPC_DupiOaklie, LVar2, LVar3, LVar4)
    Thread
        Add(LVar4, 15)
        Loop(8)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar2, LVar3, LVar4, 1, 1, 1, 1)
            Wait(5)
        EndLoop
    EndThread
    Call(PlaySoundAtNpc, NPC_DupiOaklie, SOUND_GHOST_TRANSFORM, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 1440, 20, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_DupiOaklie, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtNpc, NPC_DupiOaklie, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
    Call(SetNpcPos, NPC_DupiOaklie, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, NPC_DupiOaklie, FALSE)
    Call(SetNpcPos, NPC_Duplighost, LVar2, LVar3, LVar4)
    Call(SetNpcYaw, NPC_Duplighost, 0)
    Call(MakeLerp, -1440, 0, 20, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Duplighost, ANIM_Duplighost_Anim06)
    Wait(10)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Flail, ANIM_WorldBow_Flail, 0, NPC_PARTNER, MSG_FotB_0011)
    Call(GetNpcPos, NPC_BooBully_1, 0, LVar1, 0)
    Call(SetNpcPos, NPC_BooBully_2, 68, LVar1, -8)
    Call(NpcFacePlayer, NPC_BooBully_2, 0)
    Call(PlaySoundAtNpc, NPC_BooBully_2, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
    SetF(LVar0, Float(0.0))
    Loop(20)
        AddF(LVar0, Float(12.0))
        Call(SetNpcImgFXParams, NPC_BooBully_2, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SpeakToNpc, NPC_BooBully_2, ANIM_BooBully_Laugh, ANIM_BooBully_Laugh, 0, NPC_PARTNER, MSG_FotB_0012)
    Call(SetNpcAnimation, NPC_BooBully_1, ANIM_BooBully_Laugh)
    Call(SetNpcAnimation, NPC_BooBully_2, ANIM_BooBully_Laugh)
    Call(SetNpcVar, NPC_Duplighost, 0, 1)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BooBullyScareAndVanish) = {
    Call(SetNpcFlagBits, LVarA, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    Call(NpcFacePlayer, LVarA, 0)
    Wait(5)
    // Call(SetNpcAnimation, LVarA, ANIM_BooBully_Spook)
    Call(SetNpcAnimation, LVarA, ANIM_BooBully_Scare)
    Wait(57)
    Call(MakeLerp, 255, 0, 60, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(SetNpcPos, LVarA, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_Cutscene5) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerPos, GEN_CUTSCENE5_VEC)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Add(LVar0, 20)
    Add(LVar2, 20)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(DisablePartnerAI, 0)
    Call(GetNpcPos, NPC_BooBully_1, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_BooBully_1, -36, LVar1, -69)
    Call(GetNpcPos, NPC_BooBully_2, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_BooBully_2, -6, LVar1, -45)
    Call(SetNpcPos, NPC_Duplighost, 19, 33, -14)
    Call(PlayerFaceNpc, NPC_BooBully_2, 0)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_BooBully_2, 0)
    Call(NpcFacePlayer, NPC_Duplighost, 0)
    Call(SetNpcAnimation, NPC_BooBully_1, ANIM_BooBully_Flail)
    Call(SetNpcAnimation, NPC_BooBully_2, ANIM_BooBully_Flail)
    Call(SetNpcAnimation, NPC_Duplighost, ANIM_Duplighost_Anim0A)
    Call(SpeakToPlayer, NPC_BooBully_2, ANIM_BooBully_Flail, ANIM_BooBully_Flail, 0, MSG_FotB_0013)
    Call(SetNpcAnimation, NPC_BooBully_1, ANIM_BooBully_Idle)
    Call(SetNpcAnimation, NPC_BooBully_2, ANIM_BooBully_Idle)
    // Wait(1)
    Call(SpeakToPlayer, NPC_BooBully_2, ANIM_BooBully_Talk, ANIM_BooBully_Idle, 0, MSG_FotB_0014)
    // Wait(15)
    Call(PlaySoundAtNpc, NPC_BooBully_2, SOUND_BOO_SPOOK, SOUND_SPACE_DEFAULT)
    Set(LVarA, NPC_BooBully_2)
    Exec(N(EVS_BooBullyScareAndVanish))
    Call(PlaySoundAtNpc, NPC_BooBully_1, SOUND_BOO_SPOOK, SOUND_SPACE_DEFAULT)
    Set(LVarA, NPC_BooBully_1)
    Exec(N(EVS_BooBullyScareAndVanish))
    Call(PlaySoundAtNpc, NPC_BooBully_1, SOUND_BOO_VANISH_A, SOUND_SPACE_DEFAULT)
    WaitSecs(4)
    Wait(15)
    Call(SetNpcPos, NPC_BooBully_2, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_BooBully_1, NPC_DISPOSE_LOCATION)
    Call(GetNpcPos, NPC_Duplighost, LVar0, LVar1, LVar2)
    // Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
    Call(MakeItemEntity, ITEM_RUINS_KEY, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_MIM08_Item_ChestKey)
    Call(OnDefeatEnemy)
    // Call(RemoveNpc, NPC_Duplighost)
    Call(SetNpcPos, NPC_Duplighost, NPC_DISPOSE_LOCATION)
    Call(NpcFacePlayer, NPC_PARTNER, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_0015)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Flail, ANIM_WorldBow_Flail, 0, MSG_FotB_0016)
    Call(SetNpcFlagBits, NPC_Oaklie, NPC_FLAG_INVISIBLE, TRUE)
    Call(SetNpcPos, GEN_CHEST_OAKLIE_VEC)
    Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_FotB_0017)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_SpookLoop, ANIM_WorldBow_SpookLoop, 0, NPC_Oaklie, MSG_FotB_0018)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(25)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(20)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_0019)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBow_Laugh)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_001A)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Cutscene6) = {
    WaitSecs(2)
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcFlagBits, NPC_Oaklie, NPC_FLAG_INVISIBLE, FALSE)
    Wait(15)
    Call(SetNpcPos, NPC_Oaklie, GEN_CHEST_OAKLIE_X, -10, GEN_CHEST_OAKLIE_Z)
   Thread
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        Wait(15)
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EndThread
    Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_Oaklie, Float(1.0))
    Call(NpcJump0, NPC_Oaklie, GEN_CHEST_OAKLIE_X, 33, 0, 20)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    Wait(5)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Idle)
    Call(PlayerFaceNpc, NPC_Oaklie, FALSE)
    Wait(15)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
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
    Call(ResetCam, CAM_DEFAULT, 6)
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

EvtScript N(EVS_NpcIdle_BooBully_1) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_BooBully_1) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_BooBully_1)))
    Return
    End
};

NpcData N(NpcData_BooBully_1) = {
    .id = NPC_BooBully_1,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = GEN_BOO_BULLY_DIR,
    .init = &N(EVS_NpcInit_BooBully_1),
    .settings = &N(NpcSettings_BooBully),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BOO_BULLY_ANIMS,
};

EvtScript N(EVS_NpcIdle_BooBully_2) = {
    // Loop(0)
    //     Call(GetSelfVar, 0, LVar0)
    //     IfEq(LVar0, 1)
    //         BreakLoop
    //     EndIf
    //     Wait(1)
    // EndLoop
    // Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_BooBully_2) = {
    // Call(GetBattleOutcome, LVar0)
    // Switch(LVar0)
    //     CaseEq(OUTCOME_PLAYER_WON)
    //         IfLt(GB_StoryProgress, STORY_MOD_CUTSCENE_5)
    //             Exec(N(EVS_Cutscene5))
    //             Set(GB_StoryProgress, STORY_MOD_CUTSCENE_5)
    //         EndIf
    //     CaseEq(OUTCOME_PLAYER_LOST)
    //     CaseEq(OUTCOME_PLAYER_FLED)
    // EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_BooBully_2) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_BooBully_2)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_BooBully_2)))
    Return
    End
};

NpcData N(NpcData_BooBully_2) = {
    .id = NPC_BooBully_2,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = GEN_BOO_BULLY_DIR,
    .init = &N(EVS_NpcInit_BooBully_2),
    .settings = &N(NpcSettings_BooBully),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BOO_BULLY_ANIMS,
};

NpcSettings N(NpcSettings_Duplighost) = {
    .height = 30,
    .radius = 45,
    .level = ACTOR_LEVEL_NONE,
};

// EvtScript N(EVS_NpcAI_Duplighost_Flee) = {
//     Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
//     Add(LVar0, -130)
//     Loop(0)
//         Wait(1)
//         Call(GetPlayerPos, LVar1, LVar2, LVar3)
//         IfGe(LVar1, LVar0)
//             BreakLoop
//         EndIf
//     EndLoop
//     Call(DisablePlayerInput, TRUE)
//     Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
//     Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
//     Wait(20)
//     Call(InterpNpcYaw, NPC_SELF, 90, 5)
//     Call(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim04)
//     Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
//     Add(LVar0, 150)
//     Call(NpcMoveTo, NPC_SELF, LVar0, -30, 20)
//     Call(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim02)
//     Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
//     Call(DisablePlayerInput, FALSE)
//     Return
//     End
// };

// EvtScript N(EVS_NpcAI_Duplighost_Caught) = {
//     Call(DisablePlayerInput, TRUE)
//     Call(GetNpcPos, NPC_Follower, LVar2, LVar3, LVar4)
//     Thread
//         Add(LVar4, 15)
//         Loop(8)
//             PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar2, LVar3, LVar4, 1, 1, 1, 1)
//             Wait(5)
//         EndLoop
//     EndThread
//     Call(PlaySoundAtNpc, NPC_Follower, SOUND_GHOST_TRANSFORM, SOUND_SPACE_DEFAULT)
//     Call(MakeLerp, 0, 1440, 20, EASING_QUADRATIC_IN)
//     Loop(0)
//         Call(UpdateLerp)
//         Call(SetNpcRotation, NPC_Follower, 0, LVar0, 0)
//         Wait(1)
//         IfEq(LVar1, 0)
//             BreakLoop
//         EndIf
//     EndLoop
//     Call(PlaySoundAtNpc, NPC_Follower, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
//     Call(SetNpcPos, NPC_Guardian, NPC_DISPOSE_LOCATION)
//     Call(SetNpcPos, NPC_Follower, NPC_DISPOSE_LOCATION)
//     Call(EnableNpcShadow, NPC_Follower, FALSE)
//     Call(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
//     Call(SetNpcYaw, NPC_SELF, 270)
//     Call(MakeLerp, -1440, 0, 20, EASING_QUADRATIC_OUT)
//     Loop(0)
//         Call(UpdateLerp)
//         Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
//         Wait(1)
//         IfEq(LVar1, 0)
//             BreakLoop
//         EndIf
//     EndLoop
//     Wait(10)
//     Call(SpeakToPlayer, NPC_SELF, ANIM_Duplighost_Anim05, ANIM_Duplighost_Anim02, 0, MSG_CH8_002D)
//     Call(StartBossBattle, SONG_SPECIAL_BATTLE)
//     Call(GetPlayerPos, LVar0, LVar1, LVar2)
//     IfLt(LVar0, 700)
//         Add(LVar0, 30)
//         Call(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim04)
//         Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 35)
//     EndIf
//     Return
//     End
// };

EvtScript N(EVS_NpcIdle_Duplighost) = {
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

EvtScript N(EVS_NpcDefeat_Duplighost) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            IfLt(GB_StoryProgress, STORY_MOD_CUTSCENE_5)
                Set(GB_StoryProgress, STORY_MOD_CUTSCENE_5)
                ExecWait(N(EVS_Cutscene5))
                Call(RemoveNpc, NPC_BooBully_1)
                Call(RemoveNpc, NPC_BooBully_2)
                Call(RemoveNpc, NPC_Duplighost)
            EndIf
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Duplighost)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Duplighost)))
    Return
    End
};

NpcData N(NpcData_Imposter)[] = {
    {
        .id = NPC_DupiOaklie,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        // .init = &N(EVS_NpcInit_Guardian),
        .settings = &N(NpcSettings_Oaklie),
        .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPI_OAKLIE_ANIMS,
        .tattle = MSG_NpcTattle_KPA_FakePrincessPeach,
    },
    {
        .id = NPC_Duplighost,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Duplighost),
        .settings = &N(NpcSettings_Duplighost),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
    },
};

EvtScript N(EVS_NpcIdle_Oaklie) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    ExecWait(N(EVS_Cutscene6))
    Return
    End
};

EvtScript N(EVS_NpcInit_Oaklie) = {
    // Call(SetSelfVar, 0, 0)
    // Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Oaklie)))
    Return
    End
};

NpcData N(NpcData_Oaklie) = {
    .id = NPC_Oaklie,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = GEN_CHEST_OAKLIE_DIR,
    .init = &N(EVS_NpcInit_Oaklie),
    .settings = &N(NpcSettings_Oaklie),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = OAKLIE_ANIMS,
    .tattle = MSG_NpcTattle_Oaklie,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_FreezyFuzzy), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_PiranhaPlant), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_Beehive), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_BooBully_1)),
    NPC_GROUP(N(NpcData_BooBully_2)),
    NPC_GROUP(N(NpcData_Imposter), BTL_FOB_FORMATION_00, BTL_FOB_STAGE_00),
    NPC_GROUP(N(NpcData_Oaklie)),
    {}
};
