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
	setvar VAR_0x8004, -5
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
# 30 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 32 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 34 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleZone1_Matchmaking_2
# 36 "data/maps/OldaleTown/scripts.pory"
	applymovement 2, BattleZone1_Matchmaking_Movement_0
# 41 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 43 "data/maps/OldaleTown/scripts.pory"
	setflag 0x4D
# 45 "data/maps/OldaleTown/scripts.pory"
	trainerbattle_no_intro TRAINER_SAWYER_1, BattleZone1_Matchmaking_Text_1
# 47 "data/maps/OldaleTown/scripts.pory"
	special HealPlayerParty
# 49 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 1
# 50 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleZone1_Matchmaking_5
# 61 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_3
# 62 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 64 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, -5
# 65 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
BattleZone1_Matchmaking_4:
# 68 "data/maps/OldaleTown/scripts.pory"
	clearflag 0x4D
# 69 "data/maps/OldaleTown/scripts.pory"
	release
	end

BattleZone1_Matchmaking_2:
	return

BattleZone1_Matchmaking_5:
# 51 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_Matchmaking_Text_2
# 52 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 54 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 56 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8004, 5
# 57 "data/maps/OldaleTown/scripts.pory"
	callnative Script_AddTrainerPointsAnim
	goto BattleZone1_Matchmaking_4


# 36 "data/maps/OldaleTown/scripts.pory"
BattleZone1_Matchmaking_Movement_0:
# 37 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 37 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 38 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 38 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 39 "data/maps/OldaleTown/scripts.pory"
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
# 45 "data/maps/OldaleTown/scripts.pory"
	.string "Crushed like a pebble...$"

BattleZone1_Matchmaking_Text_2:
# 51 "data/maps/OldaleTown/scripts.pory"
	.string "Congratulations on your victory!$"

BattleZone1_Matchmaking_Text_3:
# 61 "data/maps/OldaleTown/scripts.pory"
	.string "Your rank got lower$"
