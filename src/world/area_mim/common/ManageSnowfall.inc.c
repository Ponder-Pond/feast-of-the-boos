#include "common.h"
#include "../mim.h"
#include "effects.h"

EvtScript N(EVS_ManageSnowfall) = {
    Set(AF_MIM_Snowing, TRUE)
    Set(AF_MIM_LastSnowing, FALSE)
    Label(10)
        IfNe(AF_MIM_Snowing, AF_MIM_LastSnowing)
            IfEq(AF_MIM_Snowing, FALSE)
                Call(RemoveEffect, LVarF)
            Else
                PlayEffect(EFFECT_SNOWFALL, 0, 50)
            EndIf
            Set(AF_MIM_LastSnowing, AF_MIM_Snowing)
        EndIf
        Wait(1)
        Goto(10)
    Return
    End
};
