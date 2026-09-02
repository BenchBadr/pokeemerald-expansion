OldaleTown_MapScripts::
	.byte 0


ScraftyBeers_Sign::
# 4 "data/maps/OldaleTown/scripts.pory"
	msgbox ScraftyBeers_Sign_Text_0, MSGBOX_SIGN
# 5 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end


ManTest::
# 11 "data/maps/OldaleTown/scripts.pory"
	lock
# 12 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 14 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_0
# 17 "data/maps/OldaleTown/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, ManTest_Text_1, ManTest_Text_2, ManTest_Text_3, ManTest_Text_4, ManTest_Text_5
# 18 "data/maps/OldaleTown/scripts.pory"
	switch VAR_RESULT
# 19 "data/maps/OldaleTown/scripts.pory"
	case 0, ManTest_3
# 21 "data/maps/OldaleTown/scripts.pory"
	case 1, ManTest_4
# 23 "data/maps/OldaleTown/scripts.pory"
	case 2, ManTest_5
# 29 "data/maps/OldaleTown/scripts.pory"
	case 3, ManTest_6
ManTest_1:
# 37 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end

ManTest_3:
# 20 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_6
	goto ManTest_1

ManTest_4:
# 22 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_7
	goto ManTest_1

ManTest_5:
# 24 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8004, 5
# 25 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
# 26 "data/maps/OldaleTown/scripts.pory"
	delay 120
# 27 "data/maps/OldaleTown/scripts.pory"
	waitbuttonpress
# 28 "data/maps/OldaleTown/scripts.pory"
	callnative Script_HideRankDisplay
	goto ManTest_1

ManTest_6:
# 30 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8004, -5
# 31 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
# 32 "data/maps/OldaleTown/scripts.pory"
	delay 120
# 33 "data/maps/OldaleTown/scripts.pory"
	waitbuttonpress
# 34 "data/maps/OldaleTown/scripts.pory"
	callnative Script_HideRankDisplay
	goto ManTest_1


BattleZone1_Matchmaking::
# 42 "data/maps/OldaleTown/scripts.pory"
	lock
# 43 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 44 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 1
# 45 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_0, MSGBOX_YESNO
# 47 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 49 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleZone1_Matchmaking_2
# 59 "data/maps/OldaleTown/scripts.pory"
	callnative Script_SetupRandomOpponent
# 60 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_1
# 64 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 65 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleZone1_Matchmaking_Movement_0
# 70 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 73 "data/maps/OldaleTown/scripts.pory"
	setflag 0x4D
# 74 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 76 "data/maps/OldaleTown/scripts.pory"
	special HealPlayerParty
# 81 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8005, 3
# 82 "data/maps/OldaleTown/scripts.pory"
	special ChoosePartyForBattleFrontier
# 83 "data/maps/OldaleTown/scripts.pory"
	waitstate
# 84 "data/maps/OldaleTown/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 85 "data/maps/OldaleTown/scripts.pory"
	frontier_setpartyorder 3
# 90 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_2
# 91 "data/maps/OldaleTown/scripts.pory"
	trainerbattle_no_intro TRAINER_SAWYER_1, BattleZone1_Matchmaking_Text_3
# 95 "data/maps/OldaleTown/scripts.pory"
	special HealPlayerParty
# 98 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 1
# 101 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleZone1_Matchmaking_5
# 108 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_5
# 110 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, -5
BattleZone1_Matchmaking_4:
# 113 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
# 114 "data/maps/OldaleTown/scripts.pory"
	delay 120
# 115 "data/maps/OldaleTown/scripts.pory"
	waitbuttonpress
# 116 "data/maps/OldaleTown/scripts.pory"
	callnative Script_HideRankDisplay
# 118 "data/maps/OldaleTown/scripts.pory"
	special LoadPlayerParty
# 120 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 121 "data/maps/OldaleTown/scripts.pory"
	clearflag 0x4E
# 122 "data/maps/OldaleTown/scripts.pory"
	clearflag 0x4D
# 123 "data/maps/OldaleTown/scripts.pory"
	release
	end

BattleZone1_Matchmaking_2:
	return

BattleZone1_Matchmaking_5:
# 102 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_4
# 104 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, 5
	goto BattleZone1_Matchmaking_4


# 65 "data/maps/OldaleTown/scripts.pory"
BattleZone1_Matchmaking_Movement_0:
# 66 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 66 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 67 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 67 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 68 "data/maps/OldaleTown/scripts.pory"
	face_down
	step_end

ScraftyBeers_Sign_Text_0:
# 4 "data/maps/OldaleTown/scripts.pory"
	.string "Scrafty Beers.\n"
	.string "Independent brewery.\p"
	.string "Handcrafted Beers, brewed tough,\n"
	.string "served cold.$"

ManTest_Text_0:
# 14 "data/maps/OldaleTown/scripts.pory"
	.string "Welcome to the Battle Zone! Do you need\n"
	.string "any explanation ?$"

ManTest_Text_1:
# 17 "data/maps/OldaleTown/scripts.pory"
	.string "What are ranks$"

ManTest_Text_2:
# 17 "data/maps/OldaleTown/scripts.pory"
	.string "What is this place$"

ManTest_Text_3:
# 17 "data/maps/OldaleTown/scripts.pory"
	.string "Add Points$"

ManTest_Text_4:
# 17 "data/maps/OldaleTown/scripts.pory"
	.string "Remove Points$"

ManTest_Text_5:
# 17 "data/maps/OldaleTown/scripts.pory"
	.string "No thanks$"

ManTest_Text_6:
# 20 "data/maps/OldaleTown/scripts.pory"
	.string "There are 5 ranks in the PWC.$"

ManTest_Text_7:
# 22 "data/maps/OldaleTown/scripts.pory"
	.string "This place is what we call a Battle Zone.$"

BattleZone1_Matchmaking_Text_0:
# 45 "data/maps/OldaleTown/scripts.pory"
	.string "Do you want to find an opponent?$"

BattleZone1_Matchmaking_Text_1:
# 60 "data/maps/OldaleTown/scripts.pory"
	.string "Wait please.$"

BattleZone1_Matchmaking_Text_2:
# 90 "data/maps/OldaleTown/scripts.pory"
	.string "{STR_VAR_1}$"

BattleZone1_Matchmaking_Text_3:
# 91 "data/maps/OldaleTown/scripts.pory"
	.string "{STR_VAR_3}$"

BattleZone1_Matchmaking_Text_4:
# 102 "data/maps/OldaleTown/scripts.pory"
	.string "Congratulations on your victory! Your\n"
	.string "rank is being updated...$"

BattleZone1_Matchmaking_Text_5:
# 108 "data/maps/OldaleTown/scripts.pory"
	.string "You lost your battle. Your rank is being\n"
	.string "updated...$"
