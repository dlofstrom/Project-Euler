#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    //Comparing if ax/bx = a/b or ax/xb = a/b
    int a, b, x;
    float ab, axbx, axxb;
    int nominator = 1, denominator = 1;
    for (a = 1; a < 10; a++) {
        for (b = 1; b < 10; b++) {
            for (x = 1; x < 10; x++) {
                //Comparison
                ab = ((float)a)/b;
                //ax/bx
                axbx = ((float)(10*a+x))/(10*b+x);
                if (axbx < 1.0 && axbx == ab) {
                    //printf("%d/%d = %d/%d\n", 10*a+x, 10*b+x, a, b);
                    nominator *= a;
                    denominator *= b;
                }
                
                //ax/xb
                axxb = ((float)(10*a+x))/(10*x+b);
                if (axxb < 1.0 && axxb == ab) {
                    //printf("%d/%d = %d/%d\n", 10*a+x, 10*x+b, a, b);
                    nominator *= a;
                    denominator *= b;
                }
            }
        }
    }

    //Lowest common term
    a = 2;
    while (a <= nominator) {
        if (nominator % a == 0 && denominator % a == 0) {
            nominator /= a;
            denominator /= a;
        } else {
            a++;
        }
    }
    
    //Product
    //printf("Product = %d/%d\n", nominator, denominator);
    printf("Answer: %d\n", denominator);
}
