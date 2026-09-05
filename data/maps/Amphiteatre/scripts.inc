Amphiteatre_MapScripts::
# 2 "data/maps/Amphiteatre/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Amphiteatre_OnResume
	.byte 0


Amphiteatre_OnResume::
# 7 "data/maps/Amphiteatre/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Amphiteatre_OnResume_2
Amphiteatre_OnResume_1:
	end

Amphiteatre_OnResume_2:
# 8 "data/maps/Amphiteatre/scripts.pory"
	setflag FLAG_TEMP_1
# 20 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 2, 3, 0, DIR_SOUTH, 1, 0, 20
# 21 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 25, 8, 2, 0, DIR_SOUTH, 1, 0, 23
# 22 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 6, 2, 0, DIR_SOUTH, 1, 0, 25
# 23 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 8, 3, 0, DIR_SOUTH, 1, 0, 27
# 24 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 21, 12, 4, 0, DIR_SOUTH, 1, 0, 30
# 25 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 21, 2, 4, 0, DIR_SOUTH, 1, 0, 34
# 26 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 21, 6, 4, 0, DIR_SOUTH, 1, 0, 38
# 27 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 14, 12, 2, 0, DIR_SOUTH, 1, 0, 42
# 28 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 15, 2, 0, DIR_EAST, 1, 1, 44
# 29 "data/maps/Amphiteatre/scripts.pory"
	createvirtualobjects 12, 24, 3, 0, DIR_EAST, 1, 1, 46
	goto Amphiteatre_OnResume_1

