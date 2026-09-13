OldaleTown_PokemonCenter_2F_MapScripts::
# 2 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 5 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
# 6 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	lock
# 15 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_0x8014, 1
# 16 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
# 17 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_0x8014, 0
# 19 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Movement_0
# 20 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement 2, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Movement_1
# 22 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
# 23 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 24 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
# 25 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 26 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	giveitem ITEM_FRESH_WATER, 1
# 27 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3
# 28 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 29 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4
# 30 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 31 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5
# 32 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 33 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6
# 34 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 37 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_0x8014, 1
# 38 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playSE SE_TRUCK_STOP
# 39 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playSE SE_DING_DONG
# 40 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7
# 41 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_8
# 42 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_0x8014, 0
# 44 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	warp MAP_OLDALE_TOWN, 0
# 45 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitstate
# 46 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	end


# 19 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Movement_0:
# 19 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_left
	step_end

# 20 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Movement_1:
# 20 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_right
	step_end

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 16 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "{FONT_SMALL}{COLOR GREEN}{SHADOW LIGHT_GREEN}This train terminates at {COLOR RED}{SHADOW LIGHT_RED}Copernic Labs$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
# 22 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Is it your first time in Lutecia?$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
# 24 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Take some water, you must be tired with\n"
	.string "all that traveling.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
# 27 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "There is multiple metro lines, allowing\n"
	.string "you to go from a place to another. You\l"
	.string "can always check which line it is by\l"
	.string "reading the signpost in front of the\l"
	.string "entrance of the stations.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
# 29 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "This metro for example is the {COLOR RED}{SHADOW LIGHT_RED}ligne A.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5:
# 31 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "One important thing to now, you gotta\n"
	.string "be ready to fight here. People come for\l"
	.string "various workplaces, they are tired and\l"
	.string "bored so they battle.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6:
# 33 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So next time you take one, keep\n"
	.string "battling until you arrive!$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7:
# 40 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "{FONT_SMALL}{COLOR LIGHT_GREEN}{SHADOW GREEN}Copernic Labs.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_8:
# 41 "data/maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "{FONT_SMALL}{COLOR LIGHT_GREEN}{SHADOW GREEN}This is our last stop.$"
