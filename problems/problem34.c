#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    unsigned int sum = 0;
    
    int i, f[10], ifs;
    //Precalculate digit factorial 0-9
    for (i = 0; i < 10; i++) f[i] = factorial(i);

    char d[10], *dp;
    for (i = 3; i < 1000000; i++) {
        ifs = 0;
        sprintf(d, "%d", i);
        dp = d;
        while (*dp != '\0' || ifs > i) ifs += f[*(dp++)-'0'];

        if (ifs == i) {
            //printf("%d\n", i);
            sum += i;
        }
    }
    
    printf("Answer: %u\n", sum);
}
