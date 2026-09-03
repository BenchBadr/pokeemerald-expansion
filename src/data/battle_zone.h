#include "constants/opponents.h"

struct MatchmakingOpponent
{
    u16 trainerId;
    u16 graphicsId;
    const u8 *speechBefore;
    const u8 *speechAfter;
    u8 pts;
};


static const struct MatchmakingOpponent sMatchmakingPool[] =
{
    {
        .trainerId = TRAINER_SAWYER_1,
        .graphicsId = OBJ_EVENT_GFX_CAMPER,
        .speechBefore = COMPOUND_STRING("Let's see what you've got!"),
        .speechAfter = COMPOUND_STRING("Crushed like a pebble..."),
        .pts = 5
    },
    {
        .trainerId = TRAINER_ALBERTO,
        .graphicsId = OBJ_EVENT_GFX_LASS,
        .speechBefore = COMPOUND_STRING("My Pokémon are ready for this!"),
        .speechAfter = COMPOUND_STRING("Oh no, we lost!"),
        .pts = 5
    },
};