Amphitheatre_MapScripts::
# 2 "data/maps/Amphitheatre/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Amphitheatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Amphitheatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/Amphitheatre/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, Amphitheatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

Amphitheatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 4 "data/maps/Amphitheatre/scripts.pory"
	lock
# 5 "data/maps/Amphitheatre/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Amphitheatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
Amphitheatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
# 17 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_TEMP_0, 1
# 18 "data/maps/Amphitheatre/scripts.pory"
	release
	return

Amphitheatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
# 6 "data/maps/Amphitheatre/scripts.pory"
	call Amphitheatre_CreateCrowd
# 8 "data/maps/Amphitheatre/scripts.pory"
	setflag FLAG_TEMP_1
# 10 "data/maps/Amphitheatre/scripts.pory"
	removeobject 6, MAP_AMPHITHEATRE
# 11 "data/maps/Amphitheatre/scripts.pory"
	removeobject 7, MAP_AMPHITHEATRE
# 12 "data/maps/Amphitheatre/scripts.pory"
	removeobject 8, MAP_AMPHITHEATRE
# 14 "data/maps/Amphitheatre/scripts.pory"
	setflag FLAG_IS_CHOOSING_MON
	goto Amphitheatre_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1


Amphitheatre_CreateCrowd::
# 25 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 12, 9, 3, VAR_TEMP_5, DIR_SOUTH, 1, 0, 20
# 26 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 25, 15, 2, VAR_TEMP_5, DIR_SOUTH, 1, 0, 23
# 27 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 12, 13, 2, VAR_TEMP_5, DIR_SOUTH, 1, 0, 25
# 28 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 12, 15, 3, VAR_TEMP_5, DIR_SOUTH, 1, 0, 27
# 29 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 21, 19, 4, VAR_TEMP_5, DIR_SOUTH, 1, 0, 30
# 31 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 22, 9, 3, VAR_TEMP_5, DIR_SOUTH, 1, 0, 34
# 33 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 21, 13, 4, VAR_TEMP_5, DIR_SOUTH, 1, 0, 38
# 34 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 14, 19, 2, VAR_TEMP_5, DIR_SOUTH, 1, 0, 42
# 37 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 12, 22, 2, VAR_TEMP_5, DIR_EAST, 1, 1, 44
# 38 "data/maps/Amphitheatre/scripts.pory"
	createvirtualobjects 12, 31, 2, VAR_TEMP_5, DIR_EAST, 1, 1, 46
	return


Amphitheatre_ClearCrowd::
# 42 "data/maps/Amphitheatre/scripts.pory"
	special DrawWholeMapView
# 43 "data/maps/Amphitheatre/scripts.pory"
	setflag FLAG_TEMP_1
	return


Arr2_AmphiIntroduction::
# 52 "data/maps/Amphitheatre/scripts.pory"
	lock
# 53 "data/maps/Amphitheatre/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, Arr2_AmphiIntroduction_2
# 60 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_AmphiIntroduction_Movement_0
# 63 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 65 "data/maps/Amphitheatre/scripts.pory"
	msgbox Arr2_AmphiIntroduction_Text_1
# 67 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 69 "data/maps/Amphitheatre/scripts.pory"
	playSE SE_PIN
# 71 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_AmphiIntroduction_Movement_1
# 77 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 79 "data/maps/Amphitheatre/scripts.pory"
	delay 60
# 82 "data/maps/Amphitheatre/scripts.pory"
	special SpawnCameraObject
# 83 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_AmphiIntroduction_Movement_2
# 84 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 87 "data/maps/Amphitheatre/scripts.pory"
	hideobjectat 6, MAP_AMPHITHEATRE
# 88 "data/maps/Amphitheatre/scripts.pory"
	hideobjectat 7, MAP_AMPHITHEATRE
# 89 "data/maps/Amphitheatre/scripts.pory"
	hideobjectat 8, MAP_AMPHITHEATRE
# 91 "data/maps/Amphitheatre/scripts.pory"
	call Amphi_IntroScientist1
# 92 "data/maps/Amphitheatre/scripts.pory"
	call Amphi_IntroSycamore1
# 93 "data/maps/Amphitheatre/scripts.pory"
	call Amphi_IntroScientist2
# 94 "data/maps/Amphitheatre/scripts.pory"
	call Amphi_IntroCallingNames
# 97 "data/maps/Amphitheatre/scripts.pory"
	special RemoveCameraObject
# 99 "data/maps/Amphitheatre/scripts.pory"
	call Amphi_CallingTrainer
# 104 "data/maps/Amphitheatre/scripts.pory"
	special RemoveCameraObject
# 107 "data/maps/Amphitheatre/scripts.pory"
	release
	end

Arr2_AmphiIntroduction_2:
# 54 "data/maps/Amphitheatre/scripts.pory"
	msgbox Arr2_AmphiIntroduction_Text_0
	return


Amphi_IntroScientist1::
# 112 "data/maps/Amphitheatre/scripts.pory"
	setspeaker Amphi_IntroScientist1_Text_0
# 114 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist1_Text_1
# 115 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist1_Text_2
# 117 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist1_Text_3
# 119 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist1_Text_4
# 121 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 123 "data/maps/Amphitheatre/scripts.pory"
	applymovement 1, Amphi_IntroScientist1_Movement_0
# 127 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 129 "data/maps/Amphitheatre/scripts.pory"
	closemessage
	return


Amphi_IntroSycamore1::
# 134 "data/maps/Amphitheatre/scripts.pory"
	playbgm MUS_SYCAMORE, FALSE
# 136 "data/maps/Amphitheatre/scripts.pory"
	applymovement 2, Amphi_IntroSycamore1_Movement_0
# 137 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 139 "data/maps/Amphitheatre/scripts.pory"
	setspeaker Amphi_IntroSycamore1_Text_0
# 140 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroSycamore1_Text_1
# 141 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroSycamore1_Text_2
# 142 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroSycamore1_Text_3
# 143 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroSycamore1_Text_4
# 144 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroSycamore1_Text_5
# 145 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 147 "data/maps/Amphitheatre/scripts.pory"
	applymovement 2, Amphi_IntroScientist1_Movement_0
# 151 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 152 "data/maps/Amphitheatre/scripts.pory"
	playSE SE_APPLAUSE
# 153 "data/maps/Amphitheatre/scripts.pory"
	delay 120
# 155 "data/maps/Amphitheatre/scripts.pory"
	closemessage
	return


Amphi_IntroScientist2::
# 161 "data/maps/Amphitheatre/scripts.pory"
	applymovement 1, Amphi_IntroSycamore1_Movement_0
# 162 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 165 "data/maps/Amphitheatre/scripts.pory"
	setspeaker Amphi_IntroScientist1_Text_0
# 167 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist2_Text_0
# 168 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist2_Text_1
# 169 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist2_Text_2
# 170 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist2_Text_3
# 172 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist2_Text_4
# 173 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist2_Text_5
# 175 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 177 "data/maps/Amphitheatre/scripts.pory"
	applymovement 1, Amphi_IntroScientist1_Movement_0
# 181 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
	return


Amphi_IntroCallingNames::
# 188 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroCallingNames_Text_0
# 189 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 191 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Amphi_IntroCallingNames_Movement_0
# 192 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 194 "data/maps/Amphitheatre/scripts.pory"
	playSE SE_PIN
# 195 "data/maps/Amphitheatre/scripts.pory"
	applymovement 4, Amphi_IntroCallingNames_Movement_1
# 199 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroCallingNames_Text_1
# 200 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 204 "data/maps/Amphitheatre/scripts.pory"
	applymovement 4, Amphi_IntroCallingNames_Movement_2
# 208 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 209 "data/maps/Amphitheatre/scripts.pory"
	removeobject 4
# 211 "data/maps/Amphitheatre/scripts.pory"
	setspeaker Amphi_IntroSycamore1_Text_0
# 212 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroCallingNames_Text_2
# 213 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 215 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroCallingNames_Text_3
# 216 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 218 "data/maps/Amphitheatre/scripts.pory"
	delay 60
# 221 "data/maps/Amphitheatre/scripts.pory"
	applymovement 5, Amphi_IntroCallingNames_Movement_3
# 222 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_AmphiIntroduction_Movement_0
# 224 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroCallingNames_Text_4
# 225 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroCallingNames_Text_5
# 226 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 228 "data/maps/Amphitheatre/scripts.pory"
	applymovement 5, Amphi_IntroCallingNames_Movement_4
# 229 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Amphi_IntroCallingNames_Movement_4
# 232 "data/maps/Amphitheatre/scripts.pory"
	fadescreen FADE_TO_BLACK
# 233 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 2
# 235 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroCallingNames_Text_6
# 237 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 238 "data/maps/Amphitheatre/scripts.pory"
	callnative DestroyVirtualObjects
# 240 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 0
# 241 "data/maps/Amphitheatre/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


Amphi_CallingTrainer::
# 245 "data/maps/Amphitheatre/scripts.pory"
	callnative GetTrainerIdString
# 246 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_CallingTrainer_Text_0
# 247 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 250 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Amphi_CallingTrainer_Movement_0
# 254 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 256 "data/maps/Amphitheatre/scripts.pory"
	applymovement 1, Amphi_CallingTrainer_Movement_1
# 261 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Amphi_CallingTrainer_Movement_2
# 265 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 269 "data/maps/Amphitheatre/scripts.pory"
	setspeaker Amphi_IntroScientist1_Text_0
# 270 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_CallingTrainer_Text_1
# 271 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 274 "data/maps/Amphitheatre/scripts.pory"
	applymovement 2, Amphi_CallingTrainer_Movement_3
# 278 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 280 "data/maps/Amphitheatre/scripts.pory"
	setspeaker Amphi_IntroSycamore1_Text_0
# 281 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_CallingTrainer_Text_2
# 282 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 284 "data/maps/Amphitheatre/scripts.pory"
	fadedefaultbgm
# 286 "data/maps/Amphitheatre/scripts.pory"
	clearflag FLAG_IS_CHOOSING_MON
# 288 "data/maps/Amphitheatre/scripts.pory"
	addobject 6
# 289 "data/maps/Amphitheatre/scripts.pory"
	addobject 7
# 290 "data/maps/Amphitheatre/scripts.pory"
	addobject 8
# 292 "data/maps/Amphitheatre/scripts.pory"
	showobjectat 6, MAP_AMPHITHEATRE
# 293 "data/maps/Amphitheatre/scripts.pory"
	showobjectat 7, MAP_AMPHITHEATRE
# 294 "data/maps/Amphitheatre/scripts.pory"
	showobjectat 8, MAP_AMPHITHEATRE
# 296 "data/maps/Amphitheatre/scripts.pory"
	playSE SE_BALL_OPEN
# 297 "data/maps/Amphitheatre/scripts.pory"
	playSE SE_BALL_OPEN
# 298 "data/maps/Amphitheatre/scripts.pory"
	playSE SE_BALL_OPEN
# 300 "data/maps/Amphitheatre/scripts.pory"
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
# 301 "data/maps/Amphitheatre/scripts.pory"
	playmoncry SPECIES_CHIMCHAR, CRY_MODE_NORMAL
# 302 "data/maps/Amphitheatre/scripts.pory"
	playmoncry SPECIES_SOBBLE, CRY_MODE_NORMAL
# 303 "data/maps/Amphitheatre/scripts.pory"
	waitmoncry
# 306 "data/maps/Amphitheatre/scripts.pory"
	applymovement 6, Amphi_CallingTrainer_Movement_4
# 310 "data/maps/Amphitheatre/scripts.pory"
	applymovement 7, Amphi_CallingTrainer_Movement_5
# 314 "data/maps/Amphitheatre/scripts.pory"
	applymovement 8, Amphi_CallingTrainer_Movement_6
# 318 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 321 "data/maps/Amphitheatre/scripts.pory"
	delay 60
# 322 "data/maps/Amphitheatre/scripts.pory"
	special SaveGame
# 325 "data/maps/Amphitheatre/scripts.pory"
	release
	end


Amphi_ChooseSnivy::
# 332 "data/maps/Amphitheatre/scripts.pory"
	lock
# 333 "data/maps/Amphitheatre/scripts.pory"
	faceplayer
# 334 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 1
# 335 "data/maps/Amphitheatre/scripts.pory"
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
# 336 "data/maps/Amphitheatre/scripts.pory"
	showmonpic SPECIES_SNIVY, 0, 4
# 337 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_ChooseSnivy_Text_0, MSGBOX_YESNO
# 338 "data/maps/Amphitheatre/scripts.pory"
	waitmoncry
# 339 "data/maps/Amphitheatre/scripts.pory"
	hidemonpic
# 340 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 0
# 341 "data/maps/Amphitheatre/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Amphi_ChooseSnivy_2
Amphi_ChooseSnivy_1:
# 359 "data/maps/Amphitheatre/scripts.pory"
	closemessage
	return

Amphi_ChooseSnivy_2:
# 342 "data/maps/Amphitheatre/scripts.pory"
	applymovement 6, Amphi_ChooseSnivy_Movement_0
# 346 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 348 "data/maps/Amphitheatre/scripts.pory"
	givemon SPECIES_SNIVY, 5, ITEM_NONE
# 349 "data/maps/Amphitheatre/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SNIVY
# 351 "data/maps/Amphitheatre/scripts.pory"
	applymovement 6, Amphi_ChooseSnivy_Movement_1
# 354 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 356 "data/maps/Amphitheatre/scripts.pory"
	call Amphi_StarterNickname
	goto Amphi_ChooseSnivy_1


Amphi_ChooseChimchar::
# 363 "data/maps/Amphitheatre/scripts.pory"
	lock
# 364 "data/maps/Amphitheatre/scripts.pory"
	faceplayer
# 365 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 1
# 366 "data/maps/Amphitheatre/scripts.pory"
	playmoncry SPECIES_CHIMCHAR, CRY_MODE_NORMAL
# 367 "data/maps/Amphitheatre/scripts.pory"
	showmonpic SPECIES_CHIMCHAR, 0, 4
# 368 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_ChooseChimchar_Text_0, MSGBOX_YESNO
# 369 "data/maps/Amphitheatre/scripts.pory"
	waitmoncry
# 370 "data/maps/Amphitheatre/scripts.pory"
	hidemonpic
# 371 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 0
# 372 "data/maps/Amphitheatre/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Amphi_ChooseChimchar_2
Amphi_ChooseChimchar_1:
# 389 "data/maps/Amphitheatre/scripts.pory"
	closemessage
	return

Amphi_ChooseChimchar_2:
# 373 "data/maps/Amphitheatre/scripts.pory"
	applymovement 6, Amphi_ChooseSnivy_Movement_0
# 377 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 378 "data/maps/Amphitheatre/scripts.pory"
	givemon SPECIES_CHIMCHAR, 5, ITEM_NONE
# 379 "data/maps/Amphitheatre/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CHIMCHAR
# 381 "data/maps/Amphitheatre/scripts.pory"
	applymovement 6, Amphi_ChooseSnivy_Movement_1
# 384 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 386 "data/maps/Amphitheatre/scripts.pory"
	call Amphi_StarterNickname
	goto Amphi_ChooseChimchar_1


Amphi_ChooseSobble::
# 393 "data/maps/Amphitheatre/scripts.pory"
	lock
# 394 "data/maps/Amphitheatre/scripts.pory"
	faceplayer
# 395 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 1
# 396 "data/maps/Amphitheatre/scripts.pory"
	playmoncry SPECIES_SOBBLE, CRY_MODE_NORMAL
# 397 "data/maps/Amphitheatre/scripts.pory"
	showmonpic SPECIES_SOBBLE, 0, 4
# 398 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_ChooseSobble_Text_0, MSGBOX_YESNO
# 399 "data/maps/Amphitheatre/scripts.pory"
	waitmoncry
# 400 "data/maps/Amphitheatre/scripts.pory"
	hidemonpic
# 401 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 0
# 402 "data/maps/Amphitheatre/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Amphi_ChooseSobble_2
Amphi_ChooseSobble_1:
# 419 "data/maps/Amphitheatre/scripts.pory"
	closemessage
	return

Amphi_ChooseSobble_2:
# 403 "data/maps/Amphitheatre/scripts.pory"
	applymovement 6, Amphi_ChooseSnivy_Movement_0
# 407 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 408 "data/maps/Amphitheatre/scripts.pory"
	givemon SPECIES_SOBBLE, 5, ITEM_NONE
# 409 "data/maps/Amphitheatre/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SOBBLE
# 411 "data/maps/Amphitheatre/scripts.pory"
	applymovement 6, Amphi_ChooseSnivy_Movement_1
# 414 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 416 "data/maps/Amphitheatre/scripts.pory"
	call Amphi_StarterNickname
	goto Amphi_ChooseSobble_1


Amphi_StarterNickname::
# 423 "data/maps/Amphitheatre/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 424 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_StarterNickname_Text_0, MSGBOX_YESNO
# 425 "data/maps/Amphitheatre/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Amphi_StarterNickname_2
Amphi_StarterNickname_1:
# 431 "data/maps/Amphitheatre/scripts.pory"
	applymovement 2, Amphi_StarterNickname_Movement_0
# 436 "data/maps/Amphitheatre/scripts.pory"
	applymovement 3, Amphi_IntroCallingNames_Movement_3
# 440 "data/maps/Amphitheatre/scripts.pory"
	applymovement 6, Amphi_ChooseSnivy_Movement_1
# 444 "data/maps/Amphitheatre/scripts.pory"
	applymovement 7, Amphi_ChooseSnivy_Movement_1
# 448 "data/maps/Amphitheatre/scripts.pory"
	applymovement 8, Amphi_ChooseSnivy_Movement_1
# 452 "data/maps/Amphitheatre/scripts.pory"
	waitmovement 0
# 454 "data/maps/Amphitheatre/scripts.pory"
	setvar VAR_0x8014, 0
# 455 "data/maps/Amphitheatre/scripts.pory"
	setspeaker Amphi_IntroSycamore1_Text_0
# 456 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_StarterNickname_Text_1
# 460 "data/maps/Amphitheatre/scripts.pory"
	setflag FLAG_SYS_POKENAV_GET
# 461 "data/maps/Amphitheatre/scripts.pory"
	setflag FLAG_IS_CHOOSING_MON
# 463 "data/maps/Amphitheatre/scripts.pory"
	closemessage
# 464 "data/maps/Amphitheatre/scripts.pory"
	release
	end

Amphi_StarterNickname_2:
# 426 "data/maps/Amphitheatre/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Amphi_StarterNickname_4
	goto Amphi_StarterNickname_1

Amphi_StarterNickname_4:
# 427 "data/maps/Amphitheatre/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto Amphi_StarterNickname_1


Amphi_Policeman::
# 469 "data/maps/Amphitheatre/scripts.pory"
	lock
# 470 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_Policeman_Text_0
# 471 "data/maps/Amphitheatre/scripts.pory"
	release
	end


Arr2_ForceChooseStarter::
# 476 "data/maps/Amphitheatre/scripts.pory"
	lock
# 477 "data/maps/Amphitheatre/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, Arr2_ForceChooseStarter_2
Arr2_ForceChooseStarter_1:
# 487 "data/maps/Amphitheatre/scripts.pory"
	release
	end

Arr2_ForceChooseStarter_2:
# 479 "data/maps/Amphitheatre/scripts.pory"
	msgbox Amphi_IntroScientist1_Text_0
# 480 "data/maps/Amphitheatre/scripts.pory"
	msgbox Arr2_ForceChooseStarter_Text_0
# 482 "data/maps/Amphitheatre/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_ForceChooseStarter_Movement_0
	goto Arr2_ForceChooseStarter_1


# 60 "data/maps/Amphitheatre/scripts.pory"
Arr2_AmphiIntroduction_Movement_0:
# 61 "data/maps/Amphitheatre/scripts.pory"
	face_right
	step_end

# 71 "data/maps/Amphitheatre/scripts.pory"
Arr2_AmphiIntroduction_Movement_1:
# 72 "data/maps/Amphitheatre/scripts.pory"
	emote_exclamation_mark
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 73 "data/maps/Amphitheatre/scripts.pory"
	player_run_down
# 74 "data/maps/Amphitheatre/scripts.pory"
	player_run_right
# 74 "data/maps/Amphitheatre/scripts.pory"
	player_run_right
# 75 "data/maps/Amphitheatre/scripts.pory"
	face_down
	step_end

# 83 "data/maps/Amphitheatre/scripts.pory"
Arr2_AmphiIntroduction_Movement_2:
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 83 "data/maps/Amphitheatre/scripts.pory"
	walk_down
	step_end

# 123 "data/maps/Amphitheatre/scripts.pory"
Amphi_IntroScientist1_Movement_0:
# 124 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 124 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 124 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 125 "data/maps/Amphitheatre/scripts.pory"
	face_up
	step_end

# 136 "data/maps/Amphitheatre/scripts.pory"
Amphi_IntroSycamore1_Movement_0:
# 136 "data/maps/Amphitheatre/scripts.pory"
	walk_up
# 136 "data/maps/Amphitheatre/scripts.pory"
	walk_up
# 136 "data/maps/Amphitheatre/scripts.pory"
	walk_up
	step_end

# 191 "data/maps/Amphitheatre/scripts.pory"
Amphi_IntroCallingNames_Movement_0:
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
# 191 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_up
	step_end

# 195 "data/maps/Amphitheatre/scripts.pory"
Amphi_IntroCallingNames_Movement_1:
# 196 "data/maps/Amphitheatre/scripts.pory"
	emote_exclamation_mark
# 197 "data/maps/Amphitheatre/scripts.pory"
	jump_in_place_down
	step_end

# 204 "data/maps/Amphitheatre/scripts.pory"
Amphi_IntroCallingNames_Movement_2:
# 205 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_right
# 205 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_right
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 206 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
	step_end

# 221 "data/maps/Amphitheatre/scripts.pory"
Amphi_IntroCallingNames_Movement_3:
# 221 "data/maps/Amphitheatre/scripts.pory"
	face_left
	step_end

# 228 "data/maps/Amphitheatre/scripts.pory"
Amphi_IntroCallingNames_Movement_4:
# 228 "data/maps/Amphitheatre/scripts.pory"
	face_down
	step_end

# 250 "data/maps/Amphitheatre/scripts.pory"
Amphi_CallingTrainer_Movement_0:
# 251 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_left
# 251 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_left
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
# 252 "data/maps/Amphitheatre/scripts.pory"
	walk_fast_down
	step_end

# 256 "data/maps/Amphitheatre/scripts.pory"
Amphi_CallingTrainer_Movement_1:
# 257 "data/maps/Amphitheatre/scripts.pory"
	walk_right
# 257 "data/maps/Amphitheatre/scripts.pory"
	walk_right
# 258 "data/maps/Amphitheatre/scripts.pory"
	walk_up
	step_end

# 261 "data/maps/Amphitheatre/scripts.pory"
Amphi_CallingTrainer_Movement_2:
# 262 "data/maps/Amphitheatre/scripts.pory"
	walk_right
# 262 "data/maps/Amphitheatre/scripts.pory"
	walk_right
# 262 "data/maps/Amphitheatre/scripts.pory"
	walk_right
# 262 "data/maps/Amphitheatre/scripts.pory"
	walk_right
# 263 "data/maps/Amphitheatre/scripts.pory"
	face_up
	step_end

# 274 "data/maps/Amphitheatre/scripts.pory"
Amphi_CallingTrainer_Movement_3:
# 275 "data/maps/Amphitheatre/scripts.pory"
	walk_up
# 275 "data/maps/Amphitheatre/scripts.pory"
	walk_up
# 275 "data/maps/Amphitheatre/scripts.pory"
	walk_up
# 275 "data/maps/Amphitheatre/scripts.pory"
	walk_up
# 276 "data/maps/Amphitheatre/scripts.pory"
	face_down
	step_end

# 306 "data/maps/Amphitheatre/scripts.pory"
Amphi_CallingTrainer_Movement_4:
# 307 "data/maps/Amphitheatre/scripts.pory"
	exit_pokeball
# 308 "data/maps/Amphitheatre/scripts.pory"
	face_right
	step_end

# 310 "data/maps/Amphitheatre/scripts.pory"
Amphi_CallingTrainer_Movement_5:
# 311 "data/maps/Amphitheatre/scripts.pory"
	exit_pokeball
# 312 "data/maps/Amphitheatre/scripts.pory"
	face_down
	step_end

# 314 "data/maps/Amphitheatre/scripts.pory"
Amphi_CallingTrainer_Movement_6:
# 315 "data/maps/Amphitheatre/scripts.pory"
	exit_pokeball
# 316 "data/maps/Amphitheatre/scripts.pory"
	face_left
	step_end

# 342 "data/maps/Amphitheatre/scripts.pory"
Amphi_ChooseSnivy_Movement_0:
# 343 "data/maps/Amphitheatre/scripts.pory"
	emote_heart
# 344 "data/maps/Amphitheatre/scripts.pory"
	jump_in_place_right
# 344 "data/maps/Amphitheatre/scripts.pory"
	jump_in_place_right
# 344 "data/maps/Amphitheatre/scripts.pory"
	jump_in_place_right
	step_end

# 351 "data/maps/Amphitheatre/scripts.pory"
Amphi_ChooseSnivy_Movement_1:
# 352 "data/maps/Amphitheatre/scripts.pory"
	enter_pokeball
	step_end

# 431 "data/maps/Amphitheatre/scripts.pory"
Amphi_StarterNickname_Movement_0:
# 432 "data/maps/Amphitheatre/scripts.pory"
	walk_down
# 433 "data/maps/Amphitheatre/scripts.pory"
	face_right
	step_end

# 482 "data/maps/Amphitheatre/scripts.pory"
Arr2_ForceChooseStarter_Movement_0:
# 483 "data/maps/Amphitheatre/scripts.pory"
	walk_right
	step_end

Arr2_AmphiIntroduction_Text_0:
# 54 "data/maps/Amphitheatre/scripts.pory"
	.string "Time to battle with Rival.$"

Arr2_AmphiIntroduction_Text_1:
# 65 "data/maps/Amphitheatre/scripts.pory"
	.string "You're late. Hurry up.$"

Amphi_IntroScientist1_Text_0:
# 112 "data/maps/Amphitheatre/scripts.pory"
	.string "Host$"

Amphi_IntroScientist1_Text_1:
# 114 "data/maps/Amphitheatre/scripts.pory"
	.string "... that unexpectedly ascended into\n"
	.string "among the greatest trainers worldwide.$"

Amphi_IntroScientist1_Text_2:
# 115 "data/maps/Amphitheatre/scripts.pory"
	.string "The PWC, stands for Pokémon World\n"
	.string "Championship. It's a world organization\l"
	.string "that help nominate the best trainer\l"
	.string "worldwide every five years.$"

Amphi_IntroScientist1_Text_3:
# 117 "data/maps/Amphitheatre/scripts.pory"
	.string "Not only that but it also funds a lot of\n"
	.string "infrastructures like {COLOR RED}{SHADOW LIGHT_RED}Pokémon Centers {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\l"
	.string "or {COLOR RED}{SHADOW LIGHT_RED}Battle Zones.$"

Amphi_IntroScientist1_Text_4:
# 119 "data/maps/Amphitheatre/scripts.pory"
	.string "We will now welcome Prof. Sycamore to\n"
	.string "talk about your goals.$"

Amphi_IntroSycamore1_Text_0:
# 139 "data/maps/Amphitheatre/scripts.pory"
	.string "Pr. Sycamore$"

Amphi_IntroSycamore1_Text_1:
# 140 "data/maps/Amphitheatre/scripts.pory"
	.string "Hello everyone.$"

Amphi_IntroSycamore1_Text_2:
# 141 "data/maps/Amphitheatre/scripts.pory"
	.string "Adding to what has been said, the PWC is\n"
	.string "also funding today's ceremony jointly\l"
	.string "with the Copernic Lab.$"

Amphi_IntroSycamore1_Text_3:
# 142 "data/maps/Amphitheatre/scripts.pory"
	.string "You are all about to receive a Pokémon,\n"
	.string "commonly known as a starter from the\l"
	.string "region you wish among a list.$"

Amphi_IntroSycamore1_Text_4:
# 143 "data/maps/Amphitheatre/scripts.pory"
	.string "We hope for three things : See as much\n"
	.string "of you in high ranked official battles,\l"
	.string "receive a lot of data with your\l"
	.string "respective Pokédexes and finally...\l"
	.string "create a lot of memories.$"

Amphi_IntroSycamore1_Text_5:
# 144 "data/maps/Amphitheatre/scripts.pory"
	.string "Thank you for your attention.$"

Amphi_IntroScientist2_Text_0:
# 167 "data/maps/Amphitheatre/scripts.pory"
	.string "We will now begin distributing the\n"
	.string "Pokémon.$"

Amphi_IntroScientist2_Text_1:
# 168 "data/maps/Amphitheatre/scripts.pory"
	.string "Please note, there are exactly as much\n"
	.string "Pokémon than the number of people in\l"
	.string "this room.$"

Amphi_IntroScientist2_Text_2:
# 169 "data/maps/Amphitheatre/scripts.pory"
	.string "That being said, the Pokémon you want\n"
	.string "may not be available by the time it's\l"
	.string "your turn.$"

Amphi_IntroScientist2_Text_3:
# 170 "data/maps/Amphitheatre/scripts.pory"
	.string "Order is based on a random shuffle of\n"
	.string "all the trainer IDs.$"

Amphi_IntroScientist2_Text_4:
# 172 "data/maps/Amphitheatre/scripts.pory"
	.string "When you hear your name, please come to\n"
	.string "the stand.$"

Amphi_IntroScientist2_Text_5:
# 173 "data/maps/Amphitheatre/scripts.pory"
	.string "Let us get started.$"

Amphi_IntroCallingNames_Text_0:
# 188 "data/maps/Amphitheatre/scripts.pory"
	.string "Trainer ID : 290620.$"

Amphi_IntroCallingNames_Text_1:
# 199 "data/maps/Amphitheatre/scripts.pory"
	.string "Oh nice, I'm first! I get to pick\n"
	.string "whatever Pokémon I want.$"

Amphi_IntroCallingNames_Text_2:
# 212 "data/maps/Amphitheatre/scripts.pory"
	.string "From what region you want it?$"

Amphi_IntroCallingNames_Text_3:
# 215 "data/maps/Amphitheatre/scripts.pory"
	.string "From Hoenn! I want a Torchic.$"

Amphi_IntroCallingNames_Text_4:
# 224 "data/maps/Amphitheatre/scripts.pory"
	.string "Oh boy.. I sure hope we're not among the\n"
	.string "last ones.$"

Amphi_IntroCallingNames_Text_5:
# 225 "data/maps/Amphitheatre/scripts.pory"
	.string "All the best Pokémon will be picked by\n"
	.string "then.$"

Amphi_IntroCallingNames_Text_6:
# 235 "data/maps/Amphitheatre/scripts.pory"
	.string "A lot of time has passed. Everyone got\n"
	.string "their Pokémon except for two people.$"

Amphi_CallingTrainer_Text_0:
# 246 "data/maps/Amphitheatre/scripts.pory"
	.string "Trainer ID : {STR_VAR_1}. Name :\n"
	.string "{PLAYER}.$"

Amphi_CallingTrainer_Text_1:
# 270 "data/maps/Amphitheatre/scripts.pory"
	.string "You are in luck. Someone did not show\n"
	.string "up. So there are three Pokémon\l"
	.string "remaining for you to choose from.$"

Amphi_CallingTrainer_Text_2:
# 281 "data/maps/Amphitheatre/scripts.pory"
	.string "Which are...$"

Amphi_ChooseSnivy_Text_0:
# 337 "data/maps/Amphitheatre/scripts.pory"
	.string "Would you like to choose Snivy?$"

Amphi_ChooseChimchar_Text_0:
# 368 "data/maps/Amphitheatre/scripts.pory"
	.string "Would you like to choose Chimchar?$"

Amphi_ChooseSobble_Text_0:
# 398 "data/maps/Amphitheatre/scripts.pory"
	.string "Would you like to choose Sobble?$"

Amphi_StarterNickname_Text_0:
# 424 "data/maps/Amphitheatre/scripts.pory"
	.string "Would you like to give {STR_VAR_1} a\n"
	.string "nickname?$"

Amphi_StarterNickname_Text_1:
# 456 "data/maps/Amphitheatre/scripts.pory"
	.string "Now that you have your partner, here is\n"
	.string "a Pokédex. We hope that you fill as many\l"
	.string "pages as possible. That data will be\l"
	.string "valuable for our researches.$"

Amphi_Policeman_Text_0:
# 470 "data/maps/Amphitheatre/scripts.pory"
	.string "Dummy text.$"

Arr2_ForceChooseStarter_Text_0:
# 480 "data/maps/Amphitheatre/scripts.pory"
	.string "Where are you going?$"
