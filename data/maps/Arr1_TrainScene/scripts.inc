Arr1_TrainScene_MapScripts::
# 2 "data/maps/Arr1_TrainScene/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Arr1_TrainScene_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Arr1_TrainScene_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/Arr1_TrainScene/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, Arr1_TrainScene_WhichWay
	.2byte 0


Arr1_TrainScene_WhichWay::
# 8 "data/maps/Arr1_TrainScene/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq Arr1_TrainScene_WhichWay_1
	return

Arr1_TrainScene_WhichWay_1:
# 9 "data/maps/Arr1_TrainScene/scripts.pory"
	call Arr1_TrainScene_ToRight
	return


Arr1_TrainScene_ToRight::
# 14 "data/maps/Arr1_TrainScene/scripts.pory"
	lock
# 16 "data/maps/Arr1_TrainScene/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr1_TrainScene_ToRight_Movement_0
# 18 "data/maps/Arr1_TrainScene/scripts.pory"
	addobject 1, MAP_ARR1_TRAIN_SCENE
# 19 "data/maps/Arr1_TrainScene/scripts.pory"
	addobject 2, MAP_ARR1_TRAIN_SCENE
# 20 "data/maps/Arr1_TrainScene/scripts.pory"
	addobject 3, MAP_ARR1_TRAIN_SCENE
# 21 "data/maps/Arr1_TrainScene/scripts.pory"
	addobject 4, MAP_ARR1_TRAIN_SCENE
# 22 "data/maps/Arr1_TrainScene/scripts.pory"
	addobject 5, MAP_ARR1_TRAIN_SCENE
# 24 "data/maps/Arr1_TrainScene/scripts.pory"
	applymovement 1, train_decalage
# 25 "data/maps/Arr1_TrainScene/scripts.pory"
	applymovement 2, train_decalage
# 26 "data/maps/Arr1_TrainScene/scripts.pory"
	applymovement 3, train_decalage
# 27 "data/maps/Arr1_TrainScene/scripts.pory"
	applymovement 4, train_decalage
# 28 "data/maps/Arr1_TrainScene/scripts.pory"
	applymovement 5, train_decalage
# 30 "data/maps/Arr1_TrainScene/scripts.pory"
	special SpawnCameraObject
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr1_TrainScene_ToRight_Movement_1
# 34 "data/maps/Arr1_TrainScene/scripts.pory"
	setvar VAR_0x8014, 1
# 35 "data/maps/Arr1_TrainScene/scripts.pory"
	playSE SE_DING_DONG
# 36 "data/maps/Arr1_TrainScene/scripts.pory"
	msgbox Arr1_TrainScene_ToRight_Text_0
# 37 "data/maps/Arr1_TrainScene/scripts.pory"
	closemessage
# 38 "data/maps/Arr1_TrainScene/scripts.pory"
	setvar VAR_0x8014, 0
# 41 "data/maps/Arr1_TrainScene/scripts.pory"
	waitmovement 0
# 43 "data/maps/Arr1_TrainScene/scripts.pory"
	fadescreen FADE_TO_BLACK
# 44 "data/maps/Arr1_TrainScene/scripts.pory"
	special RemoveCameraObject
# 45 "data/maps/Arr1_TrainScene/scripts.pory"
	setspeaker Arr1_TrainScene_ToRight_Text_1
# 46 "data/maps/Arr1_TrainScene/scripts.pory"
	msgbox Arr1_TrainScene_ToRight_Text_2
# 47 "data/maps/Arr1_TrainScene/scripts.pory"
	call PlayersHouse_2F_EventScript_SetWallClock
# 48 "data/maps/Arr1_TrainScene/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 49 "data/maps/Arr1_TrainScene/scripts.pory"
	closemessage
# 51 "data/maps/Arr1_TrainScene/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 54 "data/maps/Arr1_TrainScene/scripts.pory"
	warp MAP_OLDALE_TOWN_POKEMON_CENTER_2F, 13, 3
# 56 "data/maps/Arr1_TrainScene/scripts.pory"
	waitstate
# 57 "data/maps/Arr1_TrainScene/scripts.pory"
	release
	end


# 61 "data/maps/Arr1_TrainScene/scripts.pory"
train_decalage:
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 62 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
	step_end

# 16 "data/maps/Arr1_TrainScene/scripts.pory"
Arr1_TrainScene_ToRight_Movement_0:
# 16 "data/maps/Arr1_TrainScene/scripts.pory"
	set_invisible
	step_end

# 31 "data/maps/Arr1_TrainScene/scripts.pory"
Arr1_TrainScene_ToRight_Movement_1:
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
# 31 "data/maps/Arr1_TrainScene/scripts.pory"
	walk_right
	step_end

Arr1_TrainScene_ToRight_Text_0:
# 36 "data/maps/Arr1_TrainScene/scripts.pory"
	.string "{FONT_SMALL}{SHADOW GREEN}{COLOR LIGHT_GREEN}We are now entering the Gare de\n"
	.string "Saint-Chandelure. Please do not forget\l"
	.string "your luggage.$"

Arr1_TrainScene_ToRight_Text_1:
# 45 "data/maps/Arr1_TrainScene/scripts.pory"
	.string "Speaker$"

Arr1_TrainScene_ToRight_Text_2:
# 46 "data/maps/Arr1_TrainScene/scripts.pory"
	.string "We inform you that we are entering a\n"
	.string "new timezone. We recommend you to set\l"
	.string "your watch accordingly.$"
