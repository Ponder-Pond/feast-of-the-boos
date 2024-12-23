#include "mim_01.h"

#include "world/common/enemy/PiranhaPlant.inc.c"

API_CALLABLE(NpcFaceAwayFromPlayer) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32* initialYaw = &script->functionTempF[1];
    f32* deltaYaw = &script->functionTempF[2];
    s32* turnTime = &script->functionTemp[3];
    Npc* npc;

    if (isInitialCall) {
        s32 npcID = evt_get_variable(script, *args++);

        npc = resolve_npc(script, npcID);
        if (npc == NULL) {
            return ApiStatus_DONE2;
        }

        *initialYaw = npc->yaw;

        // Use the game's custom atan2 implementation
        f32 targetYaw = atan2(
            npc->pos.x, npc->pos.z,          // NPC's position
            playerStatus->pos.x, playerStatus->pos.z // Player's position
        );
        targetYaw = clamp_angle(targetYaw + 180.0f); // Add 180 degrees to face away

        *deltaYaw = targetYaw - *initialYaw;

        script->functionTempPtr[0] = npc;
        *turnTime = evt_get_variable(script, *args++);
        npc->duration = 0;

        // Normalize deltaYaw to the shortest turn direction
        if (*deltaYaw < -180.0f) {
            *deltaYaw += 360.0f;
        }
        if (*deltaYaw > 180.0f) {
            *deltaYaw -= 360.0f;
        }
    }

    npc = script->functionTempPtr[0];
    if (*turnTime > 0) {
        npc->duration++;
        npc->yaw = *initialYaw + ((*deltaYaw * npc->duration) / *turnTime);
        npc->yaw = clamp_angle(npc->yaw);
        return !(npc->duration < *turnTime) * ApiStatus_DONE1;
    }

    npc->yaw = clamp_angle(*initialYaw + *deltaYaw);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Cutscene1) = {
    Call(AwaitPlayerApproach, GEN_CUTSCENE1_X, GEN_CUTSCENE1_Z, 250)
    Call(DisablePlayerInput, TRUE)
    Wait(10)

    Call(DisablePartnerAI, 0)
    // Call(SetNpcSpeed, NPC_PARTNER, Float(4.0))
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Add(LVar0, 60)
    Add(LVar2, 1)
    // Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(10)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Sub(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(10)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(10)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Sub(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 10)
    Wait(10)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(5)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PARTNER, MSG_FotB_0000)
    Wait(5)
    // Call(InterpNpcYaw, NPC_PARTNER, 90, 5)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_FotB_0001)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Laugh, ANIM_WorldBow_Laugh, 0, MSG_FotB_0002)
    Call(GetNpcPos, NPC_PARTNER, 0, LVar1, 0)
    Call(GetPlayerPos, LVar0, 0, LVar2)
    Sub(LVar0, 30)
    Add(LVar2, 1)
    // Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(NpcFlyTo, NPC_PARTNER, LVar0, LVar1, LVar2, 30, 0, EASING_LINEAR)
    Call(GetNpcYaw, NPC_PARTNER, LVar3)
    Add(LVar3, 180)
    Call(InterpNpcYaw, NPC_PARTNER, LVar3, 0)
    Wait(5)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

NpcData N(NpcData_PiranhaPlant)[] = {
    {
        .id = NPC_PiranhaPlant,
        .pos = { 135.0f, 0.0f, -300.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 135, 0, -300 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 400 },
            }
        },
        .settings = &N(NpcSettings_PiranhaPlant),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = PIRANHA_PLANT_DROPS,
        .animations = PIRANHA_PLANT_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    PIRANHA_PLANT_HITBOX(NPC_PiranhaPlant_Hitbox)
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PiranhaPlant), BTL_TST_FORMATION_00, BTL_TST_STAGE_00),
    {}
};
