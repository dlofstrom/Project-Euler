#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    unsigned int sum = 0;


    int f[10000] = {1}; //Factorial number (starts at 1)
    int ft[10000] = {0}; //Temporary storage for intermediate result

    //Go through n = 1,2,...,N in N! and multiply
    int i, j, t, c;
    for (i = 1; i <= 100; i++) {
        t = i;
        c = 0;
        //Digits in n
        while (t > 0) {
            //Digits in temporary storage
            for (j = 0; j < 9999; j++) {
                ft[j+c] += f[j]*(t%10);
                //Carry
                if (ft[j+c] >= 10) {
                    ft[j+c+1] += ft[j+c]/10;
                    ft[j+c] %= 10;
                }
            }
            t /= 10;
            c++;
        }
        //Move from temporary storage to f
        for (j = 0; j < 10000; j++) {
            f[j] = ft[j];
            ft[j] = 0;
        }
    }

    for (j = 0; j < 10000; j++) sum += f[j];
    
    printf("Answer: %u\n", sum);
}
