#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    int n = 0;
    
    int i, ip, j, l, ir, ic;
    char s[20], *sp;
    for (i = 0; i < 1000000; i++) {
        ip = get_prime(i);
        if (ip >= 1000000) break;
        
        sprintf(s, "%d", ip);
        sp = s;
        l = strlen(s);
        //printf("Testing %d\n", ip);
        ic = 1;
        for (j = 0; j < l; j++) {
            //printf("%s\n", sp);
            sp[l] = *sp;
            sp++;
            sp[l] = '\0';
            sscanf(sp, "%d", &ir);
            if (is_prime(ir) == 0) ic = 0;
        }

        if (ic) {
            //printf("%d is a circular prime\n", ip);
            n++;
        }
    }

    printf("Answer: %d\n", n);
}
