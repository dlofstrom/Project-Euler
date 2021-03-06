#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    unsigned int ssum = 0;
    unsigned int sum = 0;
    unsigned int n;
    for (n = 1; n <= 100; n++) {
        sum += n;
        ssum += pow(n, 2);
    }
    sum = pow(sum, 2);
    printf("Answer: %u\n", sum - ssum);
}
