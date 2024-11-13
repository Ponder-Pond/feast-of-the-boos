#include "area.h"

extern ActorBlueprint A(beehive);

extern Stage A(flo_01);

Vec3i A(BeehivePos) = { 90, 125, -68 };

// [BTL_POS_GROUND_A] { 5, 0, -20 },
// [BTL_POS_GROUND_B] { 45, 0, -5 },
// [BTL_POS_GROUND_C] { 85, 0, 10 },
// [BTL_POS_GROUND_D] { 125, 0, 25 },

Formation A(Formation_00) = {
    ACTOR_BY_POS(A(beehive), A(BeehivePos), 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(flo_01), "Flower Fields"),
    {},
};

StageList A(Stages) = {
    STAGE("flo_01", A(flo_01)),
    {},
};
