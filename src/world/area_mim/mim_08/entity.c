#include "mim_08.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_Oaklie) = {
    Set(GF_MIM8_Chest_Oaklie, TRUE)
    Call(SetNpcVar, NPC_Oaklie, 0, 1)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    // Call(MakeEntity, Ref(Entity_RedBlock), 0, 93, 0, 45, ITEM_HP_PLUS_A, MAKE_ENTITY_END)
    // Call(AssignBlockFlag, GF_MIM08_BadgeBlock_HPPlusA)
    Call(MakeItemEntity, ITEM_MAPLE_SYRUP, GEN_ITEM2_VEC, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MIM08_Item_MapleSyrup)
    Call(MakeEntity, Ref(Entity_Chest), GEN_CHEST_OAKLIE_VEC, GEN_CHEST_OAKLIE_DIR, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_MIM8_Chest_Oaklie)
    Call(AssignScript, Ref(N(EVS_OpenChest_Oaklie)))
    Call(MakeEntity, Ref(Entity_HeartBlock), GEN_HP_BLOCK_VEC, GEN_HP_BLOCK_DIR, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SavePoint), GEN_SAVE_BLOCK_VEC, GEN_SAVE_BLOCK_DIR, MAKE_ENTITY_END)
    Return
    End
};
