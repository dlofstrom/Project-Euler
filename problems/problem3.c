#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    unsigned long long number = 600851475143;
    
    unsigned long long pfactors[100];
    unsigned long long *pf = pfactors;
    unsigned long long pi = 0;
    unsigned long long p;
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
