#include "RedPanser.h"

NpcSettings N(NpcSettings_RedPanser_Stationary) = {
    .height = 24,
    .radius = 28,
    .level = ACTOR_LEVEL_RED_PANSER,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
