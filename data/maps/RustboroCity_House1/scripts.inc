# 1 "data/maps/RustboroCity_House1/scripts.pory"

# 2 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_MapScripts::
# 3 "data/maps/RustboroCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_House1/scripts.pory"

# 5 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_Trader::
# 6 "data/maps/RustboroCity_House1/scripts.pory"
	lock
# 7 "data/maps/RustboroCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 9 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 10 "data/maps/RustboroCity_House1/scripts.pory"

# 11 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_DeclineTrade::
# 12 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
# 13 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 14 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 15 "data/maps/RustboroCity_House1/scripts.pory"

# 16 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_NotRequestedMon::
# 17 "data/maps/RustboroCity_House1/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 18 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
# 19 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 20 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 21 "data/maps/RustboroCity_House1/scripts.pory"

# 22 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_TradeCompleted::
# 23 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
# 24 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 25 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 26 "data/maps/RustboroCity_House1/scripts.pory"

# 27 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_Hiker::
# 28 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
# 29 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 30 "data/maps/RustboroCity_House1/scripts.pory"

# 31 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_IllTradeIfYouWant:
# 32 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Huh? My POKéMON is cute?\n"
# 33 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Sure, I knew that.\p"
# 34 "data/maps/RustboroCity_House1/scripts.pory"
	.string "But if you really want, I'm willing\n"
# 35 "data/maps/RustboroCity_House1/scripts.pory"
	.string "to trade it to you.\p"
# 36 "data/maps/RustboroCity_House1/scripts.pory"
	.string "I'll trade you my {STR_VAR_2} for\n"
# 37 "data/maps/RustboroCity_House1/scripts.pory"
	.string "a {STR_VAR_1} if you want.$"
# 38 "data/maps/RustboroCity_House1/scripts.pory"

# 39 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
# 40 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Eheheh…\n"
# 41 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Please be good to my POKéMON.$"
# 42 "data/maps/RustboroCity_House1/scripts.pory"

# 43 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_DoesntLookLikeMonToMe:
# 44 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Huh? That doesn't look anything like\n"
# 45 "data/maps/RustboroCity_House1/scripts.pory"
	.string "a {STR_VAR_1} to me.$"
# 46 "data/maps/RustboroCity_House1/scripts.pory"

# 47 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_YouDontWantToThatsOkay:
# 48 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Oh, if you don't want to, that's okay.\n"
# 49 "data/maps/RustboroCity_House1/scripts.pory"
	.string "But my POKéMON is cute, you know…$"
# 50 "data/maps/RustboroCity_House1/scripts.pory"

# 51 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_AnyPokemonCanBeCute:
# 52 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Any POKéMON can be cute if you raise\n"
# 53 "data/maps/RustboroCity_House1/scripts.pory"
	.string "it with care and kindness.$"
# 54 "data/maps/RustboroCity_House1/scripts.pory"

# 55 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_AllSortsOfPlaces:
# 56 "data/maps/RustboroCity_House1/scripts.pory"
	.string "In all sorts of places, there are all\n"
# 57 "data/maps/RustboroCity_House1/scripts.pory"
	.string "sorts of POKéMON and people.\p"
# 58 "data/maps/RustboroCity_House1/scripts.pory"
	.string "I find that fascinating, so I go to all\n"
# 59 "data/maps/RustboroCity_House1/scripts.pory"
	.string "sorts of places.$"
