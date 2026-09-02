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





#include "global.h"
#include "pokemon.h"
#include "debug.h"

static void PrintSpeciesNames(u16 trainerId)
{
    u8 difficulty = GetCurrentDifficultyLevel();
    const struct Trainer *trainer = &gTrainers[difficulty][trainerId];

    DebugPrintf("Trainer ID: %d | Difficulty: %d | Party Size: %d", 
        trainerId, difficulty, trainer->partySize);

    for (u32 i = 0; i < trainer->partySize; i++)
    {
        u16 species = SPECIES_NONE;
        u8 level = 0;

        DebugPrintf("  Mon %d: %d (Lvl %d)", i + 1, trainer->party[i].species, trainer->party[i].lvl);
    }
}

void Script_SetupRandomOpponent(void)
{
    u8 index = Random() % ARRAY_COUNT(sMatchmakingPool);
    const struct MatchmakingOpponent *opp = &sMatchmakingPool[index];

    PrintSpeciesNames(opp->trainerId);

    // gSpecialVar_0x8005 = opp->trainerId;
    // gSpecialVar_0x8004 = opp->graphicsId;    // Graphics ID for VAR_OBJ_GFX_ID_0
    
    // Copy text strings so script msgboxes can read them
    StringCopy(gStringVar1, opp->speechBefore);
    StringCopy(gStringVar3, opp->speechAfter);
}