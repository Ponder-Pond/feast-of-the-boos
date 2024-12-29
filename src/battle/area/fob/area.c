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

Vec3i A(BeehivePos) = { 90, 125, -68 };
Vec3i A(PiranhaPlantPos) = { 42, 25, 0 };
Vec3i A(BooBullyPos) = { 35, 30, -5 };

// [BTL_POS_GROUND_A] { 5, 0, -20 },
// [BTL_POS_GROUND_B] { 45, 0, -5 },
// [BTL_POS_GROUND_C] { 85, 0, 10 },
// [BTL_POS_GROUND_D] { 125, 0, 25 },

Formation A(Formation_00) = {
    // ACTOR_BY_IDX(A(freezy_fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_POS(A(boo_bully), A(BooBullyPos), 10),
    // ACTOR_BY_IDX(A(purple_panser), BTL_POS_GROUND_B, 10),
    // ACTOR_BY_POS(A(piranha_plant), A(PiranhaPlantPos), 10),
    // ACTOR_BY_IDX(A(boo_bully), BTL_POS_AIR_B, 10),
    // ACTOR_BY_POS(A(beehive), A(BeehivePos), 10),
    ACTOR_BY_IDX(A(frost_piranha), BTL_POS_GROUND_C, 9),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(fob_01), "Forever Forest"),
    {},
};

StageList A(Stages) = {
    STAGE("fob_01", A(fob_01)),
    {},
};
