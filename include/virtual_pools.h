#ifndef GUARD_VIRTUAL_NPC_POOLS_H
#define GUARD_VIRTUAL_NPC_POOLS_H

#define POOL_VIR_TRAINERS   0
#define POOL_VIR_LAB        1
#define POOL_VIR_COUNT      2


static const u16 sTrainersPool[] = {
    OBJ_EVENT_GFX_BOY_1,
    OBJ_EVENT_GFX_MAN_4,
    OBJ_EVENT_GFX_MAN_5,
    OBJ_EVENT_GFX_WOMAN_5,
    OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,
    OBJ_EVENT_GFX_BEAUTY
};


static const u16 sLabPool[] = {
    OBJ_EVENT_GFX_SCIENTIST_1,
    OBJ_EVENT_GFX_SCIENTIST_2,
};


struct NpcPoolInfo {
    const u16 *sprites;
    u8 count;
};

// Grouped master table using designated initializers
static const struct NpcPoolInfo gVirtualNpcPools[POOL_VIR_COUNT] = {
    [POOL_VIR_TRAINERS] = {
        .sprites = sTrainersPool,
        .count = ARRAY_COUNT(sTrainersPool),
    },
    [POOL_VIR_LAB] = {
        .sprites = sLabPool,
        .count = ARRAY_COUNT(sLabPool),
    },
};

#endif