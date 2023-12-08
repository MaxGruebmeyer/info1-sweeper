/* TODO (GM): Remove stdio header and print statements here! -> Introduce real logging? */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "mines.h"

#define FIELD_SIZE 3
#define EXPLOSION_PROBABILITY 4

/*
 * Field structure:
 * - 5 Bits for counting explosives in neighboring mines
 * - 1 Bit for open/closed (1/0)
 * - 1 Bit for flag yes/no (1/0)
 * - 1 Bit for explosive yes/no (1/0)
 */
uint8_t map[FIELD_SIZE][FIELD_SIZE];

const uint8_t OPEN_BIT = 1 << 2;
const uint8_t FLAG_BIT = 1 << 1;
const uint8_t EXPLOSIVE_BIT = 1;

uint16_t non_explosive_count = 0;

static uint8_t *get_field(const uint8_t x, const uint8_t y)
{
    if (x >= FIELD_SIZE || y >= FIELD_SIZE) {
        /* TODO (GM): Proper error handling! */
        return NULL;
    }

    return &(map[x][y]);
}

static uint8_t generate_explosive_bit() {
    return (rand() % EXPLOSION_PROBABILITY) == 0 ? EXPLOSIVE_BIT : 0;
}

void init()
{
    int i = 0;

    /* TODO (GM): Only here to test compilation - remove later! */
    printf("Hello from field init!\n");

    for (; i < FIELD_SIZE; i++) {
        int j = 0;
        for (; j < FIELD_SIZE; j++) {
            map[i][j] = generate_explosive_bit();

            if (!(map[i][j] & EXPLOSIVE_BIT)) {
                non_explosive_count++;
            }
        }
    }

    /* TODO (GM): Set explosive bits! */
    printf("Goodbye from field init!\n");
}

void flag(const uint8_t x, const uint8_t y)
{
    /* TODO (GM): Does this work? */
    /* TODO (GM): How to unit test in C? */
    uint8_t *field = get_field(x, y);
    *field = *field | FLAG_BIT;
}

void unflag(const uint8_t x, const uint8_t y)
{
    uint8_t *field = get_field(x, y);
    *field = *field & (~FLAG_BIT);
}

uint8_t open(const uint8_t x, const uint8_t y)
{
    uint8_t explosive;
    uint8_t *field = get_field(x, y);
    *field = *field | OPEN_BIT;

    explosive = *field & EXPLOSIVE_BIT;
    if (!explosive) {
        non_explosive_count--;
    }

    return explosive;
}
