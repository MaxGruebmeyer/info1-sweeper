#include "../src/mines.h"
#include "Unity/src/unity.h"

void setUp(void)
{
    /* Put setup calls here */
    init();
}

void tearDown(void)
{
    /* Put cleanup calls here */
}

/* TODO (GM): Replace this with a real test later */
void bullshit_test(void)
{
    int i = 0;
    for ( ; i < FIELD_SIZE; i++) {
        int j = 0;
        for ( ; j < FIELD_SIZE; j++) {
            int explosive = open(i, j);

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

    /* TODO (GM): Can we use e.g. reflection to call all functions in this file? */
    RUN_TEST(bullshit_test);

    UNITY_END();
}
