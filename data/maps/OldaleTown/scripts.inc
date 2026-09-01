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
	msgbox ManTest_Text_0, MSGBOX_YESNO
# 12 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ManTest_2
ManTest_1:
# 15 "data/maps/OldaleTown/scripts.pory"
	closemessage
	end

ManTest_2:
# 13 "data/maps/OldaleTown/scripts.pory"
	msgbox ManTest_Text_1
	goto ManTest_1


BattleZone1_SawyerBattle::
# 20 "data/maps/OldaleTown/scripts.pory"
	lock
# 21 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 22 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 1
# 23 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_SawyerBattle_Text_0, MSGBOX_YESNO
# 24 "data/maps/OldaleTown/scripts.pory"
	setvar 0x8014, 0
# 26 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 28 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleZone1_SawyerBattle_2
BattleZone1_SawyerBattle_1:
# 33 "data/maps/OldaleTown/scripts.pory"
	release
	end

BattleZone1_SawyerBattle_2:
# 30 "data/maps/OldaleTown/scripts.pory"
	trainerbattle_no_intro TRAINER_SAWYER_1, BattleZone1_SawyerBattle_Text_1
# 31 "data/maps/OldaleTown/scripts.pory"
	msgbox BattleZone1_SawyerBattle_Text_2, MSGBOX_AUTOCLOSE
	goto BattleZone1_SawyerBattle_1


ScraftyBeers_Sign_Text_0:
# 4 "data/maps/OldaleTown/scripts.pory"
	.string "Scrafty Beers.\n"
	.string "Independent brewery.\p"
	.string "Handcrafted Beers, brewed tough,\n"
	.string "served cold.$"

ManTest_Text_0:
# 11 "data/maps/OldaleTown/scripts.pory"
	.string "Just a little yesno test$"

ManTest_Text_1:
# 13 "data/maps/OldaleTown/scripts.pory"
	.string "Yes!$"

BattleZone1_SawyerBattle_Text_0:
# 23 "data/maps/OldaleTown/scripts.pory"
	.string "Do you want to find an opponent?$"

BattleZone1_SawyerBattle_Text_1:
# 30 "data/maps/OldaleTown/scripts.pory"
	.string "Crushed like a pebble...$"

BattleZone1_SawyerBattle_Text_2:
# 31 "data/maps/OldaleTown/scripts.pory"
	.string "I need to head back to the mountains\n"
	.string "and train my Geodude harder.$"
