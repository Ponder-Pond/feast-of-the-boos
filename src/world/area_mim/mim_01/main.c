#include "mim_01.h"

#include "../common/SetForeverForestFog.inc.c"

#include "../common/ManageSnowfall.inc.c"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_n) = EVT_EXIT_WALK(60, mim_01_ENTRY_0, "mim_08", mim_08_ENTRY_2);
EvtScript N(EVS_ExitWalk_w) = EVT_EXIT_WALK(60, mim_01_ENTRY_1, "mim_10", mim_10_ENTRY_1);
EvtScript N(EVS_ExitWalk_s) = EVT_EXIT_WALK(60, mim_01_ENTRY_2, "mim_07", mim_07_ENTRY_1);
EvtScript N(EVS_ExitWalk_e) = EVT_EXIT_WALK(60, mim_01_ENTRY_3, "mim_07", mim_07_ENTRY_0);

EvtScript N(EVS_GotoMap_mim_07_4) = {
    Call(GotoMap, Ref("mim_07"), mim_07_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_GotoMap_mim_03_4) = {
    Call(GotoMap, Ref("mim_03"), mim_03_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_mim_07_4) = EVT_EXIT_PIPE_VERTICAL(mim_01_ENTRY_4, COLLIDER_GreenPipeTop, N(EVS_GotoMap_mim_07_4));
EvtScript N(EVS_ExitPipe_mim_03_4) = EVT_EXIT_PIPE_VERTICAL(mim_01_ENTRY_5, COLLIDER_BluePipeTop, N(EVS_GotoMap_mim_03_4));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_n)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_w)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_s)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_e)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_mim_07_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_GreenPipeTop, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_mim_03_4)), TRIGGER_FLOOR_TOUCH, COLLIDER_BluePipeTop, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mim_01_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mim_01_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            IfLt(GB_StoryProgress, STORY_MOD_CUTSCENE_1)
                Exec(N(EVS_Cutscene1))
                Set(GB_StoryProgress, STORY_MOD_CUTSCENE_1)
            EndIf
        CaseEq(mim_01_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mim_01_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mim_01_ENTRY_4)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        CaseEq(mim_01_ENTRY_5)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FOREVER_FOREST)
    Call(SetSpriteShading, SHADING_MIM_01)
    EVT_SETUP_CAMERA_MIM()
    Set(GF_MAP_ForeverForest, TRUE)
    Set(AB_MIM_2, GB_MIM_CurrentMapID)
    Call(GetMapID, GB_MIM_CurrentMapID)
    ExecWait(N(EVS_SetupGates))
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupExitHint))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Call(N(SetForeverForestFog))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_ManageSnowfall))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Return
    End
};
