#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    uint32_t ssum, sum, n;
    for (n = 1; n <= 100; n++) {
        sum += n;
        ssum += pow(n, 2);
    }
    sum = pow(sum, 2);
    printf("Answer: %u\n", sum - ssum);
}
