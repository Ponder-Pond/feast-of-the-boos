#include "mim_10.h"

EvtScript mim_10_EVS_ExitWalk_mac_02_1 = EVT_EXIT_WALK(60, mim_10_ENTRY_0, "mac_02", mac_02_ENTRY_1);

EvtScript mim_10_EVS_ExitWalk_mim_01_1 = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(UseExitHeading, 60, mim_10_ENTRY_1)
    Exec(ExitWalk)
    IfEq(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
        IfEq(GF_StartedChapter3, FALSE)
            Set(GF_StartedChapter3, TRUE)
            Call(FadeOutMusic, 0, 1500)
            Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_3, TRANSITION_BEGIN_OR_END_CHAPTER)
            Wait(100)
            Return
        EndIf
    EndIf
    Call(GotoMap, Ref("mim_01"), mim_01_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript mim_10_EVS_BindExitTriggers = {
    BindTrigger(Ref(mim_10_EVS_ExitWalk_mac_02_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(mim_10_EVS_ExitWalk_mim_01_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript mim_10_EVS_EnterMap = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(mim_10_EVS_BindExitTriggers)
        Return
    EndIf
    Set(LVar0, Ref(mim_10_EVS_BindExitTriggers))
    Exec(EnterWalk)
    Return
    End
};

EvtScript mim_10_EVS_Main = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT(0, 0, 0)
    Call(MakeNpcs, TRUE, Ref(mim_10_DefaultNPCs))
    Exec(mim_10_EVS_SetupBootlerTrigger)
    ExecWait(mim_10_EVS_MakeEntities)
    Exec(mim_10_EVS_SetupMusic)
    Exec(mim_10_EVS_EnterMap)
    Wait(1)
    Set(GF_MAC01_RowfBadgesChosen, FALSE)
    Return
    End
};

// EntryList mim_10_Entrances = {
//     [mim_10_ENTRY_0]    { -385.0,   20.0,   10.0,   90.0 },
//     [mim_10_ENTRY_1]    {  385.0,    0.0,   10.0,  270.0 },
// };

// MapSettings mim_10_settings = {
//     .main = &mim_10_EVS_Main,
//     .entryList = &mim_10_Entrances,
//     .entryCount = ENTRY_COUNT(mim_10_Entrances),
//     .background = &gBackgroundImage,
// };
