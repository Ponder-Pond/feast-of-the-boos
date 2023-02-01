#include "sbk_41.h"
#include "entity.h"

TweesterPath N(DefaultTweesterPath)[] = {
    { -65, 0, 217 },
    { -262, 0, -64 },
    { 57, 0, -286 },
    { 327, 0, 8 },
    { TWEESTER_PATH_LOOP }
};

TweesterPath* N(TweesterPaths)[] = {
    N(DefaultTweesterPath),
    PTR_LIST_END
};

EvtScript N(EVS_RideTweester) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("sbk_32"), sbk_32_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Tweester), 327, 0, 8, 0, EVT_PTR(N(TweesterPaths)), MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_RideTweester)))
    EVT_RETURN
    EVT_END
};
