#include "common.h"
#include "npc.h"
#include "sprite/npc/Panser.h"

// prerequisites
#include "world/common/enemy/ai/ProjectileHitbox.inc.c"

// ensure state handlers conform to expected signature
static AIStateHandler N(RedPanserAI_Init);
static AIStateHandler N(RedPanserAI_Wander);
static AIStateHandler N(RedPanserAI_PreSurface);
static AIStateHandler N(RedPanserAI_Surface);
static AIStateHandler N(RedPanserAI_DrawFireball);
static AIStateHandler N(RedPanserAI_ShootFireball);
static AIStateHandler N(RedPanserAI_PreBurrow);
static AIStateHandler N(RedPanserAI_Burrow);

enum AIStateRedPanser {
    AI_STATE_REDPANSER_INIT             = 0,    // choose random heading and duration for next state
    AI_STATE_REDPANSER_WANDER           = 1,    // wander around 'underground'
    AI_STATE_REDPANSER_PRE_SURFACE      = 12,   // delay before emerging from underground
    AI_STATE_REDPANSER_SURFACE          = 13,   // emerge from underground
    AI_STATE_REDPANSER_DRAW_FIREBALL    = 14,   // pull out a rock, can either attack or cancel
    AI_STATE_REDPANSER_FIRE_FIREBALL    = 15,   // throw the rock
    AI_STATE_REDPANSER_UNUSED           = 16,
    AI_STATE_REDPANSER_PRE_BURROW       = 20,   // delay before burrowing back underground
    AI_STATE_REDPANSER_BURROW           = 21,   // burrow underground
};

#define INTANGIBLE_RED_PANSER_NPC_FLAGS \
    ENEMY_FLAG_SKIP_BATTLE \
    | ENEMY_FLAG_IGNORE_TOUCH \
    | ENEMY_FLAG_IGNORE_JUMP \
    | ENEMY_FLAG_IGNORE_HAMMER \
    | ENEMY_FLAG_IGNORE_PARTNER \
    | ENEMY_FLAG_CANT_INTERACT

static s32 N(RedPanserAI_CanAttack)(Evt* script, EnemyDetectVolume* territory, f32 radius, f32 arg3) {
    Camera* cam;
    Enemy* enemy;
    Npc* npc;
    f32 angle;
    s32 retVal;

    enemy = script->owner1.enemy;
    npc = get_npc_unsafe(enemy->npcID);
    cam = &gCameras[gCurrentCamID];
    retVal = basic_ai_check_player_dist(territory, enemy, radius * 1.1, arg3, 0) != 0;
    // check npc facing angle for sight of player
    angle = 270.0f;
    if (clamp_angle(get_clamped_angle_diff(cam->curYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    }
    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z))) > 60.0) {
        retVal = FALSE;
    }
    // check for overlap with player
    if (get_xz_dist_to_player(npc->pos.x, npc->pos.z) < gPlayerStatusPtr->colliderDiameter + npc->collisionDiameter) {
        retVal = FALSE;
    }
    // check player elevation difference
    if (fabsf(npc->pos.y - gPlayerStatusPtr->pos.y) >= 40.0f) {
        retVal = FALSE;
    }
    // check for bow hiding
    if (gPartnerStatus.actingPartner == PARTNER_BOW) {
        retVal = FALSE;
    }
    return retVal;
}

static void N(RedPanserAI_Init)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->moveTime / 2) + rand_int((aiSettings->moveTime / 2) + 1);
    npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->flags |= INTANGIBLE_RED_PANSER_NPC_FLAGS;
    npc->flags |= NPC_FLAG_INVISIBLE;
    script->functionTemp[1] = 0;
    script->AI_TEMP_STATE = AI_STATE_REDPANSER_WANDER;
}

static void N(RedPanserAI_Wander)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Npc dummyNpc;
    f32 hitDepth;

    if (is_point_outside_territory(enemy->territory->wander.wanderShape,
            enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSize.x, enemy->territory->wander.wanderSize.z)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
    }
    dummyNpc.pos.x = npc->pos.x;
    dummyNpc.pos.y = npc->pos.y + 1.0f;
    dummyNpc.pos.z = npc->pos.z;
    npc_move_heading(&dummyNpc, npc->moveSpeed + npc->collisionDiameter, npc->yaw);
    hitDepth = 1000.0f;
    if (npc_raycast_down_sides(0, &dummyNpc.pos.x, &dummyNpc.pos.y, &dummyNpc.pos.z, &hitDepth) && (hitDepth < 5.0f)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
    if (npc->flags & NPC_FLAG_COLLDING_FORWARD_WITH_WORLD) {
        script->AI_TEMP_STATE = AI_STATE_REDPANSER_INIT;
    }
    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->playerSearchInterval;
            if (N(RedPanserAI_CanAttack)(script, territory, aiSettings->alertRadius, aiSettings->alertOffsetDist)) {
                npc->duration = 0;
                script->AI_TEMP_STATE = AI_STATE_REDPANSER_PRE_SURFACE;
                return;
            }
        }
        script->functionTemp[1]--;
    }
    if (!(npc->flags & (NPC_FLAG_FLYING | NPC_FLAG_GROUNDED))) {
        npc->homePos.x = npc->pos.x;
        npc->homePos.z = npc->pos.z;
    }
    npc->duration--;
    if (npc->duration == 0) {
        script->AI_TEMP_STATE = AI_STATE_REDPANSER_INIT;
    }
}

static void N(RedPanserAI_PreSurface)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->flags &= ~NPC_FLAG_INVISIBLE;
    ai_enemy_play_sound(npc, SOUND_BURROW_SURFACE, 0);
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
    npc->curAnim = ANIM_Panser_Red_Idle; // emerge from ground
    npc->duration = 10;
    script->AI_TEMP_STATE = AI_STATE_REDPANSER_SURFACE;
}

static void N(RedPanserAI_Surface)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 2) {
        enemy->flags &= ~(INTANGIBLE_RED_PANSER_NPC_FLAGS);
    }
    if (npc->duration <= 0) {
        npc->curAnim = ANIM_Panser_Red_Talk; // get and throw rock
        npc->duration = 10;
        script->AI_TEMP_STATE = AI_STATE_REDPANSER_DRAW_FIREBALL;
    }
}

static void N(RedPanserAI_DrawFireball)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* emoteOut;

    npc->duration--;
    if ((npc->duration) <= 0) {
        if (!N(RedPanserAI_CanAttack)(script, territory, aiSettings->alertRadius * 1.1, aiSettings->alertOffsetDist)) {
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteOut);
            npc->curAnim = ANIM_Panser_Red_Idle; // cancel attack
            npc->duration = 30;
            script->AI_TEMP_STATE =  AI_STATE_REDPANSER_PRE_BURROW;
        } else {
            npc->curAnim = ANIM_Panser_Red_Shot; // shoot fireball
            npc->duration = 125;
            script->AI_TEMP_STATE =  AI_STATE_REDPANSER_FIRE_FIREBALL;
        }
    }
}

static void N(RedPanserAI_ShootFireball)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* panserEnemy;
    Enemy* fireballEnemy;
    Npc* panserNpc;

    panserEnemy = script->owner1.enemy;
    panserNpc = get_npc_unsafe(panserEnemy->npcID);
    panserNpc->duration--;
    if (panserNpc->duration == 13) {
        fireballEnemy = get_enemy(panserEnemy->npcID + 1);
        fireballEnemy->varTable[4] = panserEnemy->npcID;
        fireballEnemy->varTable[0] = 1;
    }
    if (panserNpc->duration < 8) {
        if (dist2D(panserNpc->pos.x, panserNpc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z) > 100.0) {
            panserNpc->curAnim = ANIM_Panser_Red_Talk; // talk
        }
    }
    if (panserNpc->duration <= 0) {
        if (panserNpc->curAnim != ANIM_Panser_Red_Talk) {
            panserNpc->curAnim = ANIM_Panser_Red_Idle;
        }
        panserNpc->duration = 15;
        script->AI_TEMP_STATE = AI_STATE_REDPANSER_PRE_BURROW;
    }
}

static void N(RedPanserAI_PreBurrow)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        ai_enemy_play_sound(npc, SOUND_BURROW_DIG, 0);
        npc->duration = 11;
        npc->curAnim = ANIM_Panser_Red_Idle; // retreat into ground
        script->AI_TEMP_STATE = AI_STATE_REDPANSER_BURROW;
    }
}

static void N(RedPanserAI_Burrow)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 3) {
        enemy->flags |= INTANGIBLE_RED_PANSER_NPC_FLAGS;
    }
    if (npc->duration <= 0) {
        npc->flags |= NPC_FLAG_INVISIBLE;
        script->AI_TEMP_STATE = AI_STATE_REDPANSER_INIT;
    }
}

API_CALLABLE(N(RedPanserAI_Main)) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    if (isInitialCall) {
        script->AI_TEMP_STATE = AI_STATE_REDPANSER_INIT;
        npc->duration = 0;
        npc->flags &= ~NPC_FLAG_JUMPING;
        enemy->aiFlags |= (AI_FLAG_SKIP_EMOTE_AFTER_FLEE | AI_FLAG_SKIP_IDLE_ANIM_AFTER_FLEE);
    }

    if (enemy->aiFlags & AI_FLAG_SUSPEND) {
        if (enemy->aiSuspendTime != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~AI_FLAG_SUSPEND;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_REDPANSER_INIT:
            N(RedPanserAI_Init)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_REDPANSER_WANDER:
            N(RedPanserAI_Wander)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case AI_STATE_REDPANSER_PRE_SURFACE:
            N(RedPanserAI_PreSurface)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_REDPANSER_SURFACE:
            N(RedPanserAI_Surface)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_REDPANSER_DRAW_FIREBALL) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_REDPANSER_DRAW_FIREBALL:
            N(RedPanserAI_DrawFireball)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_REDPANSER_FIRE_FIREBALL) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_REDPANSER_FIRE_FIREBALL:
            N(RedPanserAI_ShootFireball)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_REDPANSER_UNUSED) {
                return ApiStatus_BLOCK;
            } // else fallthrough
        case AI_STATE_REDPANSER_PRE_BURROW:
            N(RedPanserAI_PreBurrow)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case AI_STATE_REDPANSER_BURROW:
            N(RedPanserAI_Burrow)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
    }
    return ApiStatus_BLOCK;
}
