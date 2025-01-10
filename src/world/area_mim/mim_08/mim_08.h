/// @file mim_08.h
/// @brief Forever Forest - Laughing Rock

#include "common.h"
#include "generated.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_08_shape.h"
#include "mapfs/mim_08_hit.h"

#include "sprite/player.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/Oaklie.h"
#include "sprite/npc/Duplighost.h"
#include "sprite/npc/BooBully.h"
#include "sprite/npc/Fuzzy.h"
#include "sprite/npc/SmallPiranha.h"
#include "sprite/npc/InsectsDK3.h"

enum {
    NPC_FreezyFuzzy,
    NPC_PiranhaPlant,
    NPC_PiranhaPlant_Hitbox,
    NPC_Beehive,
    NPC_Buzzbee,
    NPC_BooBully_1,
    NPC_BooBully_2,
    NPC_DupiOaklie,
    NPC_Duplighost,
    NPC_Oaklie,
};

enum {
    MV_ShakedTree                   = MapVar(0),
    MV_PadlockEntityID              = MapVar(1),
};

#define NAMESPACE mim_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_UnlockChest);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_DropShrinkStomp);
extern EvtScript N(EVS_UseGate_South);
extern EvtScript N(EVS_Cutscene2);
extern EvtScript N(EVS_Cutscene4);
extern EvtScript N(EVS_Cutscene5);
extern EvtScript N(EVS_Cutscene6);
