#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    unsigned int fib[2] = {1,2};
    printf("Fibonacci numbers:\n%u, %u", fib[0], fib[1]);
    unsigned int sum = 2; //Starting with 1,2

    //Loop until next fibonacci number is > 4000000
    while (fib[0] + fib[1] < 4000000) {
        //Generate new fibonacci number
        fib[1] += fib[0];
        fib[0] = fib[1] - fib[0];
        
        //Add to sum if even
        if (fib[1] % 2 == 0) sum += fib[1];
        printf(", %u", fib[1]);
    }
    
    printf("\n\nAnswer: %u\n", sum);
}
