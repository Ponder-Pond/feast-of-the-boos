#include "../area.h"
#include "sprite/npc/Boo.h"

#define NAMESPACE A(boo_bully)

extern EvtScript N(EVS_Init);
extern s32 N(DefaultAnims)[];
extern s32 N(SeedAnims)[];
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Attack_Scare);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_SCARE       = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Boo_Idle,
    STATUS_KEY_STONE,     ANIM_Boo_Still,
    STATUS_KEY_SLEEP,     ANIM_Boo_Idle,
    STATUS_KEY_POISON,    ANIM_Boo_Idle,
    STATUS_KEY_STOP,      ANIM_Boo_Still,
    STATUS_KEY_STATIC,    ANIM_Boo_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Boo_Still,
    STATUS_KEY_DIZZY,     ANIM_Boo_Idle,
    STATUS_KEY_FEAR,      ANIM_Boo_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 10, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BOO_BULLY,
    .level = ACTOR_LEVEL_BOO_BULLY,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 95,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 100,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 28, 24 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};


EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_Boo_Idle)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Boo_Idle)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail) //BurnHurt
            SetConst(LVar2, ANIM_Boo_Flail) //BurnStill
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail) //BurnHurt
            SetConst(LVar2, ANIM_Boo_Flail) //BurnStill
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail) //BurnStill
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail) //Death
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)//Death
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)//Death
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Idle)//Move?
            SetConst(LVar2, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Idle)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Else
                    Call(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Boo_Flail)
            ExecWait(EVS_Enemy_BlowAway)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    ExecWait(N(EVS_Attack_Scare))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#define LBL_SKIP_DAMAGE 0
EvtScript N(EVS_Attack_Scare) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
	Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_VANISH_A)
	SetF(LVar0, 256)
	Loop(16)
		Sub(LVar0, 16)
		Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
		Wait(1)
	EndLoop
	Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Boo_Conceal) //Hide
	Wait(20)
	Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
	Call(SetGoalToTarget, ACTOR_SELF)
	Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
	Add(LVar0, 20)
	Set(LVar1, 0)
	Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
	Call(SetBattleCamDist, 350)
	Call(SetBattleCamOffsetY, 45)
	Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
	Call(MoveBattleCamOver, 20)
	Call(SetGoalToTarget, ACTOR_SELF)
	Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
	Add(LVar0, 25)
	Set(LVar1, 10)
	Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
	Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
	Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_COS_IN_OUT)
	Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_APPEAR_A)
	SetF(LVar0, 0)
	Loop(16)
		Add(LVar0, 16)
		Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
		Wait(1)
	EndLoop
	Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Boo_Spook)//Scare
	Wait(28)
	Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
	Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
			IfEq(LVar0, HIT_RESULT_LUCKY)
                Call(SetGoalToTarget, ACTOR_SELF)
				Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
			EndIf
			Goto(LBL_SKIP_DAMAGE)
		EndCaseGroup
	EndSwitch
	Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_SPOOK)
	Wait(5)
    Call(SetGoalToTarget, ACTOR_SELF)
	Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SCARE, BS_FLAGS1_TRIGGER_EVENTS) // 3 Damage
	Label(LBL_SKIP_DAMAGE)
	Wait(30)
	Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_VANISH_A)
	SetF(LVar0, 256)
	Loop(16)
		Sub(LVar0, 16)
		Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
		Wait(1)
	EndLoop
	Wait(10)
	Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
	Call(MoveBattleCamOver, 20)
	Call(SetGoalToHome, ACTOR_SELF)
	Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
	Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
	Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Boo_Idle)
	Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_APPEAR_A)
	SetF(LVar0, 0)
	Loop(16)
		Add(LVar0, 16)
		Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
		Wait(1)
	EndLoop
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
