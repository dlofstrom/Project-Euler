#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

#define LENGTH 1500

void problem(char *info)
{
    int d, r, dl, ri, i, l;
    int longest = 0;
    int rests[LENGTH];
    for (d = 1; d <= 1000; d++) {
        //Calculate rest of digits every loop
        r = 10;
        ri = 0;
        l = 0;
        //While rest != 0
        while (r != 0) {
            //Next rest
            r = (r % d) * 10;
            rests[ri] = r;
            //Compare with earlier rests
            for (i = 0; i < ri; i++) {
                if (rests[ri] == rests[i]) {
                    //Cycle found
                    l = ri - i;
                    //printf("Cycle found at d = %d - l = %d\n", d, l);
                    //Force break
                    r = 0;
                }
            }
            ri++;
        }
        if (l > longest) {
            longest = l;
            dl = d;
        }
    }
    printf("Answer: %u\n", dl);
}
