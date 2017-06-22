#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

#define MAX 1000000

void problem(char *info)
{
    unsigned int sum = 0;

    int i, n, d, s;
    for (i = 2; i <= MAX; i++) {
        //Loop iver digits of number
        n = i;
        s = 0;
        while (n != 0) {
            d = n % 10;
            n /= 10;

            //Add power to sum
            s += pow(d, 5);
        }

        //If equal to number add to total sum
        if (i == s) {
            printf("%d can be written as the sum of the fifth power\n", i);
            sum += i;
        }
    }
    
    printf("Answer: %u\n", sum);
}
