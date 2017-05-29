#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

//Recursive function
uint32_t collatz(uint32_t n) {
    if (n == 1) return 1;
    else if (n % 2 == 0) return 1 + collatz(n/2);
    else return 1 + collatz(3*n + 1);
}

void problem(char *info)
{
    uint32_t longest = 0;
    uint32_t i, I, l;
    for (i = 1; i < 1000000; i++) {
        l = collatz(i);
        if (l > longest) {
            longest = l;
            I = i;
        }
    }

    printf("Answer: %u\n", I);
}
