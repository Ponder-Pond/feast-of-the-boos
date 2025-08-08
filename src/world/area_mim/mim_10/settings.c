#include "mim_10.h"

EntryList mim_10_Entrances = {
    [mim_10_ENTRY_0]    { -385.0,   20.0,   10.0,   90.0 },
    [mim_10_ENTRY_1]    {  385.0,    0.0,   10.0,  270.0 },
};

MapSettings mim_10_settings = {
    .main = &mim_10_EVS_Main,
    .entryList = &mim_10_Entrances,
    .entryCount = ENTRY_COUNT(mim_10_Entrances),
    .background = &gBackgroundImage,
};
