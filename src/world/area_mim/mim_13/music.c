#include "mim_13.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_POP_DIVA_SONG, 0, 8)
    Return
    End
};
