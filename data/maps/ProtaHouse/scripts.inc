ProtaHouse_MapScripts::
# 6 "data/maps/ProtaHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ProtaHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ProtaHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/ProtaHouse/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, PalletTown_IntroDream
	.2byte 0


PalletTown_IntroDream::
# 13 "data/maps/ProtaHouse/scripts.pory"
	lockall
# 15 "data/maps/ProtaHouse/scripts.pory"
	setvar VAR_TEMP_0, 1
# 16 "data/maps/ProtaHouse/scripts.pory"
	fadescreen FADE_TO_WHITE
# 18 "data/maps/ProtaHouse/scripts.pory"
	setvar VAR_0x8014, 3
# 20 "data/maps/ProtaHouse/scripts.pory"
	playbgm MUS_RG_OAK, FALSE
# 22 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_0
# 23 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_1
# 24 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_2
# 25 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_3
# 26 "data/maps/ProtaHouse/scripts.pory"
	closemessage
# 27 "data/maps/ProtaHouse/scripts.pory"
	delay 120
# 29 "data/maps/ProtaHouse/scripts.pory"
	playbgm MUS_RG_OAK_LAB, FALSE
# 31 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_4
# 32 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_3
# 33 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_5
# 35 "data/maps/ProtaHouse/scripts.pory"
	fadeoutbgm 0
# 36 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_3
# 37 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_6
# 38 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_3
# 39 "data/maps/ProtaHouse/scripts.pory"
	playse SE_SUPER_EFFECTIVE
# 40 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_7
# 41 "data/maps/ProtaHouse/scripts.pory"
	closemessage
# 42 "data/maps/ProtaHouse/scripts.pory"
	setvar VAR_0x8014, 0
# 43 "data/maps/ProtaHouse/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 45 "data/maps/ProtaHouse/scripts.pory"
	playbgm MUS_RG_PALLET, 0
# 47 "data/maps/ProtaHouse/scripts.pory"
	setvar VAR_0x8014, 1
# 48 "data/maps/ProtaHouse/scripts.pory"
	msgbox PalletTown_IntroDream_Text_8
# 49 "data/maps/ProtaHouse/scripts.pory"
	closemessage
# 50 "data/maps/ProtaHouse/scripts.pory"
	setvar VAR_0x8014, 0
# 52 "data/maps/ProtaHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_IntroDream_Movement_0
# 58 "data/maps/ProtaHouse/scripts.pory"
	waitmovement 0
# 60 "data/maps/ProtaHouse/scripts.pory"
	warp MAP_VERDANTURF_TOWN, 4, 16
# 61 "data/maps/ProtaHouse/scripts.pory"
	waitstate
# 63 "data/maps/ProtaHouse/scripts.pory"
	release
	end


# 52 "data/maps/ProtaHouse/scripts.pory"
PalletTown_IntroDream_Movement_0:
# 53 "data/maps/ProtaHouse/scripts.pory"
	player_run_right
# 53 "data/maps/ProtaHouse/scripts.pory"
	player_run_right
# 53 "data/maps/ProtaHouse/scripts.pory"
	player_run_right
# 53 "data/maps/ProtaHouse/scripts.pory"
	player_run_right
# 53 "data/maps/ProtaHouse/scripts.pory"
	player_run_right
# 53 "data/maps/ProtaHouse/scripts.pory"
	player_run_right
# 53 "data/maps/ProtaHouse/scripts.pory"
	player_run_right
# 53 "data/maps/ProtaHouse/scripts.pory"
	player_run_right
# 54 "data/maps/ProtaHouse/scripts.pory"
	player_run_up
# 54 "data/maps/ProtaHouse/scripts.pory"
	player_run_up
# 55 "data/maps/ProtaHouse/scripts.pory"
	player_run_left
# 56 "data/maps/ProtaHouse/scripts.pory"
	set_invisible
	step_end

PalletTown_IntroDream_Text_0:
# 22 "data/maps/ProtaHouse/scripts.pory"
	.string "Hey! Wait!$"

PalletTown_IntroDream_Text_1:
# 23 "data/maps/ProtaHouse/scripts.pory"
	.string "Don't go out!$"

PalletTown_IntroDream_Text_2:
# 24 "data/maps/ProtaHouse/scripts.pory"
	.string "Wild Pokémon live in tall grass! \pYou need your own Pokémon for\nyour protection.\pHere, come with me!$"

PalletTown_IntroDream_Text_3:
# 25 "data/maps/ProtaHouse/scripts.pory"
	.string "...$"

PalletTown_IntroDream_Text_4:
# 31 "data/maps/ProtaHouse/scripts.pory"
	.string "On this table sit three Pokémon in their\n"
	.string "Poké Balls: Bulbasaur, Charmander, and\l"
	.string "Squirtle. Which one will you choose {COLOR RED}{SHADOW LIGHT_RED}Red {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\l"
	.string "?$"

PalletTown_IntroDream_Text_5:
# 33 "data/maps/ProtaHouse/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Red?$"

PalletTown_IntroDream_Text_6:
# 37 "data/maps/ProtaHouse/scripts.pory"
	.string "{PLAYER}?$"

PalletTown_IntroDream_Text_7:
# 40 "data/maps/ProtaHouse/scripts.pory"
	.string "{PLAYER}!!! Wake up, you are late! You\n"
	.string "will miss your boat to Kalos!$"

PalletTown_IntroDream_Text_8:
# 48 "data/maps/ProtaHouse/scripts.pory"
	.string "What a weird dream...$"
