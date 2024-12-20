#include "common.h"
#include "npc.h"

API_CALLABLE(N(SetForeverForestFog)) {
    enable_world_fog();
    set_world_fog_dist(950, 1010);
    set_world_fog_color(75, 120, 170, 255);
    enable_entity_fog();
    set_entity_fog_dist(950, 1010);
    set_entity_fog_color(75, 120, 170, 255);

    return ApiStatus_DONE2;
}
