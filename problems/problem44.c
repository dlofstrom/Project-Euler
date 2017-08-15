#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

#define P_SIZE 5000

void problem(char *info)
{
    int Dmin = 0;

    int P[P_SIZE] = {0};
    
    int k, j, S, Sp, D, Dp, i;
    for (i = 0; i < P_SIZE; i++) P[i] = i * (3*i - 1) / 2;

    for (k = 0; k < 2500; k++) {
        //printf("%d\n", k);
        for (j = 1; j < k; j++) {
            //Check if sum and difference is pentagonal
            S = P[k] + P[j];
            Sp = 0;
            D = P[k] - P[j];
            Dp = 0;
            for (i = 1; i < S; i++) {
                if (P[i] == D) Dp = 1;
                if (P[i] == S) Sp = 1;
                else if (P[i] > S) break;
            }

            //If both is pentagonal
            if (Dp == 1 && Sp == 1) {
                printf("P%d + P%d = %d is pentagonal\n", k, j, S);
                printf("P%d - P%d = %d is pentagonal\n", k, j, D);
                if (Dmin == 0) Dmin = D;
                else if (Dp < Dmin) Dmin = D;
            }
        }
    }
    
    printf("Answer: %d\n", Dmin);
}
