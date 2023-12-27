#include <stdlib.h>
#include <time.h>

#include "../src/mines-initializer.h"
#include "Unity/src/unity.h"

uint8_t **game_map;
uint8_t x;
uint8_t y;

void setUp(void)
{
    int i;
    srand(time(NULL));

    x = (rand() % 5) + 5;
    y = (rand() % 5) + 5;

    game_map = malloc(x * sizeof(uint8_t*));
    TEST_ASSERT_NOT_NULL(game_map);

    for (i = 0; i < x; i++) {
        int j;

        game_map[i] = malloc(y * sizeof(uint8_t));
        TEST_ASSERT_NOT_NULL(game_map[i]);

        for (j = 0; j < y; j++) {
            game_map[i][j] = rand() % UINT8_MAX;
        }
    }
}

void tearDown(void)
{
    int i;
    for (i = 0; i < x; i++) {
        free(game_map[i]);
    }

    free(game_map);
}

/* TODO (GM): Put a real test here later! */
void test_init_map(void)
{
    int i;
    init_map(game_map, x, y);

    for (i = 0; i < x; i++) {
        int j = 0;
        for (; j < y; j++) {
            TEST_ASSERT_TRUE(game_map[i][j] == 0 || game_map[i][j] == 1);
        }
    }
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_init_map);

    return UNITY_END();
}
