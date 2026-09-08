#ifndef SAMPLE_UI_H
#define SAMPLE_UI_H

#include "gba/types.h"
#include "sprite.h"


static const u32 sCursor_Gfx[] = INCGFX_U32("graphics/party_menu/swsh/cursor.png", ".4bpp.smol");

static const struct OamData sOamData_Cursor =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};





static const union AnimCmd sAnim_Cursor[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Cursor[] =
{
    sAnim_Cursor,
};



static const u16 sRotom_Pal[] = INCGFX_U16("graphics/sample_ui/rotom.png", ".gbapal");
static const u32 sRotom_Gfx[] = INCGFX_U32("graphics/sample_ui/rotom.png", ".4bpp");

static const u32 sSampleUiTiles[] = INCBIN_U32("graphics/sample_ui/tiles.4bpp.lz");
static const u32 sSampleUiTilemap[] = INCBIN_U32("graphics/sample_ui/tilemap.bin.lz");
static const u16 sSampleUiPalette[] = INCBIN_U16("graphics/sample_ui/00.gbapal");

// static const u32 sSaveIcon_Gfx[] = INCGFX_U32("graphics/sample_ui/save_icon.png", ".4bpp");

/*
 * Entry tasks for the different versions of the UI. In `start_menu.c', we'll launch a task using one of
 * these functions. You can change which is used to change which menu is launched.
 */

// Launch the blank template version of the UI
void Task_OpenSampleUi_BlankTemplate(u8 taskId);

#endif