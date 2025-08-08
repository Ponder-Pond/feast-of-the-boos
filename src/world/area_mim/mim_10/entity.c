#include "mim_10.h"
#include "entity.h"

EvtScript mim_10_EVS_MakeEntities = {
    Call(MakeEntity, Ref(Entity_SavePoint), -175, 60, -50, 0, MAKE_ENTITY_END)
    Return
    End
};
