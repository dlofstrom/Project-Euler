#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

#define SIZE 1000

void add(int *i1, int *i2, int *o) {
    int c = 0;
    int i, s;
    for (i = 0; i < SIZE; i++) {
        s = i1[i] + i2[i] + c;
        o[i] = s % 10;
        c = s / 10;
    }
}

void problem(char *info)
{
    //Three numbers containing 1000 digits
    int fa[SIZE] = {1};
    int fb[SIZE] = {0};
    int fc[SIZE] = {0};

    //Pointers to numbers
    int *f1 = fa;
    int *f2 = fb;
    int *s = fc;
    int *t;
    
    int n = 1;
    //While 1000th digit is still 0
    while (f1[SIZE-1] == 0) {
        //Add last two fibonacci numbers
        add(f1, f2, s);
        //Move pointers
        t = s;
        s = f2;
        f2 = f1;
        f1 = t;
        n++;
    }
    
    printf("Answer: %d\n", n);
}
