
#include "mim_01.h"
#include "entity.h"

EvtScript N(EVS_ReadSign) = {
    Call(IsStartingConversation, LVar0)
    IfEq(LVar0, TRUE)
        Return
    EndIf
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_017E, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    End
};

EvtScript N(EVS_CheckBlockade) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_FotB_0004, 160, 40)
    Call(DisablePlayerInput, FALSE)
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Signpost), -300, 0, 0, 270, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign)))
    BindTrigger(Ref(N(EVS_CheckBlockade)),  TRIGGER_WALL_PRESS_A, COLLIDER_RightRockCol, 1, 0)
    BindTrigger(Ref(N(EVS_CheckBlockade)),  TRIGGER_WALL_PRESS_A, COLLIDER_LeftRockCol, 1, 0)
    Return
    End
};
