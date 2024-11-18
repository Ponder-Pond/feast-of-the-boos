#include "area.h"

extern ActorBlueprint A(piranha_plant);
extern ActorBlueprint A(bzzap);
extern ActorBlueprint A(beehive);
extern ActorBlueprint A(panser);

extern Stage A(mim_01);

Vec3i A(BeehivePos) = { 90, 125, -68 };
Vec3i A(PiranhaPlantPos) = { 42, 25, 0 };

// [BTL_POS_GROUND_A] { 5, 0, -20 },
// [BTL_POS_GROUND_B] { 45, 0, -5 },
// [BTL_POS_GROUND_C] { 85, 0, 10 },
// [BTL_POS_GROUND_D] { 125, 0, 25 },

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(panser), BTL_POS_GROUND_B, 10),
    // ACTOR_BY_POS(A(piranha_plant), A(PiranhaPlantPos), 10),
    // ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 10),
    // ACTOR_BY_POS(A(beehive), A(BeehivePos), 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(mim_01), "Forever Forest"),
    {},
};

StageList A(Stages) = {
    STAGE("mim_01", A(mim_01)),
    {},
};
