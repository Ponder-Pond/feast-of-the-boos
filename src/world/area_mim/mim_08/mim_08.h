/// @file mim_08.h
/// @brief Forever Forest - Laughing Rock

#include "common.h"
#include "generated.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_08_shape.h"
#include "mapfs/mim_08_hit.h"

#include "sprite/npc/Bzzap.h"
#include "sprite/npc/SmallPiranha.h"

enum {
    NPC_FreezyFuzzy                   = 0,
    NPC_PiranhaPlant                  = 1,
    NPC_PiranhaPlant_Hitbox           = 2,
    NPC_Beehive                       = 3,
    NPC_BooBully                      = 4,
    NPC_Oaklie                        = 5,
};

enum {
    MV_ShakedTree                   = MapVar(0),
};

#define NAMESPACE mim_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
