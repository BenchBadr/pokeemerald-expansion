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
# 51 "data/maps/OldaleTown/scripts.pory"
	playSE SE_DEX_SEARCH
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
	playSE SE_PIN
# 202 "data/maps/OldaleTown/scripts.pory"
	applymovement 7, Arr2_Fisherman_Movement_1
# 207 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_3
# 208 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_4
# 210 "data/maps/OldaleTown/scripts.pory"
	showobjectat 8, MAP_OLDALE_TOWN
# 212 "data/maps/OldaleTown/scripts.pory"
	applymovement 7, Arr2_Fisherman_Movement_2
# 215 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 217 "data/maps/OldaleTown/scripts.pory"
	playSE SE_PIN
# 218 "data/maps/OldaleTown/scripts.pory"
	applymovement 8, Arr2_Fisherman_Movement_3
# 222 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 226 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_5
# 228 "data/maps/OldaleTown/scripts.pory"
	applymovement 7, Arr2_Fisherman_Movement_4
# 234 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 236 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_6
# 238 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_UNUSED_0x1DE
# 239 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_UNUSED_0x1DF
# 241 "data/maps/OldaleTown/scripts.pory"
	setwildbattle SPECIES_MAGIKARP, 4, ITEM_NONE, SPECIES_MAGIKARP, 3, ITEM_NONE
# 242 "data/maps/OldaleTown/scripts.pory"
	dowildbattle
# 244 "data/maps/OldaleTown/scripts.pory"
	clearflag FLAG_UNUSED_0x1DE
# 245 "data/maps/OldaleTown/scripts.pory"
	clearflag FLAG_UNUSED_0x1DF
# 247 "data/maps/OldaleTown/scripts.pory"
	removeobject 6, MAP_OLDALE_TOWN
# 248 "data/maps/OldaleTown/scripts.pory"
	removeobject 8, MAP_OLDALE_TOWN
# 250 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 251 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_7
# 253 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_OLD_ROD
# 255 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 257 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 258 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_Fisherman_Movement_5
# 262 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 264 "data/maps/OldaleTown/scripts.pory"
	applymovement 7, Arr2_Fisherman_Movement_6
# 270 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 273 "data/maps/OldaleTown/scripts.pory"
	removeobject 7, MAP_OLDALE_TOWN
# 274 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
# 277 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_Fisherman_2:
# 192 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_2
# 193 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarTradeMagikarp::
# 284 "data/maps/OldaleTown/scripts.pory"
	lock
# 285 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 287 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_BarTradeMagikarp_Text_0
# 289 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, Arr2_BarTradeMagikarp_2
# 296 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarTradeMagikarp_Text_2
# 297 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarTradeMagikarp_Text_3
# 299 "data/maps/OldaleTown/scripts.pory"
	ingame_trade INGAME_TRADE_SEEDOT, Arr2_BarTradeMagikarp_Text_4, Arr2_BarTradeMagikarp_Text_5, Arr2_BarTradeMagikarp_Text_6, Arr2_BarTradeMagikarp_Text_7
# 300 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 302 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
# 304 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarTradeMagikarp_2:
# 291 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarTradeMagikarp_Text_1
# 292 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarDrinkerMachamp::
# 309 "data/maps/OldaleTown/scripts.pory"
	lock
# 310 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 312 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarDrinkerMachamp_Text_0
# 313 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarDrinkerMachamp_Text_1
# 315 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarBeerWaiter::
# 320 "data/maps/OldaleTown/scripts.pory"
	lock
# 321 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 322 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_BarBeerWaiter_Text_0
# 323 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_1
# 324 "data/maps/OldaleTown/scripts.pory"
	goto_if_set 0x4F, Arr2_BarBeerWaiter_2
# 330 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 331 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_3
# 332 "data/maps/OldaleTown/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, Arr2_BarBeerWaiter_Text_4, Arr2_BarBeerWaiter_Text_5, Arr2_BarBeerWaiter_Text_6, Arr2_BarBeerWaiter_Text_7, Arr2_BarBeerWaiter_Text_8, Arr2_BarBeerWaiter_Text_9, ManTest_Text_5
# 334 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq Arr2_BarBeerWaiter_5
# 339 "data/maps/OldaleTown/scripts.pory"
	copyvar VAR_0x8002, VAR_RESULT
# 340 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_10
# 343 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8001, 10
# 344 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8003, 5
# 346 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_11
# 347 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 351 "data/maps/OldaleTown/scripts.pory"
	opendoor 84, 12
# 352 "data/maps/OldaleTown/scripts.pory"
	waitdooranim
# 354 "data/maps/OldaleTown/scripts.pory"
	applymovement 11, Arr2_BarBeerWaiter_Movement_0
# 358 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 361 "data/maps/OldaleTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 362 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_1, 13
	goto_if_eq Arr2_BarBeerWaiter_8
Arr2_BarBeerWaiter_7:
Arr2_BarBeerWaiter_11:
# 369 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_0, 83
	goto_if_gt Arr2_BarBeerWaiter_12
# 378 "data/maps/OldaleTown/scripts.pory"
	getobjectxy OBJ_EVENT_ID_FOLLOWER, 0, VAR_TEMP_0, VAR_TEMP_1
Arr2_BarBeerWaiter_15:
# 379 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_0, 81
	goto_if_gt Arr2_BarBeerWaiter_16
Arr2_BarBeerWaiter_19:
# 387 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_1, 15
	goto_if_lt Arr2_BarBeerWaiter_20
# 395 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Arr2_BarBeerWaiter_Movement_3
# 401 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_BarBeerWaiter_Movement_4
# 405 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 408 "data/maps/OldaleTown/scripts.pory"
	delay 120
# 411 "data/maps/OldaleTown/scripts.pory"
	applymovement 11, Arr2_BarBeerWaiter_Movement_5
# 417 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 423 "data/maps/OldaleTown/scripts.pory"
	closedoor 84, 12
# 424 "data/maps/OldaleTown/scripts.pory"
	waitdooranim
# 426 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_BarBeerWaiter_Text_0
# 427 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_12, MSGBOX_YESNO
# 428 "data/maps/OldaleTown/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 429 "data/maps/OldaleTown/scripts.pory"
	checkmoney 500
# 430 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 432 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Arr2_BarBeerWaiter_25
Arr2_BarBeerWaiter_24:
# 476 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_23
# 478 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 480 "data/maps/OldaleTown/scripts.pory"
	applymovement 11, Arr2_BarBeerWaiter_Movement_6
# 485 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 487 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 490 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarBeerWaiter_2:
# 325 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_2
# 326 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarBeerWaiter_5:
# 335 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarBeerWaiter_8:
# 363 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_BarBeerWaiter_Movement_1
# 366 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
	goto Arr2_BarBeerWaiter_7

Arr2_BarBeerWaiter_12:
# 370 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Arr2_BarBeerWaiter_Movement_2
# 373 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 374 "data/maps/OldaleTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto Arr2_BarBeerWaiter_11

Arr2_BarBeerWaiter_16:
# 380 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Arr2_BarBeerWaiter_Movement_2
# 383 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 384 "data/maps/OldaleTown/scripts.pory"
	getobjectxy OBJ_EVENT_ID_FOLLOWER, 0, VAR_TEMP_0, VAR_TEMP_1
	goto Arr2_BarBeerWaiter_15

Arr2_BarBeerWaiter_20:
# 388 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Arr2_BarBeerWaiter_Movement_1
# 391 "data/maps/OldaleTown/scripts.pory"
	waitmovement
# 392 "data/maps/OldaleTown/scripts.pory"
	getobjectxy OBJ_EVENT_ID_FOLLOWER, 0, VAR_TEMP_0, VAR_TEMP_1
	goto Arr2_BarBeerWaiter_19

Arr2_BarBeerWaiter_22:
# 495 "data/maps/OldaleTown/scripts.pory"
	applymovement 11, Arr2_BarBeerWaiter_Movement_6
# 500 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 502 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8014, 1
# 508 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Arr2_BarBeerWaiter_Movement_7
# 512 "data/maps/OldaleTown/scripts.pory"
	waitmovement
# 514 "data/maps/OldaleTown/scripts.pory"
	bufferleadmonspeciesname 0
# 516 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_24
# 518 "data/maps/OldaleTown/scripts.pory"
	switch VAR_0x8002
# 519 "data/maps/OldaleTown/scripts.pory"
	case 1, Arr2_BarBeerWaiter_30
# 521 "data/maps/OldaleTown/scripts.pory"
	case 2, Arr2_BarBeerWaiter_31
Arr2_BarBeerWaiter_28:
# 525 "data/maps/OldaleTown/scripts.pory"
	callnative Script_FriendshipAndStats
# 526 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_27
# 528 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 531 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8014, 0
# 534 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 536 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarBeerWaiter_23:
# 434 "data/maps/OldaleTown/scripts.pory"
	showmoneybox 18, 0
# 435 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_13
# 436 "data/maps/OldaleTown/scripts.pory"
	removemoney 500
# 437 "data/maps/OldaleTown/scripts.pory"
	updatemoneybox
# 438 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_14
# 439 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
# 441 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_15
# 442 "data/maps/OldaleTown/scripts.pory"
	showmoneybox 18, 0
# 443 "data/maps/OldaleTown/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Arr2_BarBeerWaiter_Text_16, Arr2_BarBeerWaiter_Text_17, Arr2_BarBeerWaiter_Text_18
# 445 "data/maps/OldaleTown/scripts.pory"
	switch VAR_RESULT
# 446 "data/maps/OldaleTown/scripts.pory"
	case 0, Arr2_BarBeerWaiter_34
# 457 "data/maps/OldaleTown/scripts.pory"
	case 1, Arr2_BarBeerWaiter_35
# 467 "data/maps/OldaleTown/scripts.pory"
	case 2, Arr2_BarBeerWaiter_36
# 471 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
Arr2_BarBeerWaiter_32:
# 473 "data/maps/OldaleTown/scripts.pory"
	closemessage
	goto Arr2_BarBeerWaiter_22

Arr2_BarBeerWaiter_25:
# 432 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_1, 0
	goto_if_ne Arr2_BarBeerWaiter_23
	goto Arr2_BarBeerWaiter_24

Arr2_BarBeerWaiter_30:
# 520 "data/maps/OldaleTown/scripts.pory"
	bufferstring STR_VAR_1, Arr2_BarBeerWaiter_Text_25
	goto Arr2_BarBeerWaiter_28

Arr2_BarBeerWaiter_31:
# 522 "data/maps/OldaleTown/scripts.pory"
	bufferstring STR_VAR_1, Arr2_BarBeerWaiter_Text_26
	goto Arr2_BarBeerWaiter_28

Arr2_BarBeerWaiter_34:
# 447 "data/maps/OldaleTown/scripts.pory"
	checkmoney 500
# 448 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Arr2_BarBeerWaiter_39
# 454 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_20
Arr2_BarBeerWaiter_38:
# 456 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
	goto Arr2_BarBeerWaiter_32

Arr2_BarBeerWaiter_35:
# 458 "data/maps/OldaleTown/scripts.pory"
	checkmoney 100
# 459 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Arr2_BarBeerWaiter_43
# 464 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_20
Arr2_BarBeerWaiter_42:
# 466 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
	goto Arr2_BarBeerWaiter_32

Arr2_BarBeerWaiter_36:
# 468 "data/maps/OldaleTown/scripts.pory"
	hidemoneybox
# 469 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_22
	goto Arr2_BarBeerWaiter_32

Arr2_BarBeerWaiter_39:
# 449 "data/maps/OldaleTown/scripts.pory"
	removemoney 500
# 450 "data/maps/OldaleTown/scripts.pory"
	updatemoneybox
# 452 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_19
	goto Arr2_BarBeerWaiter_38

Arr2_BarBeerWaiter_43:
# 460 "data/maps/OldaleTown/scripts.pory"
	removemoney 100
# 461 "data/maps/OldaleTown/scripts.pory"
	updatemoneybox
# 462 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarBeerWaiter_Text_21
	goto Arr2_BarBeerWaiter_42


Arr2_BarWineWaiter::
# 541 "data/maps/OldaleTown/scripts.pory"
	lock
# 542 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 543 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_BarBeerWaiter_Text_0
# 544 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarWineWaiter_Text_0
# 545 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarWineWaiter_Text_1
# 546 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarOldLady::
# 552 "data/maps/OldaleTown/scripts.pory"
	lock
# 553 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 554 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarOldLady_Text_0
# 555 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarGentleman::
# 560 "data/maps/OldaleTown/scripts.pory"
	lock
# 561 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 562 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarGentleman_Text_0
# 563 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_BarLady::
# 568 "data/maps/OldaleTown/scripts.pory"
	lock
# 569 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 571 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_SHOCK_WAVE, Arr2_BarLady_2
# 578 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_1
# 579 "data/maps/OldaleTown/scripts.pory"
	applymovement 16, Arr2_BarLady_Movement_0
# 584 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 586 "data/maps/OldaleTown/scripts.pory"
	special SpawnCameraObject
# 587 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_1
# 588 "data/maps/OldaleTown/scripts.pory"
	playSE SE_PIN
# 589 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_2
# 590 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_2
# 591 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_3, MSGBOX_YESNO
# 592 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Arr2_BarLady_5
Arr2_BarLady_4:
# 633 "data/maps/OldaleTown/scripts.pory"
	special RemoveCameraObject
# 634 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarLady_2:
# 573 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_0
# 574 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_BarLady_5:
# 593 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_4
# 595 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_5
# 597 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_6
# 599 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_1
# 600 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 601 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_7
# 602 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_2
# 604 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_8
# 606 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_1
# 607 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 609 "data/maps/OldaleTown/scripts.pory"
	applymovement 16, Arr2_BarLady_Movement_3
# 614 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_9
# 616 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Arr2_BarLady_Movement_2
# 617 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 619 "data/maps/OldaleTown/scripts.pory"
	applymovement 17, Arr2_BarLady_Movement_4
# 623 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 625 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_10
# 627 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 628 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_BarLady_Text_11
# 629 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_TM_SHOCK_WAVE
# 630 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	goto Arr2_BarLady_4


Arr2_BarLass::
	return


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

# 202 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_1:
# 203 "data/maps/OldaleTown/scripts.pory"
	emote_exclamation_mark
# 204 "data/maps/OldaleTown/scripts.pory"
	face_right
	step_end

# 212 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_2:
# 213 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
	step_end

# 218 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_3:
# 219 "data/maps/OldaleTown/scripts.pory"
	emote_exclamation_mark
# 220 "data/maps/OldaleTown/scripts.pory"
	face_right
# 221 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 221 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 221 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
	step_end

# 228 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_4:
# 229 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 230 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
# 231 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 232 "data/maps/OldaleTown/scripts.pory"
	face_up
	step_end

# 258 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_5:
# 259 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 260 "data/maps/OldaleTown/scripts.pory"
	face_down
	step_end

# 264 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_6:
# 265 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 266 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 266 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 267 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 267 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 267 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 267 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 267 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 267 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 267 "data/maps/OldaleTown/scripts.pory"
	walk_up
	step_end

# 354 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_0:
# 355 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 356 "data/maps/OldaleTown/scripts.pory"
	set_invisible
	step_end

# 363 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_1:
# 364 "data/maps/OldaleTown/scripts.pory"
	walk_down
	step_end

# 370 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_2:
# 371 "data/maps/OldaleTown/scripts.pory"
	walk_left
	step_end

# 395 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_3:
# 396 "data/maps/OldaleTown/scripts.pory"
	face_right
	step_end

# 401 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_4:
# 402 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 403 "data/maps/OldaleTown/scripts.pory"
	face_left
	step_end

# 411 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_5:
# 412 "data/maps/OldaleTown/scripts.pory"
	set_visible
# 413 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 414 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 414 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 415 "data/maps/OldaleTown/scripts.pory"
	walk_down
	step_end

# 480 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_6:
# 481 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 482 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 482 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 483 "data/maps/OldaleTown/scripts.pory"
	face_down
	step_end

# 508 "data/maps/OldaleTown/scripts.pory"
Arr2_BarBeerWaiter_Movement_7:
# 509 "data/maps/OldaleTown/scripts.pory"
	emote_heart
# 510 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 510 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
	step_end

# 579 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_0:
# 580 "data/maps/OldaleTown/scripts.pory"
	emote_exclamation_mark
# 581 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_right
# 582 "data/maps/OldaleTown/scripts.pory"
	face_left
	step_end

# 587 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_1:
# 587 "data/maps/OldaleTown/scripts.pory"
	walk_fast_left
# 587 "data/maps/OldaleTown/scripts.pory"
	walk_fast_left
	step_end

# 590 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_2:
# 590 "data/maps/OldaleTown/scripts.pory"
	walk_fast_right
# 590 "data/maps/OldaleTown/scripts.pory"
	walk_fast_right
	step_end

# 609 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_3:
# 610 "data/maps/OldaleTown/scripts.pory"
	face_right
# 611 "data/maps/OldaleTown/scripts.pory"
	emote_heart
	step_end

# 619 "data/maps/OldaleTown/scripts.pory"
Arr2_BarLady_Movement_4:
# 620 "data/maps/OldaleTown/scripts.pory"
	face_left
# 621 "data/maps/OldaleTown/scripts.pory"
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
	.string "Matchmaking in progress...$"

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
# 207 "data/maps/OldaleTown/scripts.pory"
	.string "Oh good lord! He seems angry!$"

Arr2_Fisherman_Text_4:
# 208 "data/maps/OldaleTown/scripts.pory"
	.string "No, don't attack me! Please, I won't fish\n"
	.string "here anymore, I promise!$"

Arr2_Fisherman_Text_5:
# 226 "data/maps/OldaleTown/scripts.pory"
	.string "Oh no, another one?!$"

Arr2_Fisherman_Text_6:
# 236 "data/maps/OldaleTown/scripts.pory"
	.string "You, please help me!$"

Arr2_Fisherman_Text_7:
# 251 "data/maps/OldaleTown/scripts.pory"
	.string "Oh! You saved me! I wonder what could\n"
	.string "have happened if you weren't here. I\l"
	.string "don't want to fish anymore. I'll find\l"
	.string "myself another passion. Please, have\l"
	.string "this, I wont be using it anymore.$"

Arr2_BarTradeMagikarp_Text_0:
# 287 "data/maps/OldaleTown/scripts.pory"
	.string "Marcel$"

Arr2_BarTradeMagikarp_Text_1:
# 291 "data/maps/OldaleTown/scripts.pory"
	.string "Your Magikarp is so great!$"

Arr2_BarTradeMagikarp_Text_2:
# 296 "data/maps/OldaleTown/scripts.pory"
	.string "I've always dreamed of having a\n"
	.string "Gyarados. It should be easy : Magikarp\l"
	.string "are everywhere, but not for me. I'm so\l"
	.string "unlucky that one never bites my line.$"

Arr2_BarTradeMagikarp_Text_3:
# 297 "data/maps/OldaleTown/scripts.pory"
	.string "All I have is this stupid Luvdisc my ex\n"
	.string "gave me. I don't even want it... it just\l"
	.string "reminds me of her.$"

Arr2_BarTradeMagikarp_Text_4:
# 299 "data/maps/OldaleTown/scripts.pory"
	.string "Would you trade a Magikarp for a\n"
	.string "Luvdisc?$"

Arr2_BarTradeMagikarp_Text_5:
# 299 "data/maps/OldaleTown/scripts.pory"
	.string "Arghhh... No luck even with trades.$"

Arr2_BarTradeMagikarp_Text_6:
# 299 "data/maps/OldaleTown/scripts.pory"
	.string "That's not a Magikarp.$"

Arr2_BarTradeMagikarp_Text_7:
# 299 "data/maps/OldaleTown/scripts.pory"
	.string "Take care of it.$"

Arr2_BarDrinkerMachamp_Text_0:
# 312 "data/maps/OldaleTown/scripts.pory"
	.string "Oh... I always drink too much. What?\n"
	.string "You're wondering if I'm scared of not\l"
	.string "making it home? No, not at all.$"

Arr2_BarDrinkerMachamp_Text_1:
# 313 "data/maps/OldaleTown/scripts.pory"
	.string "My Machamp always carries me with his\n"
	.string "four arms when I've had too much.$"

Arr2_BarBeerWaiter_Text_0:
# 322 "data/maps/OldaleTown/scripts.pory"
	.string "Waiter$"

Arr2_BarBeerWaiter_Text_1:
# 323 "data/maps/OldaleTown/scripts.pory"
	.string "Hello and welcome to {COLOR BLUE}{SHADOW LIGHT_BLUE}Scrafty Beers.$"

Arr2_BarBeerWaiter_Text_2:
# 325 "data/maps/OldaleTown/scripts.pory"
	.string "Come with a Pokémon, it will be better\n"
	.string "trust me.$"

Arr2_BarBeerWaiter_Text_3:
# 331 "data/maps/OldaleTown/scripts.pory"
	.string "What will it be? Standard prices,\n"
	.string "everything comes at ¥500.$"

Arr2_BarBeerWaiter_Text_4:
# 332 "data/maps/OldaleTown/scripts.pory"
	.string "Cider$"

Arr2_BarBeerWaiter_Text_5:
# 332 "data/maps/OldaleTown/scripts.pory"
	.string "Lager Beer$"

Arr2_BarBeerWaiter_Text_6:
# 332 "data/maps/OldaleTown/scripts.pory"
	.string "Pale Ale Beer$"

Arr2_BarBeerWaiter_Text_7:
# 332 "data/maps/OldaleTown/scripts.pory"
	.string "Red Wine$"

Arr2_BarBeerWaiter_Text_8:
# 332 "data/maps/OldaleTown/scripts.pory"
	.string "White Wine$"

Arr2_BarBeerWaiter_Text_9:
# 332 "data/maps/OldaleTown/scripts.pory"
	.string "Gin Tonic$"

Arr2_BarBeerWaiter_Text_10:
# 340 "data/maps/OldaleTown/scripts.pory"
	.string "Great choice!$"

Arr2_BarBeerWaiter_Text_11:
# 346 "data/maps/OldaleTown/scripts.pory"
	.string "Please, take a seat.$"

Arr2_BarBeerWaiter_Text_12:
# 427 "data/maps/OldaleTown/scripts.pory"
	.string "That will be ¥500 please.$"

Arr2_BarBeerWaiter_Text_13:
# 435 "data/maps/OldaleTown/scripts.pory"
	.string "Just put your card over here...$"

Arr2_BarBeerWaiter_Text_14:
# 438 "data/maps/OldaleTown/scripts.pory"
	.string "Transaction done. Tips are welcome if\n"
	.string "you'd like.$"

Arr2_BarBeerWaiter_Text_15:
# 441 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}Give a tip?$"

Arr2_BarBeerWaiter_Text_16:
# 443 "data/maps/OldaleTown/scripts.pory"
	.string "500$"

Arr2_BarBeerWaiter_Text_17:
# 443 "data/maps/OldaleTown/scripts.pory"
	.string "100$"

Arr2_BarBeerWaiter_Text_18:
# 443 "data/maps/OldaleTown/scripts.pory"
	.string "0$"

Arr2_BarBeerWaiter_Text_19:
# 452 "data/maps/OldaleTown/scripts.pory"
	.string "Enjoy your drink!$"

Arr2_BarBeerWaiter_Text_20:
# 454 "data/maps/OldaleTown/scripts.pory"
	.string "Big talks for empty pockets.$"

Arr2_BarBeerWaiter_Text_21:
# 462 "data/maps/OldaleTown/scripts.pory"
	.string "Thanks!$"

Arr2_BarBeerWaiter_Text_22:
# 469 "data/maps/OldaleTown/scripts.pory"
	.string "...$"

Arr2_BarBeerWaiter_Text_23:
# 476 "data/maps/OldaleTown/scripts.pory"
	.string "Wait, you can't pay for the drinks? Then\n"
	.string "these are coming right back with me!$"

Arr2_BarBeerWaiter_Text_24:
# 516 "data/maps/OldaleTown/scripts.pory"
	.string "{STR_VAR_1} had a sip of your drink.\n"
	.string "It seems more attached to you.$"

Arr2_BarBeerWaiter_Text_25:
# 520 "data/maps/OldaleTown/scripts.pory"
	.string "Attack$"

Arr2_BarBeerWaiter_Text_26:
# 522 "data/maps/OldaleTown/scripts.pory"
	.string "Defense$"

Arr2_BarBeerWaiter_Text_27:
# 526 "data/maps/OldaleTown/scripts.pory"
	.string "Its {STR_VAR_1} was raised a little.$"

Arr2_BarWineWaiter_Text_0:
# 544 "data/maps/OldaleTown/scripts.pory"
	.string "Hello and welcome to {COLOR BLUE}{SHADOW LIGHT_BLUE}Wine Whip.$"

Arr2_BarWineWaiter_Text_1:
# 545 "data/maps/OldaleTown/scripts.pory"
	.string "I am sorry but all our tables are full\n"
	.string "today. Our neighbors are selling wine\l"
	.string "too if you need, maybe as good as ours\l"
	.string "but worth a try.$"

Arr2_BarOldLady_Text_0:
# 554 "data/maps/OldaleTown/scripts.pory"
	.string "I knew this bar since I was a kid. The\n"
	.string "place itself didn't change much but\l"
	.string "everything else did. The people, the\l"
	.string "surroundings and the staff. It was\l"
	.string "before Lutecia became the capitale of\l"
	.string "Kalos, when it was still a calm and\l"
	.string "peaceful city.$"

Arr2_BarGentleman_Text_0:
# 562 "data/maps/OldaleTown/scripts.pory"
	.string "I have been visiting this bar since I\n"
	.string "was about as young as you. The taste\l"
	.string "brings up so much memories...$"

Arr2_BarLady_Text_0:
# 573 "data/maps/OldaleTown/scripts.pory"
	.string "I am glad I was in the bar that day. My\n"
	.string "life would have been very different\l"
	.string "otherwise.$"

Arr2_BarLady_Text_1:
# 578 "data/maps/OldaleTown/scripts.pory"
	.string "You know, me and my husband met in this\n"
	.string "very bar. We met under very special\l"
	.string "circumstances.$"

Arr2_BarLady_Text_2:
# 589 "data/maps/OldaleTown/scripts.pory"
	.string "No! Don't tell him!$"

Arr2_BarLady_Text_3:
# 591 "data/maps/OldaleTown/scripts.pory"
	.string "Do you want to know ?$"

Arr2_BarLady_Text_4:
# 593 "data/maps/OldaleTown/scripts.pory"
	.string "Well, he had too much wine that day. He\n"
	.string "was so drunk people were gathering\l"
	.string "around him thinking he was dead.$"

Arr2_BarLady_Text_5:
# 595 "data/maps/OldaleTown/scripts.pory"
	.string "Then I came, ordered by Pokémon to use\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Shock Wave{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}, and he woke up abruptly.$"

Arr2_BarLady_Text_6:
# 597 "data/maps/OldaleTown/scripts.pory"
	.string "He looked at me and said, 'Are you an\n"
	.string "angel?' I never let him live that down.$"

Arr2_BarLady_Text_7:
# 601 "data/maps/OldaleTown/scripts.pory"
	.string "I am so embarassed!$"

Arr2_BarLady_Text_8:
# 604 "data/maps/OldaleTown/scripts.pory"
	.string "And well... here we are, years later!$"

Arr2_BarLady_Text_9:
# 614 "data/maps/OldaleTown/scripts.pory"
	.string "I am glad I met you.$"

Arr2_BarLady_Text_10:
# 625 "data/maps/OldaleTown/scripts.pory"
	.string "Me too... Me too...$"

Arr2_BarLady_Text_11:
# 628 "data/maps/OldaleTown/scripts.pory"
	.string "Oh. I am rambling again. Here's a little\n"
	.string "thank you for listening to me.$"
