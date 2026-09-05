OldaleTown_MapScripts::
	.byte 0


ManTest::
# 6 "data/maps/OldaleTown/scripts.pory"
	lock
# 7 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 9 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_0
# 12 "data/maps/OldaleTown/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, ManTest_Text_1, ManTest_Text_2, ManTest_Text_3, ManTest_Text_4, ManTest_Text_5
# 13 "data/maps/OldaleTown/scripts.pory"
	switch VAR_RESULT
# 14 "data/maps/OldaleTown/scripts.pory"
	case 0, ManTest_3
# 16 "data/maps/OldaleTown/scripts.pory"
	case 1, ManTest_4
# 18 "data/maps/OldaleTown/scripts.pory"
	case 2, ManTest_5
# 24 "data/maps/OldaleTown/scripts.pory"
	case 3, ManTest_6
ManTest_1:
# 32 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end

ManTest_3:
# 15 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_6
	goto ManTest_1

ManTest_4:
# 17 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_7
	goto ManTest_1

ManTest_5:
# 19 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8004, 5
# 20 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
# 21 "data/maps/OldaleTown/scripts.pory"
	delay 120
# 22 "data/maps/OldaleTown/scripts.pory"
	waitbuttonpress
# 23 "data/maps/OldaleTown/scripts.pory"
	callnative Script_HideRankDisplay
	goto ManTest_1

ManTest_6:
# 25 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8004, -5
# 26 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
# 27 "data/maps/OldaleTown/scripts.pory"
	delay 120
# 28 "data/maps/OldaleTown/scripts.pory"
	waitbuttonpress
# 29 "data/maps/OldaleTown/scripts.pory"
	callnative Script_HideRankDisplay
	goto ManTest_1


BattleZone1_Matchmaking::
# 37 "data/maps/OldaleTown/scripts.pory"
	lock
# 38 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 40 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 1
# 42 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_0, MSGBOX_YESNO
# 43 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 45 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleZone1_Matchmaking_2
# 49 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 52 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_1
# 55 "data/maps/OldaleTown/scripts.pory"
	callnative Script_SetupRandomOpponent
# 57 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_2
# 64 "data/maps/OldaleTown/scripts.pory"
	special SavePlayerParty
# 65 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8006, 1
# 66 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8005, 3
# 68 "data/maps/OldaleTown/scripts.pory"
	special ChoosePartyForBattleFrontier
# 75 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleZone1_Matchmaking_Movement_0
# 80 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 83 "data/maps/OldaleTown/scripts.pory"
	setflag 0x4D
# 84 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 86 "data/maps/OldaleTown/scripts.pory"
	special HealPlayerParty
# 92 "data/maps/OldaleTown/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 93 "data/maps/OldaleTown/scripts.pory"
	frontier_setpartyorder 3
# 96 "data/maps/OldaleTown/scripts.pory"
	callnative Script_LoadOpponentSpeech
# 97 "data/maps/OldaleTown/scripts.pory"
	setspeaker BattleZone1_Matchmaking_Text_3
# 98 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_4
# 100 "data/maps/OldaleTown/scripts.pory"
	trainerbattle_no_intro TRAINER_NONE, BattleZone1_Matchmaking_Text_5
# 104 "data/maps/OldaleTown/scripts.pory"
	special HealPlayerParty
# 107 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 1
# 110 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleZone1_Matchmaking_5
# 117 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_7
# 119 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, -5
BattleZone1_Matchmaking_4:
# 122 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
# 123 "data/maps/OldaleTown/scripts.pory"
	delay 120
# 124 "data/maps/OldaleTown/scripts.pory"
	waitbuttonpress
# 125 "data/maps/OldaleTown/scripts.pory"
	callnative Script_HideRankDisplay
# 127 "data/maps/OldaleTown/scripts.pory"
	special LoadPlayerParty
# 129 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 130 "data/maps/OldaleTown/scripts.pory"
	clearflag 0x4E
# 131 "data/maps/OldaleTown/scripts.pory"
	clearflag 0x4D
# 132 "data/maps/OldaleTown/scripts.pory"
	release
	end

BattleZone1_Matchmaking_2:
	return

BattleZone1_Matchmaking_5:
# 111 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_6
# 113 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, 5
	goto BattleZone1_Matchmaking_4


ScraftyBeers_Sign::
# 153 "data/maps/OldaleTown/scripts.pory"
	msgbox ScraftyBeers_Sign_Text_0, MSGBOX_SIGN
# 154 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end


WineWhip_Sign::
# 159 "data/maps/OldaleTown/scripts.pory"
	msgbox WineWhip_Sign_Text_0, MSGBOX_SIGN
# 160 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end


TrainerClub_Sign::
# 166 "data/maps/OldaleTown/scripts.pory"
	msgbox TrainerClub_Sign_Text_0, MSGBOX_SIGN
# 167 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end


TestGiveTM::
# 175 "data/maps/OldaleTown/scripts.pory"
	msgbox TestGiveTM_Text_0
# 176 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_TM_AERIAL_ACE
# 177 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end


Arr2_Fisherman::
# 184 "data/maps/OldaleTown/scripts.pory"
	lock
# 186 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_0
# 188 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_1
# 190 "data/maps/OldaleTown/scripts.pory"
	getpartysize
# 191 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt Arr2_Fisherman_2
# 198 "data/maps/OldaleTown/scripts.pory"
	showobjectat 6, MAP_OLDALE_TOWN
# 199 "data/maps/OldaleTown/scripts.pory"
	applymovement 6, Arr2_Fisherman_Movement_0
# 201 "data/maps/OldaleTown/scripts.pory"
	applymovement 7, Arr2_Fisherman_Movement_1
# 206 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_3
# 207 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_4
# 209 "data/maps/OldaleTown/scripts.pory"
	showobjectat 8, MAP_OLDALE_TOWN
# 211 "data/maps/OldaleTown/scripts.pory"
	applymovement 7, Arr2_Fisherman_Movement_2
# 214 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 216 "data/maps/OldaleTown/scripts.pory"
	applymovement 8, Arr2_Fisherman_Movement_3
# 219 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 223 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_5
# 225 "data/maps/OldaleTown/scripts.pory"
	applymovement 7, Arr2_Fisherman_Movement_4
# 231 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 233 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_6
# 235 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_UNUSED_0x1DE
# 236 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_UNUSED_0x1DF
# 241 "data/maps/OldaleTown/scripts.pory"
	clearflag FLAG_UNUSED_0x1DE
# 242 "data/maps/OldaleTown/scripts.pory"
	clearflag FLAG_UNUSED_0x1DF
# 244 "data/maps/OldaleTown/scripts.pory"
	removeobject 6, MAP_OLDALE_TOWN
# 245 "data/maps/OldaleTown/scripts.pory"
	removeobject 8, MAP_OLDALE_TOWN
# 247 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 248 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_7
# 250 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_OLD_ROD
# 252 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 254 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 255 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_Fisherman_Movement_5
# 259 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 261 "data/maps/OldaleTown/scripts.pory"
	applymovement 7, Arr2_Fisherman_Movement_6
# 267 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 270 "data/maps/OldaleTown/scripts.pory"
	removeobject 7, MAP_OLDALE_TOWN
# 271 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
# 274 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_Fisherman_2:
# 192 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_2
# 193 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarTradeMagikarp::
# 281 "data/maps/OldaleTown/scripts.pory"
	lock
# 282 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 284 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_BarTradeMagikarp_Text_0
# 286 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, Arr2_BarTradeMagikarp_2
# 293 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarTradeMagikarp_Text_2
# 294 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarTradeMagikarp_Text_3
# 296 "data/maps/OldaleTown/scripts.pory"
	ingame_trade INGAME_TRADE_SEEDOT, Arr2_BarTradeMagikarp_Text_4, Arr2_BarTradeMagikarp_Text_5, Arr2_BarTradeMagikarp_Text_6, Arr2_BarTradeMagikarp_Text_7
# 297 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 299 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
# 301 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarTradeMagikarp_2:
# 288 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarTradeMagikarp_Text_1
# 289 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarDrinkerMachamp::
# 306 "data/maps/OldaleTown/scripts.pory"
	lock
# 307 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 309 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarDrinkerMachamp_Text_0
# 310 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarDrinkerMachamp_Text_1
# 312 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarBeerWaiter::
# 317 "data/maps/OldaleTown/scripts.pory"
	lock
# 318 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 319 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_BarBeerWaiter_Text_0
# 320 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_1
# 321 "data/maps/OldaleTown/scripts.pory"
	goto_if_set 0x4F, Arr2_BarBeerWaiter_2
# 327 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 328 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_3
# 329 "data/maps/OldaleTown/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, Arr2_BarBeerWaiter_Text_4, Arr2_BarBeerWaiter_Text_5, Arr2_BarBeerWaiter_Text_6, Arr2_BarBeerWaiter_Text_7, Arr2_BarBeerWaiter_Text_8, Arr2_BarBeerWaiter_Text_9, ManTest_Text_5
# 331 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq Arr2_BarBeerWaiter_5
# 336 "data/maps/OldaleTown/scripts.pory"
	copyvar VAR_0x8002, VAR_RESULT
# 337 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_10
# 340 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8001, 10
# 341 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8003, 5
# 343 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_11
# 344 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 348 "data/maps/OldaleTown/scripts.pory"
	opendoor 84, 12
# 349 "data/maps/OldaleTown/scripts.pory"
	waitdooranim
# 351 "data/maps/OldaleTown/scripts.pory"
	applymovement 11, Arr2_BarBeerWaiter_Movement_0
# 355 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 358 "data/maps/OldaleTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 359 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_1, 13
	goto_if_eq Arr2_BarBeerWaiter_8
Arr2_BarBeerWaiter_7:
Arr2_BarBeerWaiter_11:
# 366 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_0, 83
	goto_if_gt Arr2_BarBeerWaiter_12
# 376 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Arr2_BarBeerWaiter_Movement_3
# 382 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_BarBeerWaiter_Movement_4
# 386 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 389 "data/maps/OldaleTown/scripts.pory"
	delay 120
# 392 "data/maps/OldaleTown/scripts.pory"
	applymovement 11, Arr2_BarBeerWaiter_Movement_5
# 398 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 404 "data/maps/OldaleTown/scripts.pory"
	closedoor 84, 12
# 405 "data/maps/OldaleTown/scripts.pory"
	waitdooranim
# 407 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_BarBeerWaiter_Text_0
# 408 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_12, MSGBOX_YESNO
# 409 "data/maps/OldaleTown/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 410 "data/maps/OldaleTown/scripts.pory"
	checkmoney 500
# 411 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 413 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Arr2_BarBeerWaiter_17
Arr2_BarBeerWaiter_16:
# 455 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_23
# 457 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 459 "data/maps/OldaleTown/scripts.pory"
	applymovement 11, Arr2_BarBeerWaiter_Movement_6
# 464 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 466 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 469 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarBeerWaiter_2:
# 322 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_2
# 323 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarBeerWaiter_5:
# 332 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarBeerWaiter_8:
# 360 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_BarBeerWaiter_Movement_1
# 363 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
	goto Arr2_BarBeerWaiter_7

Arr2_BarBeerWaiter_12:
# 367 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_BarBeerWaiter_Movement_2
# 370 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 371 "data/maps/OldaleTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto Arr2_BarBeerWaiter_11

Arr2_BarBeerWaiter_14:
# 474 "data/maps/OldaleTown/scripts.pory"
	applymovement 11, Arr2_BarBeerWaiter_Movement_6
# 479 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 481 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8014, 1
# 483 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Arr2_BarBeerWaiter_Movement_7
# 487 "data/maps/OldaleTown/scripts.pory"
	waitmovement
# 489 "data/maps/OldaleTown/scripts.pory"
	bufferleadmonspeciesname 0
# 491 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_24
# 493 "data/maps/OldaleTown/scripts.pory"
	switch VAR_0x8002
# 494 "data/maps/OldaleTown/scripts.pory"
	case 1, Arr2_BarBeerWaiter_22
# 496 "data/maps/OldaleTown/scripts.pory"
	case 2, Arr2_BarBeerWaiter_23
Arr2_BarBeerWaiter_20:
# 500 "data/maps/OldaleTown/scripts.pory"
	callnative Script_FriendshipAndStats
# 501 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_27
# 503 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 506 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8014, 0
# 509 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 511 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarBeerWaiter_15:
# 415 "data/maps/OldaleTown/scripts.pory"
	showmoneybox 18, 0
# 416 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_13
# 417 "data/maps/OldaleTown/scripts.pory"
	removemoney 500
# 418 "data/maps/OldaleTown/scripts.pory"
	updatemoneybox
# 419 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_14
# 420 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
# 422 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_15
# 423 "data/maps/OldaleTown/scripts.pory"
	showmoneybox 18, 0
# 424 "data/maps/OldaleTown/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Arr2_BarBeerWaiter_Text_16, Arr2_BarBeerWaiter_Text_17, Arr2_BarBeerWaiter_Text_18
# 426 "data/maps/OldaleTown/scripts.pory"
	switch VAR_RESULT
# 427 "data/maps/OldaleTown/scripts.pory"
	case 0, Arr2_BarBeerWaiter_26
# 438 "data/maps/OldaleTown/scripts.pory"
	case 1, Arr2_BarBeerWaiter_27
# 448 "data/maps/OldaleTown/scripts.pory"
	case 2, Arr2_BarBeerWaiter_28
Arr2_BarBeerWaiter_24:
# 452 "data/maps/OldaleTown/scripts.pory"
	closemessage
	goto Arr2_BarBeerWaiter_14

Arr2_BarBeerWaiter_17:
# 413 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_1, 0
	goto_if_ne Arr2_BarBeerWaiter_15
	goto Arr2_BarBeerWaiter_16

Arr2_BarBeerWaiter_22:
# 495 "data/maps/OldaleTown/scripts.pory"
	bufferstring STR_VAR_1, Arr2_BarBeerWaiter_Text_25
	goto Arr2_BarBeerWaiter_20

Arr2_BarBeerWaiter_23:
# 497 "data/maps/OldaleTown/scripts.pory"
	bufferstring STR_VAR_1, Arr2_BarBeerWaiter_Text_26
	goto Arr2_BarBeerWaiter_20

Arr2_BarBeerWaiter_26:
# 428 "data/maps/OldaleTown/scripts.pory"
	checkmoney 500
# 429 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Arr2_BarBeerWaiter_30
# 435 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_20
Arr2_BarBeerWaiter_29:
# 437 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
	goto Arr2_BarBeerWaiter_24

Arr2_BarBeerWaiter_27:
# 439 "data/maps/OldaleTown/scripts.pory"
	checkmoney 100
# 440 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Arr2_BarBeerWaiter_34
# 445 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_20
Arr2_BarBeerWaiter_33:
# 447 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
	goto Arr2_BarBeerWaiter_24

Arr2_BarBeerWaiter_28:
# 449 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
# 450 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_22
	goto Arr2_BarBeerWaiter_24

Arr2_BarBeerWaiter_30:
# 430 "data/maps/OldaleTown/scripts.pory"
	removemoney 500
# 431 "data/maps/OldaleTown/scripts.pory"
	updatemoneybox
# 433 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_19
	goto Arr2_BarBeerWaiter_29

Arr2_BarBeerWaiter_34:
# 441 "data/maps/OldaleTown/scripts.pory"
	removemoney 100
# 442 "data/maps/OldaleTown/scripts.pory"
	updatemoneybox
# 443 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_21
	goto Arr2_BarBeerWaiter_33


Arr2_BarWineWaiter::
# 516 "data/maps/OldaleTown/scripts.pory"
	lock
# 517 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 518 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_BarBeerWaiter_Text_0
# 519 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarWineWaiter_Text_0
# 520 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarWineWaiter_Text_1
# 521 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarOldLady::
# 527 "data/maps/OldaleTown/scripts.pory"
	lock
# 528 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarOldLady_Text_0
# 529 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarGentleman::
# 534 "data/maps/OldaleTown/scripts.pory"
	lock
# 535 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarGentleman_Text_0
# 536 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarLady::
# 541 "data/maps/OldaleTown/scripts.pory"
	lock
# 542 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 544 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_SHOCK_WAVE, Arr2_BarLady_2
# 551 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_1
# 552 "data/maps/OldaleTown/scripts.pory"
	applymovement 16, Arr2_BarLady_Movement_0
# 557 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 559 "data/maps/OldaleTown/scripts.pory"
	special SpawnCameraObject
# 560 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_1
# 561 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_2
# 562 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_2
# 563 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_3, MSGBOX_YESNO
# 564 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Arr2_BarLady_5
Arr2_BarLady_4:
# 597 "data/maps/OldaleTown/scripts.pory"
	special RemoveCameraObject
# 598 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarLady_2:
# 546 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_0
# 547 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarLady_5:
# 565 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_4
# 567 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_5
# 569 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_6
# 571 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_1
# 572 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 573 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_7
# 574 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_2
# 576 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_8
# 578 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_1
# 579 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 581 "data/maps/OldaleTown/scripts.pory"
	applymovement 16, Arr2_BarLady_Movement_3
# 586 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_9
# 588 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_2
# 589 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 591 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_10
# 592 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_11
# 593 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_TM_SHOCK_WAVE
# 594 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	goto Arr2_BarLady_4


# 75 "data/maps/OldaleTown/scripts.pory"
BattleZone1_Matchmaking_Movement_0:
# 76 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 76 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 77 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 77 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 78 "data/maps/OldaleTown/scripts.pory"
	face_down
	step_end

# 199 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_0:
# 199 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
# 199 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
# 199 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
	step_end

# 201 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_1:
# 201 "data/maps/OldaleTown/scripts.pory"
	face_right
	step_end

# 211 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_2:
# 212 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
	step_end

# 216 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_3:
# 217 "data/maps/OldaleTown/scripts.pory"
	face_right
# 218 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 218 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 218 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
	step_end

# 225 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_4:
# 226 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 227 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
# 228 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 229 "data/maps/OldaleTown/scripts.pory"
	face_up
	step_end

# 255 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_5:
# 256 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 257 "data/maps/OldaleTown/scripts.pory"
	face_down
	step_end

# 261 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_6:
# 262 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 263 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 263 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 264 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 264 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 264 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 264 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 264 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 264 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 264 "data/maps/OldaleTown/scripts.pory"
	walk_up
	step_end

# 351 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_0:
# 352 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 353 "data/maps/OldaleTown/scripts.pory"
	set_invisible
	step_end

# 360 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_1:
# 361 "data/maps/OldaleTown/scripts.pory"
	walk_down
	step_end

# 367 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_2:
# 368 "data/maps/OldaleTown/scripts.pory"
	walk_left
	step_end

# 376 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_3:
# 377 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 377 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 378 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 378 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 379 "data/maps/OldaleTown/scripts.pory"
	face_right
	step_end

# 382 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_4:
# 383 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 384 "data/maps/OldaleTown/scripts.pory"
	face_left
	step_end

# 392 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_5:
# 393 "data/maps/OldaleTown/scripts.pory"
	set_visible
# 394 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 395 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 395 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 396 "data/maps/OldaleTown/scripts.pory"
	walk_down
	step_end

# 459 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_6:
# 460 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 461 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 461 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 462 "data/maps/OldaleTown/scripts.pory"
	face_down
	step_end

# 483 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_7:
# 484 "data/maps/OldaleTown/scripts.pory"
	emote_heart
# 485 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 485 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
	step_end

# 552 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_0:
# 553 "data/maps/OldaleTown/scripts.pory"
	emote_exclamation_mark
# 554 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 555 "data/maps/OldaleTown/scripts.pory"
	face_left
	step_end

# 560 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_1:
# 560 "data/maps/OldaleTown/scripts.pory"
	walk_fast_left
# 560 "data/maps/OldaleTown/scripts.pory"
	walk_fast_left
	step_end

# 562 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_2:
# 562 "data/maps/OldaleTown/scripts.pory"
	walk_fast_right
# 562 "data/maps/OldaleTown/scripts.pory"
	walk_fast_right
	step_end

# 581 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_3:
# 582 "data/maps/OldaleTown/scripts.pory"
	face_right
# 583 "data/maps/OldaleTown/scripts.pory"
	emote_heart
	step_end

ManTest_Text_0:
# 9 "data/maps/OldaleTown/scripts.pory"
	.string "Welcome to the Battle Zone! Do you need\n"
	.string "any explanation ?$"

ManTest_Text_1:
# 12 "data/maps/OldaleTown/scripts.pory"
	.string "What are ranks$"

ManTest_Text_2:
# 12 "data/maps/OldaleTown/scripts.pory"
	.string "What is this place$"

ManTest_Text_3:
# 12 "data/maps/OldaleTown/scripts.pory"
	.string "Add Points$"

ManTest_Text_4:
# 12 "data/maps/OldaleTown/scripts.pory"
	.string "Remove Points$"

ManTest_Text_5:
# 12 "data/maps/OldaleTown/scripts.pory"
	.string "No thanks$"

ManTest_Text_6:
# 15 "data/maps/OldaleTown/scripts.pory"
	.string "There are 5 ranks in the PWC.$"

ManTest_Text_7:
# 17 "data/maps/OldaleTown/scripts.pory"
	.string "This place is what we call a Battle Zone.$"

BattleZone1_Matchmaking_Text_0:
# 42 "data/maps/OldaleTown/scripts.pory"
	.string "Do you want to find an opponent?$"

BattleZone1_Matchmaking_Text_1:
# 52 "data/maps/OldaleTown/scripts.pory"
	.string "Matchmaking in progress... {PAUSE 10} ... {PAUSE 10} ...$"

BattleZone1_Matchmaking_Text_2:
# 57 "data/maps/OldaleTown/scripts.pory"
	.string "An opponent has been found!\nGet ready to battle {STR_VAR_1}!$"

BattleZone1_Matchmaking_Text_3:
# 97 "data/maps/OldaleTown/scripts.pory"
	.string "{STR_VAR_1}$"

BattleZone1_Matchmaking_Text_4:
# 98 "data/maps/OldaleTown/scripts.pory"
	.string "{STR_VAR_2}$"

BattleZone1_Matchmaking_Text_5:
# 100 "data/maps/OldaleTown/scripts.pory"
	.string "{STR_VAR_3}$"

BattleZone1_Matchmaking_Text_6:
# 111 "data/maps/OldaleTown/scripts.pory"
	.string "Congratulations on your victory! Your\n"
	.string "rank is being updated...$"

BattleZone1_Matchmaking_Text_7:
# 117 "data/maps/OldaleTown/scripts.pory"
	.string "You lost your battle. Your rank is being\n"
	.string "updated...$"

ScraftyBeers_Sign_Text_0:
# 153 "data/maps/OldaleTown/scripts.pory"
	.string "Scrafty Beers.\n"
	.string "Independent brewery.\p"
	.string "$"

WineWhip_Sign_Text_0:
# 159 "data/maps/OldaleTown/scripts.pory"
	.string "Wine Whip.\n"
	.string "Independent wine bar.\p"
	.string "$"

TrainerClub_Sign_Text_0:
# 166 "data/maps/OldaleTown/scripts.pory"
	.string "Trainer Club\n"
	.string "\p"
	.string "$"

TestGiveTM_Text_0:
# 175 "data/maps/OldaleTown/scripts.pory"
	.string "Here is a TM just for you.$"

Arr2_Fisherman_Text_0:
# 186 "data/maps/OldaleTown/scripts.pory"
	.string "Let's get fishing, I am not doing to find\n"
	.string "the golden Magikarp just by staring at\l"
	.string "the water$"

Arr2_Fisherman_Text_1:
# 188 "data/maps/OldaleTown/scripts.pory"
	.string "... ... ...$"

Arr2_Fisherman_Text_2:
# 192 "data/maps/OldaleTown/scripts.pory"
	.string "Not even a nibble...$"

Arr2_Fisherman_Text_3:
# 206 "data/maps/OldaleTown/scripts.pory"
	.string "Oh good lord! He seems angry!$"

Arr2_Fisherman_Text_4:
# 207 "data/maps/OldaleTown/scripts.pory"
	.string "No, don't attack me! Please, I won't fish\n"
	.string "here anymore, I promise!$"

Arr2_Fisherman_Text_5:
# 223 "data/maps/OldaleTown/scripts.pory"
	.string "Oh no, another one?!$"

Arr2_Fisherman_Text_6:
# 233 "data/maps/OldaleTown/scripts.pory"
	.string "You, please help me!$"

Arr2_Fisherman_Text_7:
# 248 "data/maps/OldaleTown/scripts.pory"
	.string "Oh! You saved me! I wonder what could\n"
	.string "have happened if you weren't here. I\l"
	.string "don't want to fish anymore. I'll find\l"
	.string "myself another passion. Please, have\l"
	.string "this, I wont be using it anymore.$"

Arr2_BarTradeMagikarp_Text_0:
# 284 "data/maps/OldaleTown/scripts.pory"
	.string "Marcel$"

Arr2_BarTradeMagikarp_Text_1:
# 288 "data/maps/OldaleTown/scripts.pory"
	.string "Your Magikarp is so great!$"

Arr2_BarTradeMagikarp_Text_2:
# 293 "data/maps/OldaleTown/scripts.pory"
	.string "I've always dreamed of having a\n"
	.string "Gyarados. It should be easy : Magikarp\l"
	.string "are everywhere, but not for me. I'm so\l"
	.string "unlucky that one never bites my line.$"

Arr2_BarTradeMagikarp_Text_3:
# 294 "data/maps/OldaleTown/scripts.pory"
	.string "All I have is this stupid Luvdisc my ex\n"
	.string "gave me. I don't even want it... it just\l"
	.string "reminds me of her.$"

Arr2_BarTradeMagikarp_Text_4:
# 296 "data/maps/OldaleTown/scripts.pory"
	.string "Would you trade a Magikarp for a\n"
	.string "Luvdisc?$"

Arr2_BarTradeMagikarp_Text_5:
# 296 "data/maps/OldaleTown/scripts.pory"
	.string "Arghhh... No luck even with trades.$"

Arr2_BarTradeMagikarp_Text_6:
# 296 "data/maps/OldaleTown/scripts.pory"
	.string "That's not a Magikarp.$"

Arr2_BarTradeMagikarp_Text_7:
# 296 "data/maps/OldaleTown/scripts.pory"
	.string "Take care of it.$"

Arr2_BarDrinkerMachamp_Text_0:
# 309 "data/maps/OldaleTown/scripts.pory"
	.string "Oh... I always drink too much. What?\n"
	.string "You're wondering if I'm scared of not\l"
	.string "making it home? No, not at all.$"

Arr2_BarDrinkerMachamp_Text_1:
# 310 "data/maps/OldaleTown/scripts.pory"
	.string "My Machamp always carries me with his\n"
	.string "four arms when I've had too much.$"

Arr2_BarBeerWaiter_Text_0:
# 319 "data/maps/OldaleTown/scripts.pory"
	.string "Waiter$"

Arr2_BarBeerWaiter_Text_1:
# 320 "data/maps/OldaleTown/scripts.pory"
	.string "Hello and welcome to {COLOR BLUE}{SHADOW LIGHT_BLUE}Scrafty Beers.$"

Arr2_BarBeerWaiter_Text_2:
# 322 "data/maps/OldaleTown/scripts.pory"
	.string "Come with a Pokémon, it will be better\n"
	.string "trust me.$"

Arr2_BarBeerWaiter_Text_3:
# 328 "data/maps/OldaleTown/scripts.pory"
	.string "What will it be? Standard prices,\n"
	.string "everything comes at ¥500.$"

Arr2_BarBeerWaiter_Text_4:
# 329 "data/maps/OldaleTown/scripts.pory"
	.string "Cider$"

Arr2_BarBeerWaiter_Text_5:
# 329 "data/maps/OldaleTown/scripts.pory"
	.string "Lager Beer$"

Arr2_BarBeerWaiter_Text_6:
# 329 "data/maps/OldaleTown/scripts.pory"
	.string "Pale Ale Beer$"

Arr2_BarBeerWaiter_Text_7:
# 329 "data/maps/OldaleTown/scripts.pory"
	.string "Red Wine$"

Arr2_BarBeerWaiter_Text_8:
# 329 "data/maps/OldaleTown/scripts.pory"
	.string "White Wine$"

Arr2_BarBeerWaiter_Text_9:
# 329 "data/maps/OldaleTown/scripts.pory"
	.string "Gin Tonic$"

Arr2_BarBeerWaiter_Text_10:
# 337 "data/maps/OldaleTown/scripts.pory"
	.string "Great choice!$"

Arr2_BarBeerWaiter_Text_11:
# 343 "data/maps/OldaleTown/scripts.pory"
	.string "Please, take a seat.$"

Arr2_BarBeerWaiter_Text_12:
# 408 "data/maps/OldaleTown/scripts.pory"
	.string "That will be ¥500 please.$"

Arr2_BarBeerWaiter_Text_13:
# 416 "data/maps/OldaleTown/scripts.pory"
	.string "Just put your card over here...$"

Arr2_BarBeerWaiter_Text_14:
# 419 "data/maps/OldaleTown/scripts.pory"
	.string "Transaction done. Tips are welcome if\n"
	.string "you'd like.$"

Arr2_BarBeerWaiter_Text_15:
# 422 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}Give a tip ?$"

Arr2_BarBeerWaiter_Text_16:
# 424 "data/maps/OldaleTown/scripts.pory"
	.string "500$"

Arr2_BarBeerWaiter_Text_17:
# 424 "data/maps/OldaleTown/scripts.pory"
	.string "100$"

Arr2_BarBeerWaiter_Text_18:
# 424 "data/maps/OldaleTown/scripts.pory"
	.string "0$"

Arr2_BarBeerWaiter_Text_19:
# 433 "data/maps/OldaleTown/scripts.pory"
	.string "Enjoy your drink!$"

Arr2_BarBeerWaiter_Text_20:
# 435 "data/maps/OldaleTown/scripts.pory"
	.string "Big talks for empty pockets.$"

Arr2_BarBeerWaiter_Text_21:
# 443 "data/maps/OldaleTown/scripts.pory"
	.string "Thanks!$"

Arr2_BarBeerWaiter_Text_22:
# 450 "data/maps/OldaleTown/scripts.pory"
	.string "...$"

Arr2_BarBeerWaiter_Text_23:
# 455 "data/maps/OldaleTown/scripts.pory"
	.string "Wait, you can't pay for the drinks? Then\n"
	.string "these are coming right back with me!$"

Arr2_BarBeerWaiter_Text_24:
# 491 "data/maps/OldaleTown/scripts.pory"
	.string "{STR_VAR_1} had a sip of your drink.\n"
	.string "It seems more attached to you.$"

Arr2_BarBeerWaiter_Text_25:
# 495 "data/maps/OldaleTown/scripts.pory"
	.string "Attack$"

Arr2_BarBeerWaiter_Text_26:
# 497 "data/maps/OldaleTown/scripts.pory"
	.string "Defense$"

Arr2_BarBeerWaiter_Text_27:
# 501 "data/maps/OldaleTown/scripts.pory"
	.string "Its {STR_VAR_1} was raised a little.$"

Arr2_BarWineWaiter_Text_0:
# 519 "data/maps/OldaleTown/scripts.pory"
	.string "Hello and welcome to {COLOR BLUE}{SHADOW LIGHT_BLUE}Wine Whip.$"

Arr2_BarWineWaiter_Text_1:
# 520 "data/maps/OldaleTown/scripts.pory"
	.string "I am sorry but all our tables are full\n"
	.string "today. Our neighbors are selling wine\l"
	.string "too if you need, maybe as good as ours\l"
	.string "but worth a try.$"

Arr2_BarOldLady_Text_0:
# 528 "data/maps/OldaleTown/scripts.pory"
	.string "Hello and welcome to$"

Arr2_BarGentleman_Text_0:
# 535 "data/maps/OldaleTown/scripts.pory"
	.string "I have been visiting this bar since I\n"
	.string "was about as young as you. The taste\l"
	.string "brings up so much memories...$"

Arr2_BarLady_Text_0:
# 546 "data/maps/OldaleTown/scripts.pory"
	.string "I am glad I was in the bar that day. My\n"
	.string "life would have been very different\l"
	.string "otherwise.$"

Arr2_BarLady_Text_1:
# 551 "data/maps/OldaleTown/scripts.pory"
	.string "You know, me and my husband met in this\n"
	.string "very bar. We met under very special\l"
	.string "circumstances.$"

Arr2_BarLady_Text_2:
# 561 "data/maps/OldaleTown/scripts.pory"
	.string "No! Don't tell him!$"

Arr2_BarLady_Text_3:
# 563 "data/maps/OldaleTown/scripts.pory"
	.string "Do you want to know ?$"

Arr2_BarLady_Text_4:
# 565 "data/maps/OldaleTown/scripts.pory"
	.string "Well, he had too much wine that day. He\n"
	.string "was so drunk people were gathering\l"
	.string "around him thinking he was dead.$"

Arr2_BarLady_Text_5:
# 567 "data/maps/OldaleTown/scripts.pory"
	.string "Then I came, ordered by Pokémon to use\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Shock Wave{COLOR DARK_GRAY}{COLOR LIGHT_GRAY}, and he woke up abruptly.$"

Arr2_BarLady_Text_6:
# 569 "data/maps/OldaleTown/scripts.pory"
	.string "He looked at me and said, 'Are you an\n"
	.string "angel?' I never let him live that down.$"

Arr2_BarLady_Text_7:
# 573 "data/maps/OldaleTown/scripts.pory"
	.string "I am so embarassed!$"

Arr2_BarLady_Text_8:
# 576 "data/maps/OldaleTown/scripts.pory"
	.string "And well... here we are, years later!$"

Arr2_BarLady_Text_9:
# 586 "data/maps/OldaleTown/scripts.pory"
	.string "I am glad a met you.$"

Arr2_BarLady_Text_10:
# 591 "data/maps/OldaleTown/scripts.pory"
	.string "Me too... Me too...$"

Arr2_BarLady_Text_11:
# 592 "data/maps/OldaleTown/scripts.pory"
	.string "Oh. I am rambling again. Here's a little\n"
	.string "thank you for listening to me.$"
