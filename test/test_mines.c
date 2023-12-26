#include <stdlib.h>

#include "../src/mines.h"
#include "Unity/src/unity.h"

void setUp(void)
{
    /* TODO (GM): Setup! */
}

void tearDown(void)
{
    /* TODO (GM): Teardown! */
}

/* TODO (GM): Replace this with a real test later */
void bullshit_test(void)
{
    TEST_ASSERT_EQUAL(2, 1 + 1);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(bullshit_test);

    return UNITY_END();
}
