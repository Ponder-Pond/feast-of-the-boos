#include "mim_08.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"
#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_OpenChest_Oaklie) = {
    Call(DisablePlayerInput, TRUE)
    Set(GF_MIM08_Chest_Oaklie, TRUE)
    Set(GB_StoryProgress, STORY_MOD_CUTSCENE_6)
    Exec(N(EVS_Cutscene6))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UnlockChest) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    SuspendGroup(EVT_GROUP_FLAG_INTERACT)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ChestLockCollider, COLLIDER_FLAGS_UPPER_MASK)
    Call(RemoveItem, ITEM_RUINS_KEY)
    Call(CloseChoicePopup)
    Set(GF_MIM08_UnlockedChest, TRUE)
    Call(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_PadlockEntityID)
    Call(N(RemovePadlock))
    ResumeGroup(EVT_GROUP_FLAG_INTERACT)
    Unbind
    Return
    End
};

EvtScript N(EVS_OpenLockedChest) = {
    BindTrigger(Ref(N(EVS_OpenChest_Oaklie)), TRIGGER_WALL_PRESS_A, COLLIDER_ChestLockCollider, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_MAPLE_SYRUP, GEN_ITEM2_VEC, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MIM08_Item_MapleSyrup)
    IfEq(GF_MIM08_UnlockedChest, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), -74, 33, -25, 90, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OpenLockedChest)))
        Set(MV_PadlockEntityID, LVar0)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ChestLockCollider, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(MakeEntity, Ref(Entity_Chest), GEN_CHEST_OAKLIE_VEC, GEN_CHEST_OAKLIE_DIR, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_MIM08_Chest_Oaklie)
    Call(AssignScript, Ref(N(EVS_OpenChest_Oaklie)))
    Call(MakeEntity, Ref(Entity_HeartBlock), GEN_HP_BLOCK_VEC, GEN_HP_BLOCK_DIR, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SavePoint), GEN_SAVE_BLOCK_VEC, GEN_SAVE_BLOCK_DIR, MAKE_ENTITY_END)
    Return
    End
};
