#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

#define LIMIT 28123

void problem(char *info)
{
    unsigned int sum = 0;
    int *a = malloc(0);
    size_t a_size = 0;
    int i;

    //Generate all abundant numbers under 28123
    for (i = 1; i < LIMIT; i++) {
        //Check if number is abundant
        if (i < sum_of_divisors(i)) {
            a = realloc(a, sizeof(int)*(a_size + 1));
            a[a_size++] = i;
        }
    }

    int j;
    int numbers[LIMIT] = {0};
    //Mark all numbers which can be represented by two abundant numbers
    for (i = 0; i < a_size; i++) {
        for (j = i; j < a_size; j++) {
            if (a[i] + a[j] < LIMIT) numbers[a[i] + a[j]] = 1;
        }
    }
    free(a);

    for (i = 0; i < LIMIT; i++) {
        if (numbers[i] == 0) sum += i;
    }
    
    printf("Answer %u\n", sum);
}
