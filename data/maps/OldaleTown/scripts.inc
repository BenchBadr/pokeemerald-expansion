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
	setvar 0x8014, 1
# 12 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_0
# 14 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, 5
# 15 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
# 16 "data/maps/OldaleTown/scripts.pory"
	waitbuttonpress
# 17 "data/maps/OldaleTown/scripts.pory"
	callnative Script_HideRankDisplay
# 19 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_1
# 20 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 21 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end


BattleZone1_Matchmaking::
# 26 "data/maps/OldaleTown/scripts.pory"
	lock
# 27 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 28 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 1
# 29 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_0, MSGBOX_YESNO
# 31 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 33 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleZone1_Matchmaking_2
# 35 "data/maps/OldaleTown/scripts.pory"
	setflag 0x4E
# 36 "data/maps/OldaleTown/scripts.pory"
	hidefollower
# 39 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleZone1_Matchmaking_Movement_0
# 44 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 46 "data/maps/OldaleTown/scripts.pory"
	setflag 0x4D
# 48 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 50 "data/maps/OldaleTown/scripts.pory"
	trainerbattle_no_intro TRAINER_SAWYER_1, BattleZone1_Matchmaking_Text_1
# 52 "data/maps/OldaleTown/scripts.pory"
	special HealPlayerParty
# 55 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 1
# 58 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleZone1_Matchmaking_5
# 65 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_3
# 67 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, -5
BattleZone1_Matchmaking_4:
# 70 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
# 71 "data/maps/OldaleTown/scripts.pory"
	waitbuttonpress
# 72 "data/maps/OldaleTown/scripts.pory"
	callnative Script_HideRankDisplay
# 74 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 75 "data/maps/OldaleTown/scripts.pory"
	clearflag 0x4E
# 76 "data/maps/OldaleTown/scripts.pory"
	clearflag 0x4D
# 77 "data/maps/OldaleTown/scripts.pory"
	release
	end

BattleZone1_Matchmaking_2:
	return

BattleZone1_Matchmaking_5:
# 59 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_2
# 61 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, 5
	goto BattleZone1_Matchmaking_4


# 39 "data/maps/OldaleTown/scripts.pory"
BattleZone1_Matchmaking_Movement_0:
# 40 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 40 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 41 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 41 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 42 "data/maps/OldaleTown/scripts.pory"
	face_down
	step_end

ScraftyBeers_Sign_Text_0:
# 4 "data/maps/OldaleTown/scripts.pory"
	.string "Scrafty Beers.\n"
	.string "Independent brewery.\p"
	.string "Handcrafted Beers, brewed tough,\n"
	.string "served cold.$"

ManTest_Text_0:
# 12 "data/maps/OldaleTown/scripts.pory"
	.string "Just a little yesno test$"

ManTest_Text_1:
# 19 "data/maps/OldaleTown/scripts.pory"
	.string "Cool eh!$"

BattleZone1_Matchmaking_Text_0:
# 29 "data/maps/OldaleTown/scripts.pory"
	.string "Do you want to find an opponent?$"

BattleZone1_Matchmaking_Text_1:
# 50 "data/maps/OldaleTown/scripts.pory"
	.string "Crushed like a pebble...$"

BattleZone1_Matchmaking_Text_2:
# 59 "data/maps/OldaleTown/scripts.pory"
	.string "Congratulations on your victory! Your\n"
	.string "rank is being updated...$"

BattleZone1_Matchmaking_Text_3:
# 65 "data/maps/OldaleTown/scripts.pory"
	.string "You lost your battle. Your rank is being\n"
	.string "updated...$"
