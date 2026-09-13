VerdanturfTown_MapScripts::
# 2 "data/maps/VerdanturfTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

VerdanturfTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/VerdanturfTown/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, Intro_PalletTown_Goodbye
	.2byte 0


Intro_PalletTown_Goodbye::
# 10 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 11 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_TEMP_0, 1
# 13 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Intro_PalletTown_Goodbye_Movement_0
# 17 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 19 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_0x8014, 1
# 20 "data/maps/VerdanturfTown/scripts.pory"
	msgbox Intro_PalletTown_Goodbye_Text_0
# 21 "data/maps/VerdanturfTown/scripts.pory"
	closemessage
# 22 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_0x8014, 0
# 24 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Intro_PalletTown_Goodbye_Movement_1
# 30 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 32 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_0x8014, 1
# 33 "data/maps/VerdanturfTown/scripts.pory"
	msgbox Intro_PalletTown_Goodbye_Text_1
# 34 "data/maps/VerdanturfTown/scripts.pory"
	closemessage
# 35 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_0x8014, 0
# 37 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Intro_PalletTown_Goodbye_Movement_2
# 43 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 44 "data/maps/VerdanturfTown/scripts.pory"
	delay 120
# 47 "data/maps/VerdanturfTown/scripts.pory"
	fadescreen FADE_TO_BLACK
# 48 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_0x8014, 2
# 49 "data/maps/VerdanturfTown/scripts.pory"
	msgbox Intro_PalletTown_Goodbye_Text_2
# 50 "data/maps/VerdanturfTown/scripts.pory"
	closemessage
# 51 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_0x8014, 0
# 53 "data/maps/VerdanturfTown/scripts.pory"
	warp MAP_ARR1_TRAIN_SCENE, 25, 2
# 54 "data/maps/VerdanturfTown/scripts.pory"
	waitstate
# 58 "data/maps/VerdanturfTown/scripts.pory"
	releaseall
	end


# 13 "data/maps/VerdanturfTown/scripts.pory"
Intro_PalletTown_Goodbye_Movement_0:
# 14 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 14 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 15 "data/maps/VerdanturfTown/scripts.pory"
	face_up
	step_end

# 24 "data/maps/VerdanturfTown/scripts.pory"
Intro_PalletTown_Goodbye_Movement_1:
# 25 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 25 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 25 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 25 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 25 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 26 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 27 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 27 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 27 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 27 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 27 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 27 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 28 "data/maps/VerdanturfTown/scripts.pory"
	face_up
	step_end

# 37 "data/maps/VerdanturfTown/scripts.pory"
Intro_PalletTown_Goodbye_Movement_2:
# 38 "data/maps/VerdanturfTown/scripts.pory"
	player_run_left
# 38 "data/maps/VerdanturfTown/scripts.pory"
	player_run_left
# 38 "data/maps/VerdanturfTown/scripts.pory"
	player_run_left
# 38 "data/maps/VerdanturfTown/scripts.pory"
	player_run_left
# 38 "data/maps/VerdanturfTown/scripts.pory"
	player_run_left
# 38 "data/maps/VerdanturfTown/scripts.pory"
	player_run_left
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 39 "data/maps/VerdanturfTown/scripts.pory"
	player_run_up
# 40 "data/maps/VerdanturfTown/scripts.pory"
	face_down
	step_end

Intro_PalletTown_Goodbye_Text_0:
# 20 "data/maps/VerdanturfTown/scripts.pory"
	.string "Time to say goodbye to Pallet Town.\n"
	.string "Goodbye Mom.$"

Intro_PalletTown_Goodbye_Text_1:
# 33 "data/maps/VerdanturfTown/scripts.pory"
	.string "Goodbye, Prof. Oak. You've done a fine\n"
	.string "job keeping things running ever since\l"
	.string "your grandfather left us.$"

Intro_PalletTown_Goodbye_Text_2:
# 49 "data/maps/VerdanturfTown/scripts.pory"
	.string "Goodbye, Pallet Town!$"
