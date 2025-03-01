#include "mim_08.h"

#include "../common/SetForeverForestFog.inc.c"

#include "../common/ManageSnowfall.inc.c"

s32 N(KeyList)[] = {
    ITEM_RUINS_KEY,
    ITEM_NONE
};

API_CALLABLE(N(GetPlayerDistFromMapCenter)) {
    script->varTable[0] = get_xz_dist_to_player(0.0f, 0.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_n) = EVT_EXIT_WALK(60, mim_08_ENTRY_0, "mim_03", mim_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_w) = EVT_EXIT_WALK(60, mim_08_ENTRY_1, "mim_07", mim_07_ENTRY_2);
EvtScript N(EVS_ExitWalk_s) = EVT_EXIT_WALK(60, mim_08_ENTRY_2, "mim_01", mim_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_e) = EVT_EXIT_WALK(60, mim_08_ENTRY_3, "mim_03", mim_03_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_n)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_w)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_s)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_e)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mim_08_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            IfLt(GB_StoryProgress, STORY_MOD_CUTSCENE_4)
                // Call(NpcFaceNpc, NPC_DupiOaklie, NPC_DupiOaklie, 0)
                Call(SetNpcYaw, NPC_DupiOaklie, 180)
                Call(SetNpcPos, NPC_DupiOaklie, 55, 33, 27)
                Call(SetNpcPos, NPC_Oaklie, GEN_CHEST_OAKLIE_X, -10, GEN_CHEST_OAKLIE_Z)
                Call(AwaitPlayerApproach, GEN_CUTSCENE4_X, GEN_CUTSCENE4_Z, 60)
                Exec(N(EVS_Cutscene4))
                Set(GB_StoryProgress, STORY_MOD_CUTSCENE_4)
            EndIf
        CaseEq(mim_08_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mim_08_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            IfLt(GB_StoryProgress, STORY_MOD_CUTSCENE_2)
                Exec(N(EVS_Cutscene2))
                Set(GB_StoryProgress, STORY_MOD_CUTSCENE_2)
            EndIf
        CaseEq(mim_08_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ShakeTree) = {
    Loop(6)
        Set(LVar0, 2)
        Call(TranslateModel, MODEL_o507, LVar0, 0, LVar0)
        Call(TranslateModel, MODEL_o508, LVar0, 0, LVar0)
        Wait(1)
        Set(LVar0, -2)
        Call(TranslateModel, MODEL_o507, LVar0, 0, LVar0)
        Call(TranslateModel, MODEL_o508, LVar0, 0, LVar0)
        Wait(1)
    EndLoop
    Set(LVar0, 0)
    Call(TranslateModel, MODEL_o507, LVar0, 0, LVar0)
    Call(TranslateModel, MODEL_o508, LVar0, 0, LVar0)
    Wait(1)
    Set(MV_ShakedTree, TRUE)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FOREVER_FOREST)
    Call(SetSpriteShading, SHADING_MIM_08)
    EVT_SETUP_CAMERA_MIM()
    Set(AB_MIM_2, GB_MIM_CurrentMapID)
    Call(GetMapID, GB_MIM_CurrentMapID)
    ExecWait(N(EVS_SetupGates))
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    BindPadlock(Ref(N(EVS_UnlockChest)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList)), 0, 1)
    ExecWait(N(EVS_MakeEntities))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o473, 1, 0)
    Call(N(SetForeverForestFog))
    Exec(N(EVS_ManageSnowfall))
    Thread
        Label(0)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(N(GetPlayerDistFromMapCenter))
        IfLt(LVar0, 350)
            Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Else
            Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
        EndIf
        Goto(0)
    EndThread
    Return
    End
};
