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


TrainerClub_Sign::
# 160 "data/maps/OldaleTown/scripts.pory"
	msgbox TrainerClub_Sign_Text_0, MSGBOX_SIGN
# 161 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end


TestGiveTM::
# 169 "data/maps/OldaleTown/scripts.pory"
	msgbox TestGiveTM_Text_0
# 170 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_TM_AERIAL_ACE
# 171 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end


Arr2_Fisherman::
# 178 "data/maps/OldaleTown/scripts.pory"
	lock
# 180 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_0
# 182 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_1
# 184 "data/maps/OldaleTown/scripts.pory"
	getpartysize
# 185 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt Arr2_Fisherman_2
# 192 "data/maps/OldaleTown/scripts.pory"
	showobjectat 6, MAP_OLDALE_TOWN
# 193 "data/maps/OldaleTown/scripts.pory"
	applymovement 6, Arr2_Fisherman_Movement_0
# 195 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_3
# 196 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_4
# 198 "data/maps/OldaleTown/scripts.pory"
	showobjectat 8, MAP_OLDALE_TOWN
# 199 "data/maps/OldaleTown/scripts.pory"
	applymovement 6, Arr2_Fisherman_Movement_1
# 203 "data/maps/OldaleTown/scripts.pory"
	applymovement 6, Arr2_Fisherman_Movement_0
# 205 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_5
# 207 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_UNUSED_0x1DE
# 208 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_UNUSED_0x1DF
# 210 "data/maps/OldaleTown/scripts.pory"
	setwildbattle SPECIES_MAGIKARP, 4, ITEM_NONE, SPECIES_MAGIKARP, 3, ITEM_NONE
# 211 "data/maps/OldaleTown/scripts.pory"
	dowildbattle
# 213 "data/maps/OldaleTown/scripts.pory"
	clearflag FLAG_UNUSED_0x1DE
# 214 "data/maps/OldaleTown/scripts.pory"
	clearflag FLAG_UNUSED_0x1DF
# 217 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 218 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_6
# 220 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_OLD_ROD
# 221 "data/maps/OldaleTown/scripts.pory"
	fadescreen FADE_TO_BLACK
# 222 "data/maps/OldaleTown/scripts.pory"
	removeobject 7, MAP_OLDALE_TOWN
# 223 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
# 225 "data/maps/OldaleTown/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 230 "data/maps/OldaleTown/scripts.pory"
	release
	end

Arr2_Fisherman_2:
# 186 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_Fisherman_Text_2
# 187 "data/maps/OldaleTown/scripts.pory"
	release
	end


Arr2_TradeMagikarp::
# 237 "data/maps/OldaleTown/scripts.pory"
	lock
# 238 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 240 "data/maps/OldaleTown/scripts.pory"
	setspeaker Arr2_TradeMagikarp_Text_0
# 241 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_TradeMagikarp_Text_1
# 242 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_TradeMagikarp_Text_2
# 243 "data/maps/OldaleTown/scripts.pory"
	msgbox Arr2_TradeMagikarp_Text_3
# 245 "data/maps/OldaleTown/scripts.pory"
	release
	end


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

# 193 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_0:
# 193 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
# 193 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
# 193 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
	step_end

# 199 "data/maps/OldaleTown/scripts.pory"
Arr2_Fisherman_Movement_1:
# 200 "data/maps/OldaleTown/scripts.pory"
	face_right
# 201 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
# 201 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
# 201 "data/maps/OldaleTown/scripts.pory"
	jump_in_place_left
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

TrainerClub_Sign_Text_0:
# 160 "data/maps/OldaleTown/scripts.pory"
	.string "Trainer Club\n"
	.string "\p"
	.string "$"

TestGiveTM_Text_0:
# 169 "data/maps/OldaleTown/scripts.pory"
	.string "Here is a TM just for you.$"

Arr2_Fisherman_Text_0:
# 180 "data/maps/OldaleTown/scripts.pory"
	.string "Let's get fishing, I am not doing to find\n"
	.string "the golden Magikarp just by staring at\l"
	.string "the water$"

Arr2_Fisherman_Text_1:
# 182 "data/maps/OldaleTown/scripts.pory"
	.string "... ... ...$"

Arr2_Fisherman_Text_2:
# 186 "data/maps/OldaleTown/scripts.pory"
	.string "Not even a nibble...$"

Arr2_Fisherman_Text_3:
# 195 "data/maps/OldaleTown/scripts.pory"
	.string "Oh good lord! He seems angry!$"

Arr2_Fisherman_Text_4:
# 196 "data/maps/OldaleTown/scripts.pory"
	.string "No, don't attack me! Please, I won't fish\n"
	.string "here anymore, I promise!$"

Arr2_Fisherman_Text_5:
# 205 "data/maps/OldaleTown/scripts.pory"
	.string "Oh no, another one?! Somebody, please\n"
	.string "help me!$"

Arr2_Fisherman_Text_6:
# 218 "data/maps/OldaleTown/scripts.pory"
	.string "Oh! You saved me! I wonder what could\n"
	.string "have happened if you weren't here. I\l"
	.string "don't want to fish anymore. I'll find\l"
	.string "myself another passion. Please, have\l"
	.string "this, I wont be using it anymore.$"

Arr2_TradeMagikarp_Text_0:
# 240 "data/maps/OldaleTown/scripts.pory"
	.string "Marcel$"

Arr2_TradeMagikarp_Text_1:
# 241 "data/maps/OldaleTown/scripts.pory"
	.string "I've always dreamed of having a\n"
	.string "Gyarados. It should be easy : Magikarp\l"
	.string "are everywhere, but not for me. I'm so\l"
	.string "unlucky that one never bites my line.$"

Arr2_TradeMagikarp_Text_2:
# 242 "data/maps/OldaleTown/scripts.pory"
	.string "All I have is this stupid Luvdisc my ex\n"
	.string "gave me. I don't even want it... it just\l"
	.string "reminds me of her.$"

Arr2_TradeMagikarp_Text_3:
# 243 "data/maps/OldaleTown/scripts.pory"
	.string "Would you trade a Magikarp for a\n"
	.string "Luvdisc?$"
