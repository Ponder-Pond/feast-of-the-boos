#include "common.h"
#include "sprite/npc/Boo.h"

#define BOO_BULLY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 15, \
    .itemDrops = { \
        { ITEM_MAPLE_SYRUP, 6, 0 }, \
        { ITEM_HONEY_SYRUP, 4, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 4, \
}

#define BOO_BULLY_ANIMS \
{ \
    .idle   = ANIM_Boo_Idle, \
    .walk   = ANIM_Boo_Walk, \
    .run    = ANIM_Boo_Run, \
    .chase  = ANIM_Boo_Run, \
    .anim_4 = ANIM_Boo_Idle, \
    .anim_5 = ANIM_Boo_Idle, \
    .death  = ANIM_Boo_Flail, \
    .hit    = ANIM_Boo_Flail, \
    .anim_8 = ANIM_Boo_Run, \
    .anim_9 = ANIM_Boo_Run, \
    .anim_A = ANIM_Boo_Run, \
    .anim_B = ANIM_Boo_Run, \
    .anim_C = ANIM_Boo_Run, \
    .anim_D = ANIM_Boo_Run, \
    .anim_E = ANIM_Boo_Run, \
    .anim_F = ANIM_Boo_Run, \
}
