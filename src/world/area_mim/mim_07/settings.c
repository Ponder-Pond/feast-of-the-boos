#include "mim_07.h"

EntryList N(Entrances) = {
    [mim_07_ENTRY_0]    {    0.0,    0.0, -530.0,  180.0 },
    [mim_07_ENTRY_1]    { -530.0,    0.0,    0.0,   90.0 },
    [mim_07_ENTRY_2]    {    0.0,    0.0,  530.0,    0.0 },
    [mim_07_ENTRY_3]    {  530.0,    0.0,    0.0,  270.0 },
    [mim_07_ENTRY_4]    {  169, 35, 285,  GEN_GREEN_PIPE_DIR },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};
