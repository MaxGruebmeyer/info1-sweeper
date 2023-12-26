#include <stdio.h>

#include "mines.h"

void print_map(uint8_t **map, const uint8_t x, const uint8_t y)
{
    int i;
    for (i = 0; i < x; i++) {
        int j = 0;
        for (; j < y; j++) {
            /* TODO (GM): x and y is swapped in the output, fix! */
            printf("%i\t", map[i][j]);
        }

        printf("\n");
    }
}

int main(void)
{
    int i = 0;
    uint8_t x = 3;
    uint8_t y = 4;

    /*
     * Variable length array (vla) warning can be disabled.
     * Even though vla is a C99 feature it has always been part of the GNU C-dialect.
     * And since we only use gcc for compilation this will work fine even though we compile to C89.
     *
     * Using a vla instead of malloc() is advantageous because the vla is allocated on the stack
     * whereas memory allocated via malloc() usually resides on the heap.
     * Furthermore memory allocated by malloc() will need to be freed while arrays do not.
     * This is a good way to avoid unintentional memory leaks.
     */
    uint8_t **map;
#pragma GCC diagnostic ignored "-Wvla"
    uint8_t map_arr_2d[x][y];
    uint8_t *map_arr_1d[x];
#pragma GCC diagnostic warning "-Wvla"

    for (i = 0; i < x; i++) {
        map_arr_1d[i] = map_arr_2d[i];
    }

    map = map_arr_1d;

    init(map, x, y);
    print_map(map, x, y);

    flag(1, 1);
    unflag(1, 1);

    return 0;
}
