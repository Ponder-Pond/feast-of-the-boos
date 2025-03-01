#include "mim_13.h"

#include "../common/ManageSnowfall.inc.c"

#include "world/common/entity/Pipe.inc.c"

API_CALLABLE(N(SetFogAndBackgroundColor)) {
    enable_world_fog();
    set_world_fog_dist(950, 1010);
    set_world_fog_color(75, 120, 170, 255);

    enable_entity_fog();
    set_entity_fog_dist(950, 1010); // Was 990, 1000
    set_entity_fog_color(75, 120, 170, 255); // Was 0, 0, 0

    gCameras[CAM_DEFAULT].bgColor[0] = 24;
    gCameras[CAM_DEFAULT].bgColor[1] = 24;
    gCameras[CAM_DEFAULT].bgColor[2] = 24;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_FocusCameraOnPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_EnterJumping) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, 323, 0, -240, 20)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Return
    End
};

EvtScript N(EVS_ExitFall_mim_11_6) = {
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar1, -30)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Wait(30)
    Call(GotoMap, Ref("mim_11"), mim_11_ENTRY_6)
    Wait(100)
    Call(DisablePlayerInput, FALSE)
    Call(DisablePlayerPhysics, FALSE)
    Return
    End
};


EvtScript N(EVS_ExitWalk_Cellar) = EVT_EXIT_WALK(60, mim_13_ENTRY_1, "mim_13", mim_13_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    Exec(N(EVS_ExitFall_mim_11_6))
    BindTrigger(Ref(N(EVS_ExitWalk_Cellar)), TRIGGER_FLOOR_ABOVE, COLLIDER_CellarStairs, 1, 0)
    Return
    End
};

// EvtScript N(EVS_EnterMap) = {
//     // Call(GetLoadType, LVar1)
//     // IfEq(LVar1, LOAD_FROM_FILE_SELECT)
//     //     Exec(EnterSavePoint)
//     //     Exec(N(EVS_BindExitTriggers))
//     //     Return
//     // EndIf
//     Set(LVar0, Ref(N(EVS_BindExitTriggers)))
//     Exec(EnterWalk)
//     Return
//     End
// };

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mim_13_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(N(EVS_EnterJumping))
        CaseEq(mim_13_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOOS_MANSION)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT(0, 0, 0)
    // Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(N(SetFogAndBackgroundColor))
    Exec(N(EVS_ManageMansionSnowfall))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
