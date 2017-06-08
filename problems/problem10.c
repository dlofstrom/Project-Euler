#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    unsigned long long sum = 0;

    //All primes below two million
    unsigned int pi, p;
    for (pi = 0; pi < 2000000; pi++) {
        p = get_prime(pi);
        if (p < 2000000) {
            sum += p;
        } else {
            break;
        }
    }
  
    printf("Answer: %llu\n", sum);
}
