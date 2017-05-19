#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    uint64_t n;
    uint64_t N = 0;
    uint32_t d = 1;
    uint64_t t;
    for (n = 1; d < 500; n++) {
        //Calculate triangle number for number "n"
        N += n;

        //Count divisors
        d = 0;
        for (t = 1; t <= sqrt(N); t++) {
            if (N % t == 0) {
                d += 2;
                if (N / t == t) d -= 1;
            }
        }
    }
    
    printf("Answer %llu\n", N);
}
