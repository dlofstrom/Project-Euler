#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

unsigned int ones[20] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8}; //0-19
unsigned int tens[10] = {0,0,6,6,5,5,5,7,6,6}; //00-90

void problem(char *info)
{
    unsigned int sum = 0;

    unsigned int i, n, l, t;
    for (i = 1; i <= 1000; i++) {
        n = i;
        l = 0;
        while (n) {
            if (n >= 1000) {
                t = n / 1000;
                l += ones[t] + 8; //digit + thousand
                n -= 1000*t;
            } else if (n >= 100) {
                t = n / 100;
                l += ones[t] + 7; //digit + hundred
                n -= 100*t;
                if (n != 0) {
                    l += 3; //and
                }
            } else if (n >= 20) {
                t = n / 10;
                l += tens[t]; //digit
                n -= 10*t;
            } else {
                t = n;
                l += ones[t]; //digit (0-19)
                n -= t;
            }
        }
        sum += l;
    }
    
    printf("Answer: %u\n", sum);
}
