#include "common.h"
#include "sprite/npc/Panser.h"

#define PURPLE_PANSER_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 5, 0 }, \
        { ITEM_MAPLE_SYRUP, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(4), \
    .flowerDrops = STANDARD_FLOWER_DROPS(3), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define PURPLE_PANSER_ANIMS \
{ \
    .idle   = ANIM_Panser_Purple_Idle, \
    .walk   = ANIM_Panser_Purple_Idle, \
    .run    = ANIM_Panser_Purple_Idle, \
    .chase  = ANIM_Panser_Purple_Idle, \
    .anim_4 = ANIM_Panser_Purple_Idle, \
    .anim_5 = ANIM_Panser_Purple_Idle, \
    .death  = ANIM_Panser_Purple_Hurt, \
    .hit    = ANIM_Panser_Purple_Hurt, \
    .anim_8 = ANIM_Panser_Purple_Idle, \
    .anim_9 = ANIM_Panser_Purple_Shot, \
    .anim_A = ANIM_Panser_Purple_Idle, \
    .anim_B = ANIM_Panser_Purple_Idle, \
    .anim_C = ANIM_Panser_Purple_Idle, \
    .anim_D = ANIM_Panser_Purple_Idle, \
    .anim_E = ANIM_Panser_Purple_Idle, \
    .anim_F = ANIM_Panser_Purple_Idle, \
}

#define PURPLE_PANSER_BIT_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_PurplePanser_Bit), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 90, \
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .territory = { \
        .wander = { \
            .isFlying = TRUE, \
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED, \
            .wanderShape = SHAPE_CYLINDER, \
            .centerPos  = { NPC_DISPOSE_LOCATION }, \
            .wanderSize = { 0 }, \
            .detectShape = SHAPE_CYLINDER, \
            .detectPos  = { NPC_DISPOSE_LOCATION }, \
            .detectSize = { 0 }, \
        } \
    }, \
    .animations = { \
        .idle   = ANIM_Panser_Purple_DiamondBit, \
        .walk   = ANIM_Panser_Purple_DiamondBit, \
        .run    = ANIM_Panser_Purple_DiamondBit, \
        .chase  = ANIM_Panser_Purple_DiamondBit, \
        .anim_4 = ANIM_Panser_Purple_DiamondBit, \
        .anim_5 = ANIM_Panser_Purple_DiamondBit, \
        .death  = ANIM_Panser_Purple_DiamondBit, \
        .hit    = ANIM_Panser_Purple_DiamondBit, \
        .anim_8 = ANIM_Panser_Purple_DiamondBit, \
        .anim_9 = ANIM_Panser_Purple_DiamondBit, \
        .anim_A = ANIM_Panser_Purple_DiamondBit, \
        .anim_B = ANIM_Panser_Purple_DiamondBit, \
        .anim_C = ANIM_Panser_Purple_DiamondBit, \
        .anim_D = ANIM_Panser_Purple_DiamondBit, \
        .anim_E = ANIM_Panser_Purple_DiamondBit, \
        .anim_F = ANIM_Panser_Purple_DiamondBit, \
    }, \
    .extraAnimations = N(ExtraAnims_PurplePanser_Bit), \
}
