#include "mim_13.h"

EntryList N(Entrances) = {
    [mim_13_ENTRY_0]    {  GEN_ENTRY0_VEC, GEN_ENTRY0_DIR },
    [mim_13_ENTRY_1]    {  GEN_ENTRY1_VEC, GEN_ENTRY1_DIR },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};
