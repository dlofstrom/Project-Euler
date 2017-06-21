#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

#define SIZE 100

//Calculate all prime factors (e.g 54=2^1*3^3) as a string
char *calculate_prime_factors(int number, int multiplier) {
    int p = 0;
    int power = 0;
    int prime = get_prime(0);
    char *nas = malloc(20);
    char *nasp = nas;
    while (number != 1) {
        if (number % get_prime(p) == 0) {
            power += multiplier;
            number /= get_prime(p);
        }
        else {
            if (power != 0) {
                nasp += sprintf(nasp, "%d^%d*", prime, power);
                power = 0;
            }
            p++;
            prime = get_prime(p);
        }
    }
    nasp += sprintf(nasp, "%d^%d", prime, power);
    return nas;
}


void problem(char *info)
{
    int n = 0;
    char **array = malloc(0);
    
    int a, b, i, u;
    for (a = 2; a <= SIZE; a++) {
        for (b = 2; b <= SIZE; b++) {
            char *pf = calculate_prime_factors(a, b); 

            //Compare with all other in array
            u = 1;
            for (i = 0; i < n; i++) {
                if (strcmp(pf, array[i]) == 0) {
                    u = 0;
                    break;
                }
            }

            //If unique insert into array, else free memory
            if (u == 1) {
                array = realloc(array, (n+1)*sizeof(char*));
                array[n] = pf;
                n++;
            } else {
                free(pf);
            }
            
        }
    }

    //Free allocated
    for (i = 0; i < n; i++) free(array[i]);
    
    printf("Answer: %d\n", n);
}
