#include "../area.h"

#include "mapfs/mim_bt01_shape.h"
// #include "entity.h"
// #include "battle/common/stage/area_mim/mim_01.inc.c"


#define NAMESPACE A(mim_01)

API_CALLABLE(N(SetupFog)) {
    enable_world_fog();
    set_world_fog_dist(950, 1000);
    set_world_fog_color(16, 16, 16, 255);
    gCameras[CAM_BATTLE].bgColor[0] = 20;
    gCameras[CAM_BATTLE].bgColor[1] = 20;
    gCameras[CAM_BATTLE].bgColor[2] = 28;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(N(SetupFog))
    Call(TranslateModel, MODEL_Pipe0, 0, -40, 0)
    // Call(TranslateModel, MODEL_Pipe0, 0, -35, 0)
    // Wait(30)
    // Call(MakeLerp, -35, 0, 30, EASING_LINEAR)
    // Loop(0)
    //     Call(UpdateLerp)
    //     IfEq(LVarE, 8)
    //         Call(PlaySoundWithVolume, SOUND_GROW, 0)
    //     EndIf
    //     Call(TranslateModel, MODEL_Pipe0, 0, LVar0, 0)
    //     Wait(1)
    //     IfEq(LVar1, 0)
    //         BreakLoop
    //     EndIf
    // EndLoop
    // Call(TranslateModel, MODEL_Pipe0, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "mim_tex",
    .shape = "mim_bt01_shape",
    .hit = "mim_bt01_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
