#include "mim_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), GEN_ITEM_BOX_ITEM3_VEC, GEN_ITEM_BOX_ITEM3_DIR, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_MIM03_ItemBlock_LifeShroom)
    Return
    End
};
