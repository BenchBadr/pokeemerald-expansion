Amphiteatre_MapScripts::
# 2 "data/maps/Amphiteatre/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Amphiteatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Amphiteatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/Amphiteatre/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, Amphiteatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

Amphiteatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 4 "data/maps/Amphiteatre/scripts.pory"
	lock
# 5 "data/maps/Amphiteatre/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Amphiteatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
Amphiteatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
# 9 "data/maps/Amphiteatre/scripts.pory"
	setvar VAR_TEMP_0, 1
# 10 "data/maps/Amphiteatre/scripts.pory"
	release
	return

Amphiteatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
# 6 "data/maps/Amphiteatre/scripts.pory"
	call Amphiteatre_CreateCrowd
# 7 "data/maps/Amphiteatre/scripts.pory"
	setflag FLAG_TEMP_1
	goto Amphiteatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1


Amphiteatre_CreateCrowd::
# 27 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 9, 3, 0, DIR_SOUTH, 1, 0, 20
# 28 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 25, 15, 2, 0, DIR_SOUTH, 1, 0, 23
# 29 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 13, 2, 0, DIR_SOUTH, 1, 0, 25
# 30 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 15, 3, 0, DIR_SOUTH, 1, 0, 27
# 31 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 21, 19, 4, 0, DIR_SOUTH, 1, 0, 30
# 32 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 22, 9, 4, 0, DIR_SOUTH, 1, 0, 34
# 33 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 21, 13, 4, 0, DIR_SOUTH, 1, 0, 38
# 34 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 14, 19, 2, 0, DIR_SOUTH, 1, 0, 42
# 35 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 22, 2, 0, DIR_EAST, 1, 1, 44
# 36 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 31, 3, 0, DIR_EAST, 1, 1, 46
	return


Sycamore::
# 40 "data/maps/Amphiteatre/scripts.pory"
	lock
# 41 "data/maps/Amphiteatre/scripts.pory"
	faceplayer
# 42 "data/maps/Amphiteatre/scripts.pory"
	playbgm MUS_XY_SYNCA, FALSE
# 43 "data/maps/Amphiteatre/scripts.pory"
	msgbox Sycamore_Text_0
# 44 "data/maps/Amphiteatre/scripts.pory"
	release
	end


Arr2_AmphiIntroduction::
# 49 "data/maps/Amphiteatre/scripts.pory"
	lock
# 50 "data/maps/Amphiteatre/scripts.pory"
	msgbox Arr2_AmphiIntroduction_Text_0
# 51 "data/maps/Amphiteatre/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_AmphiIntroduction_Movement_0
# 56 "data/maps/Amphiteatre/scripts.pory"
	waitmovement 0
# 57 "data/maps/Amphiteatre/scripts.pory"
	release
	end


# 51 "data/maps/Amphiteatre/scripts.pory"
Arr2_AmphiIntroduction_Movement_0:
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 52 "data/maps/Amphiteatre/scripts.pory"
	player_run_down
# 53 "data/maps/Amphiteatre/scripts.pory"
	player_run_left
# 53 "data/maps/Amphiteatre/scripts.pory"
	player_run_left
# 54 "data/maps/Amphiteatre/scripts.pory"
	face_down
	step_end

Sycamore_Text_0:
# 43 "data/maps/Amphiteatre/scripts.pory"
	.string "here's some music$"

Arr2_AmphiIntroduction_Text_0:
# 50 "data/maps/Amphiteatre/scripts.pory"
	.string "You're late. Hurry up.$"
