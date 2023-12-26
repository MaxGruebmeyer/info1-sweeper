/* TODO (GM): Introduce real logging! */
#include <stdlib.h>
#include <stdint.h>

#include "mines.h"
#include "mines-initializer.h"

uint8_t maximum_x = 0;
uint8_t maximum_y = 0;

/*
 * Field structure:
 * - 5 Bits for counting explosives in neighboring mines
 * - 1 Bit for open/closed (1/0)
 * - 1 Bit for flag yes/no (1/0)
 * - 1 Bit for explosive yes/no (1/0)
 */
uint8_t **map;

const uint8_t OPEN_BIT = 1 << 2;
const uint8_t FLAG_BIT = 1 << 1;
const uint8_t EXPLOSIVE_BIT = 1;

static uint8_t *get_field(const uint8_t x, const uint8_t y);

void init(uint8_t **cur_map, const uint8_t x, const uint8_t y)
{
    maximum_x = x;
    maximum_y = y;

    map = cur_map;
    init_map(map, x, y);

    /* TODO (GM): Add bits detailling how many neighbouring fields contain explosives! */
}

uint8_t flag(const uint8_t x, const uint8_t y)
{
    /* TODO (GM): Does this work? */
    uint8_t *field = get_field(x, y);
    if (!field) {
        return 0;
    }

    *field = *field | FLAG_BIT;
    return 1;
}

uint8_t unflag(const uint8_t x, const uint8_t y)
{
    uint8_t *field = get_field(x, y);
    if (!field) {
        return 0;
    }

    *field = *field & (~FLAG_BIT);
    return 1;
}

void open(uint8_t *result, const uint8_t x, const uint8_t y)
{
    uint8_t *field = get_field(x, y);

    /* TODO (GM): Can the brackets here be removed? */
    if (!field || (*field & FLAG_BIT)) {
        result = NULL;
        return;
    }

    /* TODO (GM): Check neighbouring fields and open them as well if they have no explosives nearby! */
    *result = (*field = *field | OPEN_BIT) & EXPLOSIVE_BIT;
}

static uint8_t *get_field(const uint8_t x, const uint8_t y)
{
    if (x >= maximum_x || y >= maximum_y) {
        /* TODO (GM): Logging here! */
        return NULL;
    }

    return &(map[x][y]);
}
