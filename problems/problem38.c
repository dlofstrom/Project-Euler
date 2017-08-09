#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    int l = 0;

    //Product of x and (1,2,..,i,..,n)
    int x, n, i, p;
    char s[30];
    char *sp;
    for (x = 1; x < 100000; x++) {
        for (n = 2; n < 100; n++) {
            sp = s;
            for (i = 1; i <= n; i++) {
                sp += sprintf(sp, "%d", x*i);
            }
            if (strlen(s) > 9) break;
            sscanf(s, "%d", &p);
            if (is_pandigital(p)) {
                //printf("Concatenated product of %d and (1,2,...,%d) = %d\n", x, n, p);
                if (p > l) l = p;
            }
        }
    }
    
    printf("Answer: %d\n", l);
}
