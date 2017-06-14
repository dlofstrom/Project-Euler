#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

int quadratic_expression(int a, int b, int n) {
    int q = n*n + a*n + b;
    if (q < 0) return -q;
    else return q;
}

void problem(char *info)
{
    //From the examples it looks like both a and b in n^2 + an + b are prime
    int a, ai, b, bi, il, n, c;
    int cl = 0;
    int abl = 0;

    //Get prime index limit
    il = 0;
    while (get_prime(il) < 1000) il++;
    il--;
    
    //Try -999 < a < 999 (primes)
    for (ai = -il; ai <= il; ai++) {
        if (ai < 0) a = -get_prime(-ai);
        else a = get_prime(ai);
        //Try -1000 < b < 1000 (primes)
        for (bi = -il; bi < il; bi++) {
            if (bi < 0) b = -get_prime(-bi);
            else b = get_prime(bi);
            //printf("a=%d b=%d\n",a,b);

            //Try n > 0
            n = 0;
            c = 0;
            while (is_prime(quadratic_expression(a,b,n++))) c++;
            //printf("a=%d b=%d - %d primes\n",a,b,c);

            //Save product of longest
            if (c > cl) {
                cl = c;
                abl = a*b;
            }
        }
    }
    
    printf("Answer %d\n", abl);
}
