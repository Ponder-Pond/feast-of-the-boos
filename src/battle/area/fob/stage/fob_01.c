#include "../area.h"

#include "mapfs/mim_bt01_shape.h"
// #include "entity.h"
// #include "battle/common/stage/area_mim/mim_01.inc.c"


#define NAMESPACE A(fob_01)

#include "battle/common/stage/lib/Snowflakes.inc.c"

API_CALLABLE(N(SetupFog)) {
    enable_world_fog();
    set_world_fog_dist(950, 1010);
    set_world_fog_color(75, 120, 170, 255);
    gCameras[CAM_BATTLE].bgColor[0] = 60;
    gCameras[CAM_BATTLE].bgColor[1] = 70;
    gCameras[CAM_BATTLE].bgColor[2] = 90;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(N(SetupFog))
    Exec(N(EVS_SpawnSnowfall))
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
