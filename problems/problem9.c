#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    unsigned int abc = 0;
    //Generate possible numbers
    unsigned int a,b,c;
    unsigned int a2,b2,c2;
    for (a = 1; a < 1000; a++) {
        a2 = pow(a, 2);
        //b can only be 1 <= b < 1000-a
        for (b = 1; b < 1000-a; b++) {
            b2 = pow(b, 2);

            //c can only be 1000-a-b
            c = 1000 - a - b;
            c2 = pow(c, 2);
            
            //Check if Pythagorean triplet
            if (a2 + b2 == c2) {
                abc = a*b*c;
            }
        }
    }
    
    printf("Answer: %u\n", abc);
}
