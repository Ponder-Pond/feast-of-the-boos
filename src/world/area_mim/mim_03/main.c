#include "mim_03.h"

#include "../common/SetForeverForestFog.inc.c"

#include "../common/ManageSnowfall.inc.c"

#include "world/common/entity/Pipe.inc.c"

API_CALLABLE(N(GetPlayerDistFromMapCenter)) {
    script->varTable[0] = get_xz_dist_to_player(0.0f, 0.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_n) = EVT_EXIT_WALK(60, mim_03_ENTRY_0, "mim_08", mim_08_ENTRY_3);
EvtScript N(EVS_ExitWalk_w) = EVT_EXIT_WALK(60, mim_03_ENTRY_1, "mim_01", mim_01_ENTRY_2);
EvtScript N(EVS_ExitWalk_s) = EVT_EXIT_WALK(60, mim_03_ENTRY_2, "mim_08", mim_08_ENTRY_2);
EvtScript N(EVS_ExitWalk_e) = EVT_EXIT_WALK(60, mim_03_ENTRY_3, "mim_01", mim_01_ENTRY_1);

EvtScript N(EVS_GotoMap_mim_01_5) = {
    Call(GotoMap, Ref("mim_01"), mim_01_ENTRY_5)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_mim_01_5) = EVT_EXIT_PIPE_VERTICAL(mim_03_ENTRY_4, COLLIDER_BluePipeTop, N(EVS_GotoMap_mim_01_5));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_n)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_w)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_s)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_e)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_mim_01_5)), TRIGGER_FLOOR_TOUCH, COLLIDER_BluePipeTop, 1, 0)
    Return
    End
};

// EvtScript N(EVS_HideBluePipe) = {
//     IfEq(GF_MAC03_UnlockedPlayroom, FALSE)
//         Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_BluePipeBody, COLLIDER_FLAGS_UPPER_MASK)
//         Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_BluePipeTop, COLLIDER_FLAGS_UPPER_MASK)
//         Call(EnableModel, MODEL_BluePipe, FALSE)
//     EndIf
//     Return
//     End
// };

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mim_03_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            IfLt(GB_StoryProgress, STORY_MOD_CUTSCENE_3)
                Call(SetNpcPos, NPC_DupiOaklie, 185, 0, -280)
                Call(AwaitPlayerApproach, 110, -315, 60)
                Exec(N(EVS_Cutscene3))
                Set(GB_StoryProgress, STORY_MOD_CUTSCENE_3)
            EndIf
        CaseEq(mim_03_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mim_03_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mim_03_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mim_03_ENTRY_4)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        CaseEq(mim_03_ENTRY_5)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FOREVER_FOREST)
    Call(SetSpriteShading, SHADING_MIM_03)
    EVT_SETUP_CAMERA_MIM()
    Set(AB_MIM_2, GB_MIM_CurrentMapID)
    Call(GetMapID, GB_MIM_CurrentMapID)
    Set(AF_MIM03_Oaklie_DialogueToggle, FALSE)
    ExecWait(N(EVS_SetupGates))
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(SetZoneEnabled, ZONE_stagecutscene, FALSE)
    Call(SetZoneEnabled, ZONE_cutscene, FALSE)
    ExecWait(N(EVS_MakeEntities))
    // Exec(N(EVS_HideBluePipe))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_ManageSnowfall))
    ExecWait(N(EVS_SetupExitHint))
    Call(N(SetForeverForestFog))
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
