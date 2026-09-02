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





#include "global.h"
#include "pokemon.h"
#include "debug.h"



void Script_SetupRandomOpponent(void)
{
    u8 index = Random() % ARRAY_COUNT(sMatchmakingPool);
    const struct MatchmakingOpponent *opp = &sMatchmakingPool[index];

    // ShowOppParty(opp->trainerId);

    // gSpecialVar_0x8005 = opp->trainerId;
    // gSpecialVar_0x8004 = opp->graphicsId;    // Graphics ID for VAR_OBJ_GFX_ID_0
    
    // Copy text strings so script msgboxes can read them
    StringCopy(gStringVar1, opp->speechBefore);
    StringCopy(gStringVar3, opp->speechAfter);
}