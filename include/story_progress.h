#ifndef STORY_PROGRESS_START
#define STORY_PROGRESS_START(name, value) enum StoryProgress { \
    STORY_##name = value,
#define STORY_PROGRESS_VALUE(name) STORY_##name,
#define STORY_PROGRESS_END };
#endif

STORY_PROGRESS_START(INTRO, 0)


// Mod
STORY_PROGRESS_VALUE(MOD_INTRO)
STORY_PROGRESS_VALUE(MOD_CUTSCENE_1)
STORY_PROGRESS_VALUE(MOD_CUTSCENE_2)
STORY_PROGRESS_VALUE(MOD_CUTSCENE_3)
STORY_PROGRESS_VALUE(MOD_CUTSCENE_4)
STORY_PROGRESS_VALUE(MOD_CUTSCENE_5)
STORY_PROGRESS_VALUE(MOD_CUTSCENE_6)
STORY_PROGRESS_VALUE(MOD_CUTSCENE_7)


// Prologue
STORY_PROGRESS_VALUE(CH0_WAKE_UP)
STORY_PROGRESS_VALUE(CH0_MET_INNKEEPER)
STORY_PROGRESS_VALUE(UNUSED_FFFFFF83)
STORY_PROGRESS_VALUE(CH0_MET_GOOMPA )
STORY_PROGRESS_VALUE(CH0_GATE_CRUSHED)
STORY_PROGRESS_VALUE(CH0_FELL_OFF_CLIFF)
STORY_PROGRESS_VALUE(CH0_GOOMPA_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH0_LOOKING_FOR_HAMMER)
STORY_PROGRESS_VALUE(CH0_FOUND_HAMMER)
STORY_PROGRESS_VALUE(CH0_DEFEATED_JR_TROOPA)
STORY_PROGRESS_VALUE(CH0_LEFT_THE_PLAYGROUND)
STORY_PROGRESS_VALUE(UNUSED_FFFFFF8C)
STORY_PROGRESS_VALUE(CH0_GOOMBARIO_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH0_SMASHED_GATE_BLOCK)
STORY_PROGRESS_VALUE(CH0_DEFEATED_GOOMBA_BROS)
STORY_PROGRESS_VALUE(CH0_DEFEATED_GOOMBA_KING)
STORY_PROGRESS_VALUE(CH0_FOUND_GATEHOUSE_SWITCH)
STORY_PROGRESS_VALUE(CH0_HIT_GATEHOUSE_SWITCH)
STORY_PROGRESS_VALUE(CH0_OPENED_BRIDGE_TO_TOAD_TOWN)
STORY_PROGRESS_VALUE(CH0_KAMMY_RETURNED_TO_BOWSER)
STORY_PROGRESS_VALUE(CH0_ARRIVED_AT_TOAD_TOWN)
STORY_PROGRESS_VALUE(CH0_MET_STAR_SPIRITS)
STORY_PROGRESS_VALUE(CH0_BEGAN_PEACH_MISSION)
STORY_PROGRESS_VALUE(CH0_TWINK_GAVE_LUCKY_STAR)
STORY_PROGRESS_VALUE(CH0_RETURNED_TO_TOAD_TOWN)


// Chapter 1
STORY_PROGRESS_VALUE(CH1_SPOKE_WITH_MERLIN)
STORY_PROGRESS_VALUE(CH1_TOLD_MERLIN_ABOUT_DARK_TOADS)
STORY_PROGRESS_VALUE(CH1_MERLIN_REVEALED_KOOPA_BROS)
STORY_PROGRESS_VALUE(CH1_KNOCKED_SWITCH_FROM_TREE)
STORY_PROGRESS_VALUE(CH1_MADE_FIRST_BRIDGE)
STORY_PROGRESS_VALUE(CH1_ARRIVED_AT_KOOPA_VILLAGE)
STORY_PROGRESS_VALUE(CH1_PROMISED_TO_HELP_KOOPER)
STORY_PROGRESS_VALUE(CH1_FUZZY_THIEF_LEFT_TOWN)
STORY_PROGRESS_VALUE(CH1_FUZZY_THIEF_RAN_AWAY)
STORY_PROGRESS_VALUE(CH1_FUZZY_THIEF_HID_IN_TREE)
STORY_PROGRESS_VALUE(CH1_KOOPER_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH1_MADE_SECOND_BRIDGE)
STORY_PROGRESS_VALUE(CH1_ARRIVED_AT_KOOPA_FORTRESS)
STORY_PROGRESS_VALUE(CH1_SPOTTED_BY_KOOPA_BROS)
STORY_PROGRESS_VALUE(CH1_KOOPA_BROS_HID_KEY)
STORY_PROGRESS_VALUE(CH1_DEFEATED_BASEMENT_GUARD)
STORY_PROGRESS_VALUE(CH1_LOWERED_FIRST_STAIRS)
STORY_PROGRESS_VALUE(CH1_KOOPA_BROS_SET_TRAP)
STORY_PROGRESS_VALUE(CH1_MARIO_ACTIVATED_TRAP)
STORY_PROGRESS_VALUE(CH1_BOMBETTE_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH1_DEFEATED_DUNGEON_GUARDS)
STORY_PROGRESS_VALUE(CH1_LOWERED_SECOND_STAIRS)
STORY_PROGRESS_VALUE(CH1_RAISED_SUBMERGED_STAIRS)
STORY_PROGRESS_VALUE(CH1_KOOPA_BROS_FIRING_BLASTERS)
STORY_PROGRESS_VALUE(CH1_DEFEATED_KOOPA_BROS)
STORY_PROGRESS_VALUE(CH1_STAR_SPIRIT_RESCUED)
STORY_PROGRESS_VALUE(CH1_BEGAN_PEACH_MISSION)
STORY_PROGRESS_VALUE(CH1_STAR_SPRIT_DEPARTED)
STORY_PROGRESS_VALUE(CH1_DEFEATED_JR_TROOPA)
STORY_PROGRESS_VALUE(CH1_RETURNED_TO_TOAD_TOWN)


// Chapter 2
STORY_PROGRESS_VALUE(CH2_ARRIVED_AT_MT_RUGGED)
STORY_PROGRESS_VALUE(CH2_SPOKE_WITH_PARAKARRY)
STORY_PROGRESS_VALUE(CH2_PARAKARRY_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH2_ARRIVED_AT_DRY_DRY_DESERT)
STORY_PROGRESS_VALUE(CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
STORY_PROGRESS_VALUE(CH2_SHADY_MOUSE_LEFT_SHOP)
STORY_PROGRESS_VALUE(CH2_SPOKE_WITH_SHEEK)
STORY_PROGRESS_VALUE(CH2_SHADY_MOUSE_ENTERED_SHOP)
STORY_PROGRESS_VALUE(CH2_BOUGHT_SECRET_ITEMS)
STORY_PROGRESS_VALUE(CH2_GOT_PULSE_STONE)
STORY_PROGRESS_VALUE(CH2_UNCOVERED_DRY_DRY_RUINS)
STORY_PROGRESS_VALUE(CH2_DRAINED_FIRST_SAND_ROOM)
STORY_PROGRESS_VALUE(CH2_DRAINED_SECOND_SAND_ROOM)
STORY_PROGRESS_VALUE(CH2_GOT_SUPER_HAMMER)
STORY_PROGRESS_VALUE(CH2_DRAINED_THIRD_SAND_ROOM)
STORY_PROGRESS_VALUE(CH2_SOLVED_ARTIFACT_PUZZLE)
STORY_PROGRESS_VALUE(CH2_DEFEATED_TUTANKOOPA)
STORY_PROGRESS_VALUE(CH2_STAR_SPIRIT_RESCUED)
STORY_PROGRESS_VALUE(CH2_BEGAN_PEACH_MISSION)
STORY_PROGRESS_VALUE(CH2_STAR_SPRIT_DEPARTED)
STORY_PROGRESS_VALUE(UNUSED_FFFFFFCC)


// Chapter 3
STORY_PROGRESS_VALUE(CH3_SAW_BOO_ENTER_FOREST)
STORY_PROGRESS_VALUE(CH3_INVITED_TO_BOOS_MANSION)
STORY_PROGRESS_VALUE(CH3_ALLOWED_INTO_FOREVER_FOREST)
STORY_PROGRESS_VALUE(CH3_ARRIVED_AT_BOOS_MANSION)
STORY_PROGRESS_VALUE(CH3_OPENED_BOOS_MANSION_GATE)
STORY_PROGRESS_VALUE(CH3_ENTERED_BOOS_MANSION)
STORY_PROGRESS_VALUE(CH3_TRIGGERED_DOOR_JUMP_SCARE)
STORY_PROGRESS_VALUE(CH3_GOT_RECORD)
STORY_PROGRESS_VALUE(CH3_PLAYED_THE_RECORD)
STORY_PROGRESS_VALUE(CH3_GOT_WEIGHT)
STORY_PROGRESS_VALUE(CH3_WEIGHED_DOWN_CHANDELIER)
STORY_PROGRESS_VALUE(CH3_GOT_SUPER_BOOTS)
STORY_PROGRESS_VALUE(CH3_HIT_HUGE_BLUE_SWITCH)
STORY_PROGRESS_VALUE(CH3_GOT_BOO_PORTRAIT)
STORY_PROGRESS_VALUE(CH3_RESTORED_BOO_PORTRAIT)
STORY_PROGRESS_VALUE(CH3_BOW_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH3_UNLOCKED_GUSTY_GULCH)
STORY_PROGRESS_VALUE(CH3_ARRIVED_AT_GHOST_TOWN)
STORY_PROGRESS_VALUE(CH3_SAW_TUBBA_EAT_BOO)
STORY_PROGRESS_VALUE(CH3_ARRIVED_AT_TUBBAS_MANOR)
STORY_PROGRESS_VALUE(UNUSED_FFFFFFE1)
STORY_PROGRESS_VALUE(CH3_TUBBA_BEGAN_NAPPING)
STORY_PROGRESS_VALUE(CH3_TUBBA_WOKE_UP)
STORY_PROGRESS_VALUE(CH3_TUBBA_SMASHED_THE_BRIDGES)
STORY_PROGRESS_VALUE(CH3_TUBBA_CHASED_MARIO_IN_HALL)
STORY_PROGRESS_VALUE(CH3_TUBBA_CHASED_MARIO_IN_FOYER)
STORY_PROGRESS_VALUE(CH3_ESCAPED_TUBBAS_MANOR)
STORY_PROGRESS_VALUE(CH3_UNLOCKED_WINDY_MILL)
STORY_PROGRESS_VALUE(CH3_WENT_DOWN_THE_WELL)
STORY_PROGRESS_VALUE(CH3_HEART_FLED_FIRST_TUNNEL)
STORY_PROGRESS_VALUE(UNUSED_FFFFFFEB)
STORY_PROGRESS_VALUE(UNUSED_FFFFFFEC)
STORY_PROGRESS_VALUE(CH3_HEART_FLED_SECOND_TUNNEL)
STORY_PROGRESS_VALUE(CH3_HEART_ESCAPED_WELL)
STORY_PROGRESS_VALUE(CH3_HEART_ESCAPED_WINDY_MILL)
STORY_PROGRESS_VALUE(CH3_DEFEATED_TUBBA_BLUBBA)
STORY_PROGRESS_VALUE(CH3_STAR_SPIRIT_RESCUED)
STORY_PROGRESS_VALUE(CH3_BEGAN_PEACH_MISSION)
STORY_PROGRESS_VALUE(CH3_STAR_SPRIT_DEPARTED)


// Chapter 4
STORY_PROGRESS_VALUE(CH4_FRYING_PAN_STOLEN)
STORY_PROGRESS_VALUE(CH4_MET_WITH_TWINK)
STORY_PROGRESS_VALUE(CH4_FOUND_HIDDEN_DOOR)
STORY_PROGRESS_VALUE(CH4_ENTERED_THE_TOY_BOX)
STORY_PROGRESS_VALUE(CH4_GOT_STOREROOM_KEY)
STORY_PROGRESS_VALUE(CH4_RETURNED_STOREROOM_KEY)
STORY_PROGRESS_VALUE(CH4_GOT_TOY_TRAIN)
STORY_PROGRESS_VALUE(CH4_RETURNED_TOY_TRAIN)
STORY_PROGRESS_VALUE(CH4_GOT_FRYING_PAN)
STORY_PROGRESS_VALUE(CH4_GOT_TAYCE_TS_CAKE)
STORY_PROGRESS_VALUE(CH4_GAVE_CAKE_TO_GOURMET_GUY)
STORY_PROGRESS_VALUE(CH4_PULLED_SWITCH_SWITCH)
STORY_PROGRESS_VALUE(CH4_SOLVED_COLOR_PUZZLE)
STORY_PROGRESS_VALUE(CH4_DEFEATED_LANTERN_GHOST)
STORY_PROGRESS_VALUE(CH4_WATT_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH4_OPENED_GENERAL_GUY_ROOM)
STORY_PROGRESS_VALUE(CH4_DEFEATED_GENERAL_GUY)
STORY_PROGRESS_VALUE(CH4_STAR_SPIRIT_RESCUED)
STORY_PROGRESS_VALUE(CH4_BEGAN_PEACH_MISSION)
STORY_PROGRESS_VALUE(CH4_STAR_SPRIT_DEPARTED)


// Chapter 5
STORY_PROGRESS_VALUE(CH5_WHALE_MOUTH_OPEN)
STORY_PROGRESS_VALUE(CH5_ENTERED_WHALE)
STORY_PROGRESS_VALUE(CH5_DEFEATED_FUZZIPEDE)
STORY_PROGRESS_VALUE(CH5_REACHED_LAVA_LAVA_ISLAND)
STORY_PROGRESS_VALUE(CH5_KOLORADO_ESCAPED_FUZZIES)
STORY_PROGRESS_VALUE(CH5_KOLORADO_ESCAPED_SPEAR_GUYS)
STORY_PROGRESS_VALUE(CH5_YOSHI_CHILDREN_ARE_MISSING)
STORY_PROGRESS_VALUE(CH5_SUSHIE_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH5_ALL_YOSHI_CHILDREN_RESCUED)
STORY_PROGRESS_VALUE(CH5_GOT_JADE_RAVEN)
STORY_PROGRESS_VALUE(CH5_MOVED_RAVEN_STATUE)
STORY_PROGRESS_VALUE(CH5_DEFEATED_PIRANHAS_MINIBOSS)
STORY_PROGRESS_VALUE(CH5_REACHED_RAPHAELS_TREE)
STORY_PROGRESS_VALUE(CH5_RAPHAEL_LEFT_NEST)
STORY_PROGRESS_VALUE(CH5_RAPHAEL_MOVED_ROOT)
STORY_PROGRESS_VALUE(CH5_RAPHAEL_WAITING_FOR_MARIO)
STORY_PROGRESS_VALUE(CH5_ZIP_LINE_READY)
STORY_PROGRESS_VALUE(CH5_ENTERED_MT_LAVA_LAVA)
STORY_PROGRESS_VALUE(CH5_KOLORADO_FELL_IN_LAVA)
STORY_PROGRESS_VALUE(CH5_LAVA_STREAM_BLOCKED)
STORY_PROGRESS_VALUE(CH5_GOT_ULTRA_HAMMER)
STORY_PROGRESS_VALUE(CH5_SMASHED_ULTRA_BLOCK)
STORY_PROGRESS_VALUE(CH5_KOLORADO_FELL_IN_PIT)
STORY_PROGRESS_VALUE(CH5_KOLORADO_AT_DEAD_END)
STORY_PROGRESS_VALUE(CH5_HIDDEN_PASSAGE_OPEN)
STORY_PROGRESS_VALUE(CH5_KOLORADO_RAN_AHEAD)
STORY_PROGRESS_VALUE(CH5_KOLORADO_IN_TREASURE_ROOM)
STORY_PROGRESS_VALUE(CH5_DEFEATED_LAVA_PIRANHA)
STORY_PROGRESS_VALUE(CH5_MT_LAVA_LAVA_ERUPTING)
STORY_PROGRESS_VALUE(CH5_OPENED_ESCAPE_ROUTE)
STORY_PROGRESS_VALUE(CH5_BEGAN_PEACH_MISSION)
STORY_PROGRESS_VALUE(CH5_STAR_SPRIT_DEPARTED)
STORY_PROGRESS_VALUE(CH5_TRADED_VASE_FOR_SEED)
STORY_PROGRESS_VALUE(CH5_RETURNED_TO_TOAD_TOWN)


// Chapter 6
STORY_PROGRESS_VALUE(CH6_FLOWER_GATE_OPEN)
STORY_PROGRESS_VALUE(CH6_ARRIVED_AT_FLOWER_FIELDS)
STORY_PROGRESS_VALUE(CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
STORY_PROGRESS_VALUE(CH6_GOT_MAGICAL_BEAN)
STORY_PROGRESS_VALUE(CH6_GOT_FERTILE_SOIL)
STORY_PROGRESS_VALUE(CH6_GOT_CRYSTAL_BERRY)
STORY_PROGRESS_VALUE(CH6_GOT_WATER_STONE)
STORY_PROGRESS_VALUE(CH6_FILLED_SPRING_WITH_WATER)
STORY_PROGRESS_VALUE(CH6_SPOKE_WITH_THE_SUN)
STORY_PROGRESS_VALUE(CH6_LAKILESTER_JOINED_PARTY)
STORY_PROGRESS_VALUE(CH6_DEFEATED_PUFF_PUFF_GUARDS)
STORY_PROGRESS_VALUE(CH6_DESTROYED_PUFF_PUFF_MACHINE)
STORY_PROGRESS_VALUE(CH6_WISTERWOOD_GAVE_HINT)
STORY_PROGRESS_VALUE(CH6_GREW_MAGIC_BEANSTALK)
STORY_PROGRESS_VALUE(CH6_DEFEATED_HUFF_N_PUFF)
STORY_PROGRESS_VALUE(CH6_STAR_SPIRIT_RESCUED)
STORY_PROGRESS_VALUE(CH6_BEGAN_PEACH_MISSION)
STORY_PROGRESS_VALUE(CH6_STAR_SPRIT_DEPARTED)
STORY_PROGRESS_VALUE(CH6_RETURNED_TO_TOAD_TOWN)


// Chapter 7
STORY_PROGRESS_VALUE(CH7_INVITED_TO_STARBORN_VALLEY)
STORY_PROGRESS_VALUE(CH7_ARRIVED_AT_SHIVER_CITY)
STORY_PROGRESS_VALUE(CH7_MAYOR_MURDER_MYSTERY)
STORY_PROGRESS_VALUE(CH7_SHATTERED_FROZEN_POND)
STORY_PROGRESS_VALUE(CH7_SPOKE_WITH_HERRINGWAY)
STORY_PROGRESS_VALUE(CH7_HERRINGWAY_AT_MAYORS_HOUSE)
STORY_PROGRESS_VALUE(CH7_MAYOR_MURDER_SOLVED)
STORY_PROGRESS_VALUE(CH7_DEFEATED_JR_TROOPA)
STORY_PROGRESS_VALUE(CH7_DEFEATED_MONSTAR)
STORY_PROGRESS_VALUE(CH7_ARRIVED_AT_STARBORN_VALLEY)
STORY_PROGRESS_VALUE(CH7_MERLE_APOLOGIZED)
STORY_PROGRESS_VALUE(CH7_GOT_SNOWMAN_SCARF)
STORY_PROGRESS_VALUE(CH7_GOT_SNOWMAN_BUCKET)
STORY_PROGRESS_VALUE(CH7_UNLOCKED_SHIVER_MOUNTAIN)
STORY_PROGRESS_VALUE(CH7_DEFEATED_FIRST_DUPLIGHOST)
STORY_PROGRESS_VALUE(CH7_GOT_STAR_STONE)
STORY_PROGRESS_VALUE(CH7_RAISED_FROZEN_STAIRS)
STORY_PROGRESS_VALUE(CH7_ARRIVED_AT_CRYSTAL_PALACE)
STORY_PROGRESS_VALUE(CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
STORY_PROGRESS_VALUE(CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
STORY_PROGRESS_VALUE(CH7_DEFEATED_CLUBBAS)
STORY_PROGRESS_VALUE(CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
STORY_PROGRESS_VALUE(CH7_EXTENDED_PALACE_BRIDGE)
STORY_PROGRESS_VALUE(CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
STORY_PROGRESS_VALUE(CH7_SOLVED_ALBINO_DINO_PUZZLE)
STORY_PROGRESS_VALUE(CH7_DEFEATED_CRYSTAL_KING)
STORY_PROGRESS_VALUE(CH7_STAR_SPIRIT_RESCUED)
STORY_PROGRESS_VALUE(CH7_BEGAN_PEACH_MISSION)
STORY_PROGRESS_VALUE(CH7_STAR_SPRIT_DEPARTED)


// Chapter 8
STORY_PROGRESS_VALUE(CH8_OPENED_PATH_TO_STAR_WAY)
STORY_PROGRESS_VALUE(CH8_REACHED_STAR_HAVEN)
STORY_PROGRESS_VALUE(CH8_STAR_SHIP_ACTIVATED)
STORY_PROGRESS_VALUE(UNUSED_0000005D)
STORY_PROGRESS_VALUE(CH8_REACHED_BOWSERS_CASTLE)
STORY_PROGRESS_VALUE(CH8_REACHED_PEACHS_CASTLE)


// Epilogue
STORY_PROGRESS_VALUE(EPILOGUE)

STORY_PROGRESS_VALUE(NEVER)
STORY_PROGRESS_END
