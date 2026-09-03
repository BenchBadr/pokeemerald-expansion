OldaleTown_PokemonCenter_2F_MapScripts::
# 2 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 5 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x493, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
# 6 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	lock
# 14 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
# 15 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Movement_0
# 16 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
# 17 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 18 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
# 19 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 20 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	giveitem ITEM_FRESH_WATER, 1
# 21 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3
# 22 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 23 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4
# 24 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 25 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5
# 26 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 27 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6
# 28 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 29 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7
# 30 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_8
# 31 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	warp MAP_DEWFORD_TOWN, 0
# 32 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	end


# 15 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Movement_0:
# 15 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_right
	step_end

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 14 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "{FONT_SMALL}{COLOR GREEN}{SHADOW LIGHT_GREEN}This train terminates at {COLOR RED}{SHADOW LIGHT_RED}Place Suicune.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
# 16 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I assume it's your first time in a\n"
	.string "Lutecian metro.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
# 18 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Take some water, you must be tired with\n"
	.string "all that traveling.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
# 21 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "There is multiple metro lines, allowing\n"
	.string "you to go from a place to another. You\l"
	.string "can always check which line it is by\l"
	.string "reading the signpost in front of the\l"
	.string "entrance of the stations.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
# 23 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "This metro for example is the {COLOR RED}{SHADOW LIGHT_RED}ligne A.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5:
# 25 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "One important thing to now, you gotta\n"
	.string "be ready to fight here. People come for\l"
	.string "various workplaces, they are tired and\l"
	.string "bored so they battle.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6:
# 27 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So next time you take one, keep\n"
	.string "battling until you arrive!$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7:
# 29 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "{FONT_SMALL}{COLOR GREEN}{SHADOW LIGHT_GREEN}Place Suicune.$"

OldaleTown_PokemonCenter_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_8:
# 30 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "{FONT_SMALL}{COLOR GREEN}{SHADOW LIGHT_GREEN}This is our last stop.$"
