#include "mim_07.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_CheckBlockade) = {
    IfLt(GB_StoryProgress, STORY_MOD_CUTSCENE_5)
        Call(DisablePlayerInput, TRUE)
        Call(ShowMessageAtScreenPos, MSG_FotB_0004, 160, 40)
        Call(DisablePlayerInput, FALSE)
    Else
        Call(DisablePlayerInput, TRUE)
        Call(ShowMessageAtScreenPos, MSG_FotB_0027, 160, 40)
        Call(DisablePlayerInput, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_OpenChest_BooBullyFormation) = {
    Call(DisablePlayerInput, TRUE)
    Set(GF_MIM07_Chest_BooBullyFormation, TRUE)
    Exec(N(EVS_BooBullyChestScene))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_OpenChest) = EVT_OPEN_CHEST(ITEM_SUPER_SHROOM, GF_MIM07_Chest_SuperShroom);


EvtScript N(EVS_ReadSign) = {
    Call(IsStartingConversation, LVar0)
    IfEq(LVar0, TRUE)
        Return
    EndIf
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_017F, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), GEN_CHEST_FORMATION2_VEC, GEN_CHEST_FORMATION2_DIR, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_MIM07_Chest_BooBullyFormation)
    Call(AssignScript, Ref(N(EVS_OpenChest_BooBullyFormation)))
    Call(MakeEntity, Ref(Entity_Chest), GEN_CHEST_ITEM1_VEC, GEN_CHEST_ITEM1_DIR, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_MIM07_Chest_SuperShroom)
    Call(AssignScript, Ref(N(EVS_OpenChest)))
    Call(MakeEntity, Ref(Entity_Signpost), 280, 0, 0, 90, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign)))
    BindTrigger(Ref(N(EVS_CheckBlockade)),  TRIGGER_WALL_PRESS_A, COLLIDER_Rock1Col, 1, 0)
    BindTrigger(Ref(N(EVS_CheckBlockade)),  TRIGGER_WALL_PRESS_A, COLLIDER_Rock2Col, 1, 0)
    Return
    End
};
