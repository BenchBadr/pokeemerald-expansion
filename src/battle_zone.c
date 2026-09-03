#include "global.h"
#include "event_data.h"
#include "random.h"
#include "string_util.h"
#include "constants/event_objects.h"

#include "constants/opponents.h"
#include "constants/trainers.h"



// Include your data file here
#include "data/battle_zone.h"
#include "battle_setup.h"
#include "pokemon.h"

#include "pokemon_icon.h"




#include "pokemon.h"
#include "debug.h"
#include "data.h"

static const struct MatchmakingOpponent *opp = 0;



void Script_SetupRandomOpponent(void)
{
    u16 index = Random() % ARRAY_COUNT(sMatchmakingPool);
    opp = &sMatchmakingPool[index];

    StringCopy(gStringVar1, GetTrainerNameFromId(opp->trainerId));

    // gSpecialVar_0x8004 = opp->graphicsId;    // Graphics ID for VAR_OBJ_GFX_ID_0

}


void Script_LoadTrainerID(void)
{
    DebugPrintf("In theory... %d", opp->trainerId);
    gSpecialVar_0x8007 = opp->trainerId;
}

void Script_LoadOpponentSpeech(void)
{

    StringCopy(gStringVar1, GetTrainerNameFromId(opp->trainerId));
    StringCopy(gStringVar2, opp->speechBefore);
    StringCopy(gStringVar3, opp->speechAfter);

    opp = 0;

}
