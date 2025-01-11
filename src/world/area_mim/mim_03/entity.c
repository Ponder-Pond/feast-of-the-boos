#include "mim_03.h"
#include "entity.h"

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

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), GEN_ITEM_BOX_ITEM3_VEC, GEN_ITEM_BOX_ITEM3_DIR, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_MIM03_ItemBlock_LifeShroom)
    BindTrigger(Ref(N(EVS_CheckBlockade)),  TRIGGER_WALL_PRESS_A, COLLIDER_Rock1Col, 1, 0)
    Return
    End
};
