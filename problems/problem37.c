#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    int sum = 0;

    //Find 11 primes
    int n = 0;
    int i = 4; //ignore < 10
    int p, pt, l;
    char s[11], *sp;
    while (n < 11) {
        p = get_prime(i++);
        //printf("Testing prime %d\n", p);

        sprintf(s, "%d", p);
        l = strlen(s)-1;
        sp = s+1;
        //Left to right
        while (*sp != '\0') {
            sscanf(sp, "%d", &pt);
            //printf("%d\n", pt);
            //Abort if not prime
            if (!is_prime(pt)) break;
            sp++;
        }
        //If all "Left to right" passed then *sp = '\0'
        if (*sp == '\0') {
            //Right to left
            while (l > 0) {
                s[l] = '\0';
                sscanf(s, "%d", &pt);
                //printf("%d\n", pt);
                if (!is_prime(pt)) break;
                l--;
            }
        }
        //If all "Right to left passer then l = 0
        if (l == 0) {
            //printf("%d passed all tests\n", p);
            sum += p;
            n++;
        }
    }
    
    printf("Answer: %d\n", sum);
}
