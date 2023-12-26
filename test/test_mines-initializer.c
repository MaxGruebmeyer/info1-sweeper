#include "../src/mines-initializer.h"
#include "Unity/src/unity.h"

void setUp(void)
{
    /* Put setup calls here */
}

void tearDown(void)
{
    /* Put cleanup calls here */
}

/* TODO (GM): Put a real test here later! */
void test_init_map(void)
{
    TEST_ASSERT_EQUAL(1, 1);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_init_map);

    return UNITY_END();
}
