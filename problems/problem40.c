#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

int digit(int i) {
    //printf("Digit %d\n", i);
    
    //Get i:th digit
    int p = 1;
    int t = i;
    while (t - p*(pow(10,p)-pow(10,p-1)) > 0) {
        t -= p*(pow(10,p)-pow(10,p-1));
        p++;
    }
    p--;
    //printf("t %d\n", t);
    //printf("Power %d\n", p);

    int o = (t-1)/(p+1);
    //printf("Offset %d\n", o);
    int b = p-(t-1)%(p+1);
    //printf("Base %d\n", b);

    int d = ((int)pow(10,p)+o)/(int)pow(10,b)%10;
    //printf("%d:th digit %d\n", i, d);
    return d;
}

void problem(char *info)
{
    int p = 1;
    int i;
    for (i = 0; i < 7; i++) {
        p *= digit((int)pow(10,i));
    }
    printf("Answer: %d\n", p);
}
