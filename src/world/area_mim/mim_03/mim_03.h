/// @file mim_03.h
/// @brief Forever Forest - Flowers (Oaklie)

#include "common.h"
#include "generated.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_03_shape.h"
#include "mapfs/mim_03_hit.h"

#include "sprite/npc/WorldBow.h"
#include "sprite/npc/Oaklie.h"
#include "sprite/npc/Fuzzy.h"
#include "sprite/npc/Panser.h"
#include "sprite/npc/SmallPiranha.h"

enum {
    NPC_FreezyFuzzy             = 0,
    NPC_PiranhaPlant            = 1,
    NPC_PiranhaPlant_Hitbox     = 2,
    NPC_RedPanser               = 3,
    NPC_RedPanser_Fireball_1    = 4,
    NPC_RedPanser_Fireball_2    = 5,
    NPC_DupiOaklie              = 6,
    NPC_Oaklie                  = 7,
};

#define NAMESPACE mim_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupExitHint);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_UseGate_North);
extern EvtScript N(EVS_Cutscene3);
