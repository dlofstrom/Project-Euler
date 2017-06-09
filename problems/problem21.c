#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    unsigned int sum = 0;

    unsigned int i;
    unsigned int di;
    for (i = 0; i < 10000; i++) {
        di = sum_of_divisors(i);
        if (di != i && sum_of_divisors(di) == i) sum += i;
    }
    
    printf("Answer: %u\n", sum);
}
