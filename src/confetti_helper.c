#include "global.h"
#include "task.h"
#include "sprite.h"
#include "graphics.h"
#include "decompress.h"
#include "trig.h"
#include "random.h"
#include "confetti_helper.h"

#define TAG_CONFETTI 1001

static EWRAM_DATA u8 sConfettiTaskId = 0;

static const struct CompressedSpriteSheet sSpriteSheet_Confetti[] =
{
    {.data = gConfetti_Gfx, .size = 0x220, .tag = TAG_CONFETTI},
    {},
};

static const struct SpritePalette sSpritePalette_Confetti[] =
{
    {.data = gConfetti_Pal, .tag = TAG_CONFETTI},
    {},
};

static const struct OamData sOamData_Confetti =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PinkConfettiA[]   = { ANIMCMD_FRAME(0, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_RedConfettiA[]    = { ANIMCMD_FRAME(1, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_BlueConfettiA[]   = { ANIMCMD_FRAME(2, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_RedConfettiB[]    = { ANIMCMD_FRAME(3, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_BlueConfettiB[]   = { ANIMCMD_FRAME(4, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_YellowConfettiA[] = { ANIMCMD_FRAME(5, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_WhiteConfettiA[]  = { ANIMCMD_FRAME(6, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_GreenConfettiA[]  = { ANIMCMD_FRAME(7, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_PinkConfettiB[]   = { ANIMCMD_FRAME(8, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_BlueConfettiC[]   = { ANIMCMD_FRAME(9, 30),  ANIMCMD_END };
static const union AnimCmd sAnim_YellowConfettiB[] = { ANIMCMD_FRAME(10, 30), ANIMCMD_END };
static const union AnimCmd sAnim_WhiteConfettiB[]  = { ANIMCMD_FRAME(11, 30), ANIMCMD_END };
static const union AnimCmd sAnim_GreenConfettiB[]  = { ANIMCMD_FRAME(12, 30), ANIMCMD_END };
static const union AnimCmd sAnim_PinkConfettiC[]   = { ANIMCMD_FRAME(13, 30), ANIMCMD_END };
static const union AnimCmd sAnim_RedConfettiC[]    = { ANIMCMD_FRAME(14, 30), ANIMCMD_END };
static const union AnimCmd sAnim_YellowConfettiC[] = { ANIMCMD_FRAME(15, 30), ANIMCMD_END };
static const union AnimCmd sAnim_WhiteConfettiC[]  = { ANIMCMD_FRAME(16, 30), ANIMCMD_END };

static const union AnimCmd *const sAnims_Confetti[] =
{
    sAnim_PinkConfettiA,
    sAnim_RedConfettiA,
    sAnim_BlueConfettiA,
    sAnim_RedConfettiB,
    sAnim_BlueConfettiB,
    sAnim_YellowConfettiA,
    sAnim_WhiteConfettiA,
    sAnim_GreenConfettiA,
    sAnim_PinkConfettiB,
    sAnim_BlueConfettiC,
    sAnim_YellowConfettiB,
    sAnim_WhiteConfettiB,
    sAnim_GreenConfettiB,
    sAnim_PinkConfettiC,
    sAnim_RedConfettiC,
    sAnim_YellowConfettiC,
    sAnim_WhiteConfettiC
};

static void SpriteCB_HofConfetti(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_HofConfetti =
{
    .tileTag = TAG_CONFETTI,
    .paletteTag = TAG_CONFETTI,
    .oam = &sOamData_Confetti,
    .anims = sAnims_Confetti,
    .callback = SpriteCB_HofConfetti
};


#define sPhase     data[0]
#define sFreq      data[1]
#define sAmp       data[2]
#define sFallSpeed data[3]

static void SpriteCB_HofConfetti(struct Sprite *sprite)
{
    sprite->sPhase += sprite->sFreq;
    sprite->x2 = Sin((sprite->sPhase >> 8) & 0xFF, sprite->sAmp) >> 4;
    sprite->y += sprite->sFallSpeed;

    if (sprite->y > DISPLAY_HEIGHT + 8)
        DestroySprite(sprite);
}

#undef sPhase
#undef sFreq
#undef sAmp
#undef sFallSpeed

static bool8 CreateHofConfettiSprite(void)
{
    u8 spriteId;

    if (GetSpriteTileStartByTag(TAG_CONFETTI) == 0xFFFF)
    {
        LoadCompressedSpriteSheet(sSpriteSheet_Confetti);
        LoadSpritePalette(sSpritePalette_Confetti);
    }

    spriteId = CreateSprite(&sSpriteTemplate_HofConfetti, Random() % DISPLAY_WIDTH, -8, 0);
    if (spriteId != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[spriteId], Random() % 17);
        gSprites[spriteId].data[0] = Random() & 0xFFFF;
        gSprites[spriteId].data[1] = 0x100 + (Random() & 0x7F);
        gSprites[spriteId].data[2] = 4 + (Random() & 7);
        gSprites[spriteId].data[3] = 1 + (Random() & 1);
    }
    return FALSE;
}

void FreeHofConfettiGfx(void)
{
    FreeSpriteTilesByTag(TAG_CONFETTI);
    FreeSpritePaletteByTag(TAG_CONFETTI);
}

#define tFrameCount data[0]

static void Task_HofConfettiRunner(u8 taskId)
{
    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;

        // Spawn a new confetti particle every 4th frame for the first 290 frames
        // For the last 110 frames wait for existing confetti to fall offscreen
        if ((gTasks[taskId].tFrameCount & 3) == 0 && gTasks[taskId].tFrameCount > 110)
            CreateHofConfettiSprite();
    }
    else
    {
        FreeHofConfettiGfx();
        DestroyTask(taskId);
    }
}

#undef tFrameCount

void StartHofConfetti(u16 durationFrames)
{
    // minimum : 120
    // Due to how Task works (last 110 wait)
    if (durationFrames < 120)
        durationFrames = 120;

    sConfettiTaskId = CreateTask(Task_HofConfettiRunner, 0);

    gTasks[sConfettiTaskId].data[0] = durationFrames;
}

void StopHofConfetti(void)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].inUse && gSprites[i].template == &sSpriteTemplate_HofConfetti)
        {
            DestroySprite(&gSprites[i]);
        }
    }

    FreeHofConfettiGfx();

    if (sConfettiTaskId != 0)
    {
        DestroyTask(sConfettiTaskId);
        sConfettiTaskId = 0;
    }
}