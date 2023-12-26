#include <stdlib.h>

#include "../src/mines.h"
#include "Unity/src/unity.h"

#define MAXIMUM_X 4
#define MAXIMUM_Y 5

uint8_t **test_map;

void setUp(void)
{
    int i;

    /* TODO (GM): Test this with an array later as well! */
    test_map = malloc(MAXIMUM_X);
    for (i = 0; i < MAXIMUM_X; i++) {
        test_map[i] = malloc(MAXIMUM_Y);
    }

    init(test_map, MAXIMUM_X, MAXIMUM_Y);
}

void tearDown(void)
{
    int i = 0;
    for (; i < MAXIMUM_X; i++) {
        free(test_map[i]);
    }

    free(test_map);
}

/* TODO (GM): Replace this with a real test later */
void bullshit_test(void)
{
    int i = 0;
    for ( ; i < MAXIMUM_X; i++) {
        int j = 0;
        for ( ; j < MAXIMUM_Y; j++) {
            uint8_t explosive = 0;
            open(&explosive, i, j);

            /* TODO (GM): Replace this with real assertions! */
            if (explosive) {
                TEST_ASSERT_EQUAL(1, explosive);
            }
        }
    }
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(bullshit_test);

    UNITY_END();
}
