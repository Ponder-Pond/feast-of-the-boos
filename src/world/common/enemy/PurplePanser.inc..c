#include "PurplePanser.h"

#include "world/common/enemy/ai/PurplePanserAI.inc.c"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"

#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

EvtScript N(EVS_NpcDefeat_PurplePanser_Bit) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetSelfVar, 0, 5)
            Call(RemoveNpc, NPC_SELF)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(OnPlayerFled, 1)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, TRUE)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

MobileAISettings N(AISettings_PurplePanser) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 120.0f,
    .alertOffsetDist = 20.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 3,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 20.0f,
};

EvtScript N(EVS_NpcAI_PurplePanser) = {
    Call(SetSelfVar, 0, 70)
    Call(SetSelfVar, 1, 3)
    Call(SetSelfVar, 2, 3)
    Call(SetSelfVar, 3, 1)
    Call(N(PurplePanserAI_Main), Ref(N(AISettings_PurplePanser)))
    Return
    End
};

NpcSettings N(NpcSettings_PurplePanser) = {
    .height = 24,
    .radius = 28,
    .level = ACTOR_LEVEL_PURPLE_PANSER,
    .ai = &N(EVS_NpcAI_PurplePanser),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_08,
};

MobileAISettings N(AISettings_PurplePanser_Fireball) = {
    .moveSpeed = 5.4f,
    .alertRadius = 13.0f,
    .alertOffsetDist = 1.4f,
    .playerSearchInterval = -1,
};

EvtScript N(EVS_NpcAI_PurplePanser_Bit) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 0)
    Call(SetSelfVar, 2, 17)
    Call(SetSelfVar, 3, 17)
    Call(N(ProjectileAI_Main), Ref(N(AISettings_PurplePanser_Fireball)))
    Return
    End
};

EvtScript N(EVS_NoAI_PurplePanser_Bit) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_PurplePanser_Bit) = {
    Call(N(GetEncounterEnemyIsOwner))
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NoAI_PurplePanser_Bit)))
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_SPIN)
            Call(SetSelfVar, 0, 3)
            Call(N(ProjectileAI_Reflect))
            IfEq(LVar0, 0)
                Return
            EndIf
        EndCaseGroup
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(SetSelfVar, 0, 4)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(SetSelfVar, 0, 0)
        EndCaseGroup
        CaseDefault
            Call(SetBattleAsScripted)
        EndCaseGroup
    EndSwitch
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_PurplePanser_Bit)))
    Return
    End
};

NpcSettings N(NpcSettings_PurplePanser_Bit) = {
    .height = 12,
    .radius = 12,
    .ai = &N(EVS_NpcAI_PurplePanser_Bit),
    .onHit = &N(EVS_NpcHit_PurplePanser_Bit),
    .onDefeat = &N(EVS_NpcDefeat_PurplePanser_Bit),
    .actionFlags = AI_ACTION_08,
};

AnimID N(ExtraAnims_PurplePanser_Bit)[] = {
    ANIM_Panser_Purple_DiamondBit,
    ANIM_LIST_END
};
