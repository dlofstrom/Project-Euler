#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    long long int sum = 0;
    char p[11];
    char s[11] = "0123456789";
    
    int i, o;
    long long int d;
    for (i = 0; i < factorial(10); i++) {
        //Get all 0-9 pandigital numbers
        permutation(i, s, 10, p);
        
        //printf("Number: %s\n", p);
        //Go from d8-d10 to d2-d4
        for (o = 7; o > 0; o--) {
            sscanf(p+o, "%lld", &d);
            //printf("d%d-d%d = %d\n", o+1, o+3, d);
            p[o+2] = '\0';
            
            if (d % get_prime(o-1) != 0) break;
            //else printf("%d is divisible by %d\n", d, get_prime(o-1));
        }
        
        if (o == 0) {
            permutation(i, s, 10, p);
            sscanf(p, "%lld", &d);
            //printf("Found %lld\n", d);
            sum += d;
        }
    }
    
    printf("Answer: %lld\n", sum);
}
