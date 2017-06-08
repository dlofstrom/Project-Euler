#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

//Sum of divisors
uint32_t d(uint32_t n) {
    uint32_t s = 0;
    uint32_t ns = (uint32_t)sqrt(n);
    uint32_t i;
    for (i = 1; i <= ns; i++) {
        if (n % i == 0) {
            //printf("%u / %u = %u\n", n, i, n/i);
            if (i == ns || i == 1) s += i;
            else s += i + n/i;
        }
    }
    return s;
}

void problem(char *info)
{
    uint32_t sum = 0;

    uint32_t i;
    uint32_t di;
    for (i = 0; i < 10000; i++) {
        di = d(i);
        if (di != i && d(di) == i) sum += i;
    }
    
    printf("Answer: %u\n", sum);
}
