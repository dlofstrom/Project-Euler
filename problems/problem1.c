#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    int i;
    unsigned int sum = 0;
    for (i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) sum += i;
    }
    printf("Answer: %u\n", sum);
}
