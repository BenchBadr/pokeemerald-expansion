#include "global.h"
#include "pokemon.h"
#include "event_data.h"
#include "string_util.h"
#include "strings.h"
#include "constants/battle.h"


static const u8 sStatDataFields[NUM_STATS] = 
{
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPATK_EV,
    MON_DATA_SPDEF_EV,
};

static const u8 *const sStatNames[NUM_STATS] =
{
    gText_HP4,
    gText_Attack,
    gText_Defense,
    gText_Speed,
    gText_SpAtk,
    gText_SpDef,
};

void Script_FriendshipAndStats(void)
{
    struct Pokemon *pkmn = &gPlayerParty[0];

    if (GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES) != SPECIES_NONE &&
        !GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_IS_EGG))
    {
        // change friendship
        int friendshipAmount = gSpecialVar_0x8001;
        u8 currentFriendship = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_FRIENDSHIP);
        int newFriendship = currentFriendship + friendshipAmount;

        if (newFriendship > 255)
            newFriendship = 255;

        SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_FRIENDSHIP, &newFriendship);

        // change EV
        // 0x8002 : what stat
        // 0x8003 : how much
        u8 statIndex = gSpecialVar_0x8002;
            int evChange = gSpecialVar_0x8003;

            // 0x8002: 0=HP, 1=Atk, 2=Def, 3=Speed, 4=Sp.Atk, 5=Sp.Def
            int monDataField = sStatDataFields[statIndex];

            u8 currentEv = GetMonData(pkmn, monDataField);
            int newEv = currentEv + evChange;

            if (newEv > 255)
                newEv = 255;
            if (newEv < 0)
                newEv = 0;

            SetMonData(pkmn, monDataField, &newEv);

            StringCopy(gStringVar1, sStatNames[statIndex]);
    }
}