#include "global.h"
#include "trainer_rank.h"

#include "event_data.h"

// The points required to beat each rank.
// Index 0 requires 16 pts to reach Index 1. Index 4 requires 0 (Max).
const u16 gRankThresholds[] = {16, 32, 64, 128, 0}; 

#define MAX_RANK (ARRAY_COUNT(gRankThresholds) - 1)



u8 GetTrainerRank(void)
{
    return gSaveBlock2Ptr->trainerRank;
}

u16 GetTrainerPoints(void)
{
    return gSaveBlock2Ptr->trainerPoints;
}

u8 GetRankGoal(void)
{
    return gRankThresholds[GetTrainerRank()];
}

void AddTrainerPoints(u8 points)
{
    u8 goal = GetRankGoal();
    u8 newPoints = gSaveBlock2Ptr->trainerPoints + points; 

    gSaveBlock2Ptr->trainerPoints = (newPoints > goal) ? goal : newPoints;
}



// Poryscript Helpers

void Script_AddTrainerPoints(void)
{
    u8 points = gSpecialVar_0x8004;
    AddTrainerPoints(points);
}

void Script_ResetPoints(u8 points) 
{
    gSaveBlock2Ptr->trainerPoints = 0;
}