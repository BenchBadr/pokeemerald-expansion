#include "sample_ui.h"

#include "gba/types.h"
#include "gba/defines.h"
#include "global.h"
#include "main.h"
#include "bg.h"
#include "text_window.h"
#include "window.h"
// #include "characters.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"
#include "gpu_regs.h"

#include "rtc.h"
#include "datetime.h"

#include "trig.h"
#include "graphics.h"

#include "comfy_anim.h"

#include "global.h"

#include "pokedex.h"
#include "option_menu.h"
#include "trainer_card.h"
#include "dexnav.h"
#include "region_map.h"
#include "quests.h"




#define CURSOR_SPRITE_ID                sSampleUiState->spriteIDs[1]


#define PALETTE_TAG_ROTOM               0x1000
#define TILE_TAG_ROTOM                  0x2000
#define TAG_CURSOR                      55121
#define TAG_SAVE_ICON                   60000

#define INIT_X_MENU_OPTIONS 35
#define INIT_Y_MENU_OPTIONS 60
#define GAP_MENU_OPTIONS 54
#define CURSOR_Y_SHIFT 20


struct SampleUiState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 mode;
    u8 cursorX;
    u8 cursorY;
    u8 spriteIDs[3];

    // cursor state
    u8 comfyAnimX;
    u8 comfyAnimY;
};

enum WindowIds
{
    WINDOW_0
};


static void SpriteCallback_Cursor(struct Sprite *sprite);
static void SampleUi_InitCursorMove(s16 targetX, s16 targetY);
static void HandleSelection(void);
static void CB2_OpenTrainerCardFromSampleUi(void);


static EWRAM_DATA struct SampleUiState *sSampleUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static EWRAM_DATA u8 sSavedCursorX = 0;
static EWRAM_DATA u8 sSavedCursorY = 0;




static const struct BgTemplate sSampleUiBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    }
};

static const struct WindowTemplate sSampleUiWindowTemplates[] =
{
    [WINDOW_0] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 20,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};






static const struct SpriteSheet sRotomSpriteSheet =
{
    .data = sRotom_Gfx,
    .size = sizeof(sRotom_Gfx),
    .tag = TILE_TAG_ROTOM
};


static void SpriteCallback_RotomJump(struct Sprite *sprite)
{
    sprite->data[0] += 4;
    
    sprite->y2 = -((gSineTable[sprite->data[0] & 0xFF]) >> 7);
}

static const struct OamData sRotomOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32), 
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .priority = 0,
};




static const struct SpritePalette sRotomSpritePalette =
{
    .data = sRotom_Pal,
    .tag = PALETTE_TAG_ROTOM
};

static const struct SpriteTemplate sRotomSpriteTemplate =
{
    .tileTag = TILE_TAG_ROTOM,
    .paletteTag = PALETTE_TAG_ROTOM,
    .oam = &sRotomOam,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_RotomJump,
};


static const struct CompressedSpriteSheet sSpriteSheet_Cursor =
{
    .data = sCursor_Gfx,
    .size = (16 * 16 * 3) / 2,
    .tag = TAG_CURSOR
};

static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = PALETTE_TAG_ROTOM,
    .oam = &sOamData_Cursor,
    .anims = sAnims_Cursor,
    .callback = SpriteCallback_Cursor
};

// static const struct SpriteTemplate sSpriteTemplate_SaveIcon =
// {
//     .tileTag = TAG_SAVE_ICON,
//     .paletteTag = PALETTE_TAG_ROTOM, // change if it has its own palette
//     .oam = &sSaveIconOam,
//     .anims = sSaveIconAnims,
//     .images = sSaveIconImages,
//     .affineAnims = gDummySpriteAffineAnimTable,
//     .callback = SpriteCallbackDummy,
// };



enum FontColor
{
    FONT_WHITE,
    FONT_RED
};
static const u8 sSampleUiWindowFontColors[][3] =
{
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_RED},
};

// Callbacks for the sample UI
static void SampleUi_SetupCB(void);
static void SampleUi_MainCB(void);
static void SampleUi_VBlankCB(void);

// Sample UI tasks
static void Task_SampleUiWaitFadeIn(u8 taskId);
static void Task_SampleUiMainInput(u8 taskId);
static void Task_SampleUiWaitFadeAndBail(u8 taskId);
static void Task_SampleUiWaitFadeAndExitGracefully(u8 taskId);

// Sample UI helper functions
static void SampleUi_Init(MainCallback callback);
static void SampleUi_ResetGpuRegsAndBgs(void);
static bool8 SampleUi_InitBgs(void);
static void SampleUi_FadeAndBail(void);
static bool8 SampleUi_LoadGraphics(void);
static void SampleUi_InitWindows(void);
static void SampleUi_PrintUiSampleWindowText(void);
static void SampleUi_DisplaySprites(void);
static void SampleUi_FreeResources(void);

static void GetCurrentDateTime(struct DateTime* dateTime);
static void BuildDateTimeString(void);

// Declared in sample_ui.h
void Task_OpenSampleUi_BlankTemplate(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        PlayCry_NormalNoDucking(SPECIES_ROTOM,  0, CRY_VOLUME_RS, CRY_PRIORITY_NORMAL);
        CleanupOverworldWindowsAndTilemaps();
        SampleUi_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

static void SampleUi_Init(MainCallback callback)
{
    sSampleUiState = AllocZeroed(sizeof(struct SampleUiState));
    if (sSampleUiState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    
    sSampleUiState->loadState = 0;
    sSampleUiState->savedCallback = callback;

    sSampleUiState->comfyAnimX = INVALID_COMFY_ANIM;
    sSampleUiState->comfyAnimY = INVALID_COMFY_ANIM;

    sSampleUiState->cursorX = sSavedCursorX;
    sSampleUiState->cursorY = sSavedCursorY;


    CURSOR_SPRITE_ID = MAX_SPRITES;

    SetMainCallback2(SampleUi_SetupCB);
}



// Credit: Jaizu, pret
static void SampleUi_ResetGpuRegsAndBgs(void)
{
    /*
     * TODO : these settings are overkill, and seem to be clearing some
     * important values. I need to come back and investigate this. For now, they
     * are disabled. Note: by not resetting the various BG and GPU regs, we are
     * effectively assuming that the user of this UI is entering from the
     * overworld. If this UI is entered from a different screen, it's possible
     * some regs won't be set correctly. In that case, you'll need to figure
     * out which ones you need.
     */
    // SetGpuReg(REG_OFFSET_DISPCNT, 0);
    // SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON);
    // SetGpuReg(REG_OFFSET_BG3CNT, 0);
    // SetGpuReg(REG_OFFSET_BG2CNT, 0);
    // SetGpuReg(REG_OFFSET_BG1CNT, 0);
    // SetGpuReg(REG_OFFSET_BG0CNT, 0);
    // ChangeBgX(0, 0, BG_COORD_SET);
    // ChangeBgY(0, 0, BG_COORD_SET);
    // ChangeBgX(1, 0, BG_COORD_SET);
    // ChangeBgY(1, 0, BG_COORD_SET);
    // ChangeBgX(2, 0, BG_COORD_SET);
    // ChangeBgY(2, 0, BG_COORD_SET);
    // ChangeBgX(3, 0, BG_COORD_SET);
    // ChangeBgY(3, 0, BG_COORD_SET);
    // SetGpuReg(REG_OFFSET_BLDCNT, 0);
    // SetGpuReg(REG_OFFSET_BLDY, 0);
    // SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    // SetGpuReg(REG_OFFSET_WIN0H, 0);
    // SetGpuReg(REG_OFFSET_WIN0V, 0);
    // SetGpuReg(REG_OFFSET_WIN1H, 0);
    // SetGpuReg(REG_OFFSET_WIN1V, 0);
    // SetGpuReg(REG_OFFSET_WININ, 0);
    // SetGpuReg(REG_OFFSET_WINOUT, 0);
    // CpuFill16(0, (void *)VRAM, VRAM_SIZE);
    // CpuFill32(0, (void *)OAM, OAM_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT,
    DISPCNT_MODE_0
    | DISPCNT_OBJ_ON
    | DISPCNT_OBJ_1D_MAP);
}

static void SampleUi_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        SampleUi_ResetGpuRegsAndBgs();
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();

        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (SampleUi_InitBgs())
        {
            sSampleUiState->loadState = 0;
            gMain.state++;
        }
        else
        {
            SampleUi_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (SampleUi_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        SampleUi_InitWindows();
        gMain.state++;
        break;
    case 5:
        SampleUi_PrintUiSampleWindowText();
        SampleUi_DisplaySprites();
        CreateTask(Task_SampleUiWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(SampleUi_VBlankCB);
        SetMainCallback2(SampleUi_MainCB);
        break;
    }
}

static void SampleUi_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void SampleUi_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_SampleUiWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_SampleUiMainInput;
    }
}

static void Task_SampleUiMainInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_SampleUiWaitFadeAndExitGracefully;
    }
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        HandleSelection();
    }
    if (JOY_NEW(DPAD_LEFT))
    {

        sSampleUiState->cursorX--;

        SampleUi_InitCursorMove(
            INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS * (sSampleUiState->cursorX % 3),
            INIT_Y_MENU_OPTIONS - CURSOR_Y_SHIFT + GAP_MENU_OPTIONS * (sSampleUiState->cursorY % 2)
        );


        PlaySE(SE_SELECT);

    }

    if (JOY_NEW(DPAD_RIGHT))
    {

        sSampleUiState->cursorX++;

        SampleUi_InitCursorMove(
            INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS * (sSampleUiState->cursorX % 3),
            INIT_Y_MENU_OPTIONS - CURSOR_Y_SHIFT + GAP_MENU_OPTIONS * (sSampleUiState->cursorY % 2)
        );

        PlaySE(SE_SELECT);

    }

    if (JOY_NEW(DPAD_UP))
    {

        sSampleUiState->cursorY++;

        SampleUi_InitCursorMove(
            INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS * (sSampleUiState->cursorX % 3),
            INIT_Y_MENU_OPTIONS - CURSOR_Y_SHIFT + GAP_MENU_OPTIONS * (sSampleUiState->cursorY % 2)
        );

        PlaySE(SE_SELECT);

    }

    if (JOY_NEW(DPAD_DOWN))
    {

        sSampleUiState->cursorY--;

        SampleUi_InitCursorMove(
            INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS * (sSampleUiState->cursorX % 3),
            INIT_Y_MENU_OPTIONS - CURSOR_Y_SHIFT + GAP_MENU_OPTIONS * (sSampleUiState->cursorY % 2)
        );

        PlaySE(SE_SELECT);

    }
}

static void Task_SampleUiWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSampleUiState->savedCallback);
        SampleUi_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_SampleUiWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSampleUiState->savedCallback);
        SampleUi_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 SampleUi_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sSampleUiBgTemplates, NELEMS(sSampleUiBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void SampleUi_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_SampleUiWaitFadeAndBail, 0);
    SetVBlankCallback(SampleUi_VBlankCB);
    SetMainCallback2(SampleUi_MainCB);
}

static bool8 SampleUi_LoadGraphics(void)
{
    switch (sSampleUiState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sSampleUiTiles, 0, 0, 0);
        sSampleUiState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderVram(sSampleUiTilemap, sBg1TilemapBuffer);
            sSampleUiState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sSampleUiPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sSampleUiState->loadState++;
    default:
        sSampleUiState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void SampleUi_InitWindows(void)
{
    InitWindows(sSampleUiWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WINDOW_0, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_0);
    CopyWindowToVram(WINDOW_0, 3);
}

static const u8 sText_Text1[] = _("Hello, world!");
static const u8 sText_Text2[] = _("Press {A_BUTTON} to make a sound!");

static const u8 sText_Pokedex[] =  _(" Pokédex  ");
static const u8 sText_Maps[] =     _("   Maps   ");
static const u8 sText_DexNav[] =   _("  DexNav  ");

static const u8 sText_Notes[] =    _("   Notes  ");
static const u8 sText_Card[] =     _("   Card   ");
static const u8 sText_Settings[] = _(" Settings ");



static void SampleUi_PrintUiSampleWindowText(void)
{
    FillWindowPixelBuffer(WINDOW_0, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    
    BuildDateTimeString();


    AddTextPrinterParameterized4(WINDOW_0, FONT_SMALL, 0, 0, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, gStringVar4);

    AddTextPrinterParameterized4(WINDOW_0, FONT_SMALL, INIT_X_MENU_OPTIONS, INIT_Y_MENU_OPTIONS, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_Pokedex);


    AddTextPrinterParameterized4(WINDOW_0, FONT_SMALL, INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS, INIT_Y_MENU_OPTIONS, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_Maps);


    AddTextPrinterParameterized4(WINDOW_0, FONT_SMALL, INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS * 2, INIT_Y_MENU_OPTIONS, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_DexNav);

    AddTextPrinterParameterized4(WINDOW_0, FONT_SMALL, INIT_X_MENU_OPTIONS, INIT_Y_MENU_OPTIONS + GAP_MENU_OPTIONS, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_Notes);

    AddTextPrinterParameterized4(WINDOW_0, FONT_SMALL, INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS, INIT_Y_MENU_OPTIONS + GAP_MENU_OPTIONS, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_Card);

    AddTextPrinterParameterized4(WINDOW_0, FONT_SMALL, INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS * 2, INIT_Y_MENU_OPTIONS + GAP_MENU_OPTIONS, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_Settings);

    CopyWindowToVram(WINDOW_0, COPYWIN_GFX);
}


static void SampleUi_DisplaySprites(void)
{

    // display rotom
    LoadSpriteSheet(&sRotomSpriteSheet);
    LoadSpritePalette(&sRotomSpritePalette);
    sSampleUiState->spriteIDs[0] =
        CreateSprite(&sRotomSpriteTemplate, 224, 130, 0);
    
    LoadCompressedSpriteSheet(&sSpriteSheet_Cursor);
    CURSOR_SPRITE_ID =
        CreateSprite(
            &sSpriteTemplate_Cursor,
            INIT_X_MENU_OPTIONS + GAP_MENU_OPTIONS * (sSampleUiState->cursorX % 3),
            INIT_Y_MENU_OPTIONS - CURSOR_Y_SHIFT
                + GAP_MENU_OPTIONS * (sSampleUiState->cursorY % 2),
            0);
}


static void SampleUi_FreeResources(void)
{
    if (sSampleUiState != NULL)
    {
        Free(sSampleUiState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}


// Date time display


static void GetCurrentDateTime(struct DateTime* dateTime)
{
    RtcCalcLocalTime();
    ConvertTimeToDateTime(dateTime, &gLocalTime);
}


static const u8* const sMonthNames[13] = {
    [MONTH_JAN] = COMPOUND_STRING("Jan"), [MONTH_FEB] = COMPOUND_STRING("Feb"), [MONTH_MAR] = COMPOUND_STRING("Mar"),
    [MONTH_APR] = COMPOUND_STRING("Apr"), [MONTH_MAY] = COMPOUND_STRING("May"), [MONTH_JUN] = COMPOUND_STRING("Jun"),
    [MONTH_JUL] = COMPOUND_STRING("Jul"), [MONTH_AUG] = COMPOUND_STRING("Aug"), [MONTH_SEP] = COMPOUND_STRING("Sep"),
    [MONTH_OCT] = COMPOUND_STRING("Oct"), [MONTH_NOV] = COMPOUND_STRING("Nov"), [MONTH_DEC] = COMPOUND_STRING("Dec"),
};

static const u8* const sWeekdayNames[WEEKDAY_COUNT] = {
    [WEEKDAY_SUN] = COMPOUND_STRING("Sun"), [WEEKDAY_MON] = COMPOUND_STRING("Mon"),
    [WEEKDAY_TUE] = COMPOUND_STRING("Tue"), [WEEKDAY_WED] = COMPOUND_STRING("Wed"),
    [WEEKDAY_THU] = COMPOUND_STRING("Thu"), [WEEKDAY_FRI] = COMPOUND_STRING("Fri"),
    [WEEKDAY_SAT] = COMPOUND_STRING("Sat"),
};


static void BuildDateTimeString(void)
{
    const u8* text = COMPOUND_STRING("{STR_VAR_1}. {STR_VAR_2}, {STR_VAR_3}");
    struct DateTime dt;
    RtcCalcLocalTime();
    GetCurrentDateTime(&dt);

    DebugPrintf("%d %d %d", dt.day, dt.month, dt.year);

    StringCopy(gStringVar1, sWeekdayNames[dt.dayOfWeek]);
    ConvertIntToDecimalStringN(gStringVar2, dt.day, STR_CONV_MODE_LEADING_ZEROS, 2);

    ConvertIntToDecimalStringN(gStringVar3, dt.hour, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringAppend(gStringVar3, COMPOUND_STRING(":"));
    ConvertIntToDecimalStringN(gStringVar4, dt.minute, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringAppend(gStringVar3, gStringVar4);

    StringExpandPlaceholders(gStringVar4, text);
}


static void SpriteCallback_Cursor(struct Sprite *sprite)
{
    AdvanceComfyAnimations();

    if (sSampleUiState->comfyAnimX != INVALID_COMFY_ANIM)
    {
        struct ComfyAnim *anim = &gComfyAnims[sSampleUiState->comfyAnimX];

        if (anim->inUse)
        {
            sprite->x = ReadComfyAnimValueSmooth(anim);

            if (anim->completed)
            {
                ReleaseComfyAnim(sSampleUiState->comfyAnimX);
                sSampleUiState->comfyAnimX = INVALID_COMFY_ANIM;
            }
        }
        else
        {
            sSampleUiState->comfyAnimX = INVALID_COMFY_ANIM;
        }
    }

    if (sSampleUiState->comfyAnimY != INVALID_COMFY_ANIM)
    {
        struct ComfyAnim *anim = &gComfyAnims[sSampleUiState->comfyAnimY];

        if (anim->inUse)
        {
            sprite->y = ReadComfyAnimValueSmooth(anim);

            if (anim->completed)
            {
                ReleaseComfyAnim(sSampleUiState->comfyAnimY);
                sSampleUiState->comfyAnimY = INVALID_COMFY_ANIM;
            }
        }
        else
        {
            sSampleUiState->comfyAnimY = INVALID_COMFY_ANIM;
        }
    }
}

static void SampleUi_InitCursorMove(s16 targetX, s16 targetY)
{
    struct ComfyAnimEasingConfig config;

    // Release old anims
    if (sSampleUiState->comfyAnimX != INVALID_COMFY_ANIM)
        ReleaseComfyAnim(sSampleUiState->comfyAnimX);

    if (sSampleUiState->comfyAnimY != INVALID_COMFY_ANIM)
        ReleaseComfyAnim(sSampleUiState->comfyAnimY);

    InitComfyAnimConfig_Easing(&config);
    config.durationFrames = 8;
    config.easingFunc = ComfyAnimEasing_EaseOutCubic;

    // X
    config.from = Q_24_8(gSprites[CURSOR_SPRITE_ID].x);
    config.to = Q_24_8(targetX);
    sSampleUiState->comfyAnimX = CreateComfyAnim_Easing(&config);

    // Y
    config.from = Q_24_8(gSprites[CURSOR_SPRITE_ID].y);
    config.to = Q_24_8(targetY);
    sSampleUiState->comfyAnimY = CreateComfyAnim_Easing(&config);
}


static void CB2_ReturnToSampleUi(void)
{
    // wipe VRAM/OAM garbage
    ResetSpriteData();
    ResetTasks();
    CpuFill16(0, (void *)VRAM, VRAM_SIZE);
    CpuFill32(0, (void *)OAM, OAM_SIZE);

    gMain.state = 0;

    SetVBlankHBlankCallbacksToNull();
    ResetAllBgsCoordinates();
    SampleUi_Init(CB2_ReturnToFieldWithOpenMenu);
}


static void CB2_OpenTrainerCardFromSampleUi(void)
{
    ShowPlayerTrainerCard(CB2_ReturnToSampleUi);
}





static void Task_TransitionOut(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    MainCallback openApp = (MainCallback)(((u32)(u16)gTasks[taskId].data[1] << 16) 
                                         | (u16)gTasks[taskId].data[0]);

    gMain.savedCallback = CB2_ReturnToSampleUi;
    SampleUi_FreeResources();

    DestroyTask(taskId);
    SetMainCallback2(openApp);
}

static void OpenApp(MainCallback openApp)
{

    sSavedCursorX = sSampleUiState->cursorX;
    sSavedCursorY = sSampleUiState->cursorY;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);

    
    u8 taskId = CreateTask(Task_TransitionOut, 0);
    gTasks[taskId].data[0] = (u16)((u32)openApp);
    gTasks[taskId].data[1] = (u16)(((u32)openApp) >> 16);
}



static void HandleSelection(void) 
{

    u8 gridX = sSampleUiState->cursorX % 3;
    u8 gridY = sSampleUiState->cursorY % 2;

    // Pokédex
    if (gridX == 0 && gridY == 0)
    {
        // BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        OpenApp(CB2_OpenPokedex);
    }

    // Maps
    if (gridX == 1 && gridY == 0)
    {
        sSavedCursorX = sSampleUiState->cursorX;
        sSavedCursorY = sSampleUiState->cursorY;

        // todo...

    }

    // Dexnav
    if (gridX == 2 && gridY == 0)
    {
        sSavedCursorX = sSampleUiState->cursorX;
        sSavedCursorY = sSampleUiState->cursorY;

        gMain.savedCallback = CB2_ReturnToSampleUi;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        CreateTask(Task_OpenDexNavFromStartMenu, 0);
    }

    // Quests
    if (gridX == 0 && gridY == 1) {
        sSavedCursorX = sSampleUiState->cursorX;
        sSavedCursorY = sSampleUiState->cursorY;
        gMain.savedCallback = CB2_ReturnToSampleUi;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        CreateTask(Task_QuestMenu_OpenFromStartMenu, 0);
    }


    // Card
    if (gridX == 1 && gridY == 1)
    {
        OpenApp(CB2_OpenTrainerCardFromSampleUi);
    }

    // Settings
    if (gridX == 2 && gridY == 1)
    {
        // BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        OpenApp(CB2_InitOptionMenu);
    }
}