struct MatchmakingOpponent
{
    u16 trainerId;
    u16 graphicsId;
    const u8 *speechBefore;
    const u8 *speechAfter;
    u8 pts;
};

static const u8 sText_SawyerBefore[] = _("Let's see what you've got!");
static const u8 sText_SawyerAfter[]  = _("Crushed like a pebble...");

static const u8 sText_LassBefore[]   = _("My Pokémon are ready for this!");
static const u8 sText_LassAfter[]    = _("Oh no, we lost!");

static const struct MatchmakingOpponent sMatchmakingPool[] =
{
    {
        .trainerId = TRAINER_SAWYER_1,
        .graphicsId = OBJ_EVENT_GFX_CAMPER,
        .speechBefore = sText_SawyerBefore,
        .speechAfter = sText_SawyerAfter,
        .pts = 5
    },
    {
        .trainerId = TRAINER_GRUNT_AQUA_HIDEOUT_2,
        .graphicsId = OBJ_EVENT_GFX_LASS,
        .speechBefore = sText_LassBefore,
        .speechAfter = sText_LassAfter,
        .pts = 5
    },
};