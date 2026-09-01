#include "global.h"
#include "trainer_rank.h"

#include "event_data.h"

#include "item_icon.h"
#include "task.h"

#include "window.h"

#define TAG_ITEM_ICON_BASE 9110

EWRAM_DATA static u8 sRankIconSpriteId = 0;
EWRAM_DATA static u8 sRankBarId = 0;


#define MAX_BAR_WIDTH 64
#define BAR_HEIGHT 12


static const struct WindowTemplate sRankBarTemplate = {
    .bg = 0,
    .tilemapLeft = 10,  
    .tilemapTop = 10,
    .width = 10,        
    .height = 2,       
    .paletteNum = 15,  
    .baseBlock = 700,
};


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
    s8 goal = GetRankGoal();
    s8 newPoints = gSaveBlock2Ptr->trainerPoints + points;

    // bounds : 0 < pts < goal
    gSaveBlock2Ptr->trainerPoints = (newPoints > goal) ? goal : (newPoints < 0) ? 0 : newPoints;
}



// Poryscript Helpers

void Script_AddTrainerPoints(void)
{
    s8 points = gSpecialVar_0x8004;
    AddTrainerPoints(points);
}


////////////////////////////////////////////////////////////////////////
// Animation handling

#define tState  data[0]
#define tTimer  data[1]
#define tXPos   data[2]

#define tColor    data[3]
#define tWidth    data[4]

static void Task_AnimateRankBar(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
        case 0: // init
            tTimer = 0;
            tState = 1;
            break;

        case 1: 
            tTimer++;
            
            DebugPrintf("Color : %d", tColor);
            if (tColor == 8 || 1) {
                FillWindowPixelRect(sRankBarId, PIXEL_FILL(tColor), tXPos - tTimer, 7, tTimer, BAR_HEIGHT);
                if (tTimer >= tXPos - tWidth + 2)
                {
                    tState = 2;
                }
            } else {
                FillWindowPixelRect(sRankBarId, PIXEL_FILL(tColor), tXPos, 7, tTimer, BAR_HEIGHT);
                if (tTimer >= tWidth - tXPos + 2)
                {
                    tState = 2;
                }
            }
            


            
            CopyWindowToVram(sRankBarId, COPYWIN_GFX);


            break;

        case 2: 
            DestroyTask(taskId);
            break;
    }
}

void AnimateRankBar(s8 points) {


    if (!sRankBarId) return;


    u8 taskId = CreateTask(Task_AnimateRankBar, 0); 

    // misc inits
    gTasks[taskId].data[0] = 0; // state
    gTasks[taskId].data[1] = 0; // time 

    // x coords
    u8 adjustBase = GetTrainerPoints() * MAX_BAR_WIDTH / GetRankGoal();

    gTasks[taskId].data[2] = points < 0 ? adjustBase + points + 2 : adjustBase + 2;

    // color (if substracting, fill color = bg color)
    gTasks[taskId].data[3] = points > GetTrainerPoints() ? 15 : 8;

    // width
    gTasks[taskId].data[4] = ((points < 0 ? -points : points) * MAX_BAR_WIDTH) / GetRankGoal();



}


static const union AffineAnimCmd sPokeBallAffineAnim_Grow[] = {
    AFFINEANIMCMD_FRAME(32, 32, 32, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sPokeBallAffineAnims[] = {
    sPokeBallAffineAnim_Grow,
};


void DisplayRankBall(void) {
    sRankIconSpriteId = AddItemIconSprite(TAG_ITEM_ICON_BASE, TAG_ITEM_ICON_BASE, ITEM_POKE_BALL);
    if (sRankIconSpriteId != MAX_SPRITES)
    {
        gSprites[sRankIconSpriteId].x2 = 124;
        gSprites[sRankIconSpriteId].y2 = 72;
        gSprites[sRankIconSpriteId].oam.priority = 0;

        gSprites[sRankIconSpriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        gSprites[sRankIconSpriteId].oam.matrixNum = 0;

        InitSpriteAffineAnim(&gSprites[sRankIconSpriteId]);

        gSprites[sRankIconSpriteId].affineAnims = sPokeBallAffineAnims;

        StartSpriteAffineAnim(&gSprites[sRankIconSpriteId], 0);
    }
}

void DestroyRankBall(void) {
    if (sRankIconSpriteId != 0) {
        FreeSpriteTilesByTag(TAG_ITEM_ICON_BASE);
        FreeSpritePaletteByTag(TAG_ITEM_ICON_BASE);
        DestroySprite(&gSprites[sRankIconSpriteId]);
        sRankIconSpriteId = 0;
    }
}

void DrawRankBar(void) {
    if (sRankBarId == 0) {
        sRankBarId = AddWindow(&sRankBarTemplate);
        PutWindowTilemap(sRankBarId);
        {


            u16 fillWidth = (GetTrainerPoints() * MAX_BAR_WIDTH) / GetRankGoal();
            if (fillWidth > MAX_BAR_WIDTH) fillWidth = MAX_BAR_WIDTH;

            PutWindowTilemap(sRankBarId);

            FillWindowPixelRect(sRankBarId, PIXEL_FILL(8), 2, 7, MAX_BAR_WIDTH, BAR_HEIGHT); // bar
            FillWindowPixelRect(sRankBarId, PIXEL_FILL(15), 2, 7, fillWidth, BAR_HEIGHT); // filling
            CopyWindowToVram(sRankBarId, COPYWIN_FULL);
        }
    }
}

void DestroyRankBar(void) {

    u8 taskId = FindTaskIdByFunc(Task_AnimateRankBar);
    if (taskId != TASK_NONE)
    {
        DestroyTask(taskId);
    }

    if (sRankBarId != 0)
    {
        ClearWindowTilemap(sRankBarId);
        RemoveWindow(sRankBarId);
        CopyWindowToVram(sRankBarId, COPYWIN_MAP);
        sRankBarId = 0;
    }
}

void Script_AddTrainerPointsAnim(void)
{
    s8 points = gSpecialVar_0x8004;


    DisplayRankBall();
    DrawRankBar();


    u8 goal = GetRankGoal();
    s8 newPoints = GetTrainerPoints() + points;
    if (newPoints > goal) newPoints = goal;
    if (newPoints < 0)    newPoints = 0;

    AnimateRankBar(newPoints);

    AddTrainerPoints(points);

}

void Script_HideRankDisplay(void)
{
    DestroyRankBall();
    DestroyRankBar();
}

void Script_AddPointsClearAnim(void)
{   
}

void Script_ResetPoints(u8 points) 
{
    gSaveBlock2Ptr->trainerPoints = 0;
}