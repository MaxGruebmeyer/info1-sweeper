#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "mines-initializer.h"

void init_map(uint8_t **map, const uint8_t x, const uint8_t y)
{
    int i = 0;
    srand(time(NULL));

    for (; i < x; i++) {
        int j = 0;
        for (; j < y; j++) {
            map[i][j] = (rand() % EXPLOSION_PROBABILITY) == 0 ? 1 : 0;
        }
    }
}
