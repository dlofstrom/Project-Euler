#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    int pmax = 0;
    int nmax = 0;
    int p, a, b, n;
    float c;
    for (p = 3; p < 1000; p++) {
        n = 0;
        for (a = 1; a < p; a++) {
            for (b = 1; b <= a; b++) {
                c = sqrt(pow(a,2) + pow(b,2));
                if (a + b + c == p) {
                    //printf("{%d,%d,%d} = %d\n",a, b, (int)c, p);
                    n++;
                }
                else  if (a + b + c > p) break;
            }
        }
        if (n > nmax) {
            nmax = n;
            pmax = p;
        }
    }
    
    printf("Answer: %d\n", pmax);
}
