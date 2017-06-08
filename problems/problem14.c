#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

//Recursive function
unsigned int collatz(unsigned int n) {
    if (n == 1) return 1;
    else if (n % 2 == 0) return 1 + collatz(n/2);
    else return 1 + collatz(3*n + 1);
}

void problem(char *info)
{
    unsigned int longest = 0;
    unsigned int i, I, l;
    for (i = 1; i < 1000000; i++) {
        l = collatz(i);
        if (l > longest) {
            longest = l;
            I = i;
        }
    }

    printf("Answer: %u\n", I);
}
