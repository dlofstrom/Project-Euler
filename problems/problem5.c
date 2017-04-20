#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    uint32_t multiple = 1;
    uint8_t powers[8] = {0}; //8 primes <= 20

    //Calculate prime divisors for numbers 2-20 (e.g 20 = 2*2*5 = 2^2*5)
    uint8_t n,i,power,prime, rest;
    for (n = 2; n <= 20; n++) {
        i = 0;
        power = 0;
        rest = n;
        while (rest != 1) {
            prime = get_prime(i);
            if (rest % prime == 0) {
                //If divisible, increment power and continue with rest/prime
                rest /= prime;
                power++;
            } else {
                //Else save power if it is the largest yet
                if (power > powers[i]) powers[i] = power;
                power = 0;
                i++;
            }
        }
        //Save last power if it is the largest yet
        if (power > powers[i]) powers[i] = power;
    }

    //Multiply number together
    for (i = 0; i < 8; i++) {
        multiple *= pow(get_prime(i),powers[i]);
    }
    
    printf("Answer: %u\n", multiple);
}
