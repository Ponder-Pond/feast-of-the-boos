#include "area.h"

extern ActorBlueprint A(freezy_fuzzy);
extern ActorBlueprint A(pink_panser);
extern ActorBlueprint A(red_panser);
extern ActorBlueprint A(piranha_plant);
extern ActorBlueprint A(boo_bully);
extern ActorBlueprint A(frost_piranha);
extern ActorBlueprint A(crystal_cleft);
extern ActorBlueprint A(purple_panser);
extern ActorBlueprint A(spirit_bubble);
extern ActorBlueprint A(beehive);
extern ActorBlueprint A(duplighost);
extern ActorBlueprint A(jr_troopa_gang);

extern Stage A(fob_01);

Vec3i A(Beehive1Pos) = { 90, 125, -68 };
Vec3i A(Beehive2Pos) = { 120, 125, -68 };
Vec3i A(PiranhaPlantPos) = { 42, 25, 0 };
Vec3i A(BooBullyPosB) = { 45, 30, -5 };
Vec3i A(BooBullyPosC) = { 85, 30, 10 };

// [BTL_POS_GROUND_A] { 5, 0, -20 },
// [BTL_POS_GROUND_B] { 45, 0, -5 },
// [BTL_POS_GROUND_C] { 85, 0, 10 },
// [BTL_POS_GROUND_D] { 125, 0, 25 },

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(freezy_fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(freezy_fuzzy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_POS(A(boo_bully), A(BooBullyPosB), 10),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(freezy_fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(piranha_plant), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(piranha_plant), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(purple_panser), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(freezy_fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(freezy_fuzzy), BTL_POS_GROUND_C, 9),
    ACTOR_BY_IDX(A(purple_panser), BTL_POS_GROUND_D, 8),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(purple_panser), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(red_panser), BTL_POS_GROUND_C, 9),
    ACTOR_BY_IDX(A(purple_panser), BTL_POS_GROUND_D, 8),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(piranha_plant), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(piranha_plant), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_07) = {
    ACTOR_BY_POS(A(beehive), A(Beehive1Pos), 10),
    ACTOR_BY_POS(A(beehive), A(Beehive2Pos), 9),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 10),
    ACTOR_BY_POS(A(boo_bully), A(BooBullyPosC), 9),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(fob_01), "2 Freezy Fuzzies"),
    BATTLE(A(Formation_01), A(fob_01), "Boo Bully"),
    BATTLE(A(Formation_02), A(fob_01), "Freezy Fuzzy Piranha Plant"),
    BATTLE(A(Formation_03), A(fob_01), "Piranha Plant Purple Panser"),
    BATTLE(A(Formation_04), A(fob_01), "2 Freezy Fuzzies Purple Panser"),
    BATTLE(A(Formation_05), A(fob_01), "2 Purple Pansers Red Panser"),
    BATTLE(A(Formation_06), A(fob_01), "2 Piranha Plants"),
    BATTLE(A(Formation_07), A(fob_01), "2 Beehives"),
    BATTLE(A(Formation_08), A(fob_01), "Duplighost Boo Bully"),
    {},
};

StageList A(Stages) = {
    STAGE("fob_01", A(fob_01)),
    {},
};
