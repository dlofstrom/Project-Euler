#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    uint64_t number = 600851475143;
    
    uint64_t pfactors[100];
    uint64_t *pf = pfactors;
    uint64_t pi = 0;
    uint64_t p;
    while (number != 1) {
        p = get_prime(pi);
        //printf("Testing %llu / %llu: ", number, p);
        //If prime factor
        if (number % p == 0) {
            number /= p;
            *pf = p;
            pf++;
            //printf("%llu is a prime factor\n", p);
        } else {
            pi++;
            //printf("\n");
        }
    }
        
    printf("Answer: %llu\n", *(pf-1)); 
}
