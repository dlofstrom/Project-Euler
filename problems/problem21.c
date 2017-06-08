#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

//Sum of divisors
unsigned int d(unsigned int n) {
    unsigned int s = 0;
    unsigned int ns = (unsigned int)sqrt(n);
    unsigned int i;
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
    unsigned int sum = 0;

    unsigned int i;
    unsigned int di;
    for (i = 0; i < 10000; i++) {
        di = d(i);
        if (di != i && d(di) == i) sum += i;
    }
    
    printf("Answer: %u\n", sum);
}
