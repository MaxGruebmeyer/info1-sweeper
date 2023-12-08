#include <stdio.h>

#include "mines.h"

int main()
{
    printf("Hello from the start of main!\n");

    init();
    flag(1, 1);
    unflag(1, 1);

    /*test from me, Marwin*/

    printf("Hello from the end of main!\n");

    return 0;
}
