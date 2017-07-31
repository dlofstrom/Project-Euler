#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

int is_pandigital(int a, int b, int p) {
    //Concatinate numbers
    char s[20];
    sprintf(s, "%d%d%d", a, b, p);

    //Count digits
    int digit_count[10] = {1,0,0,0,0,0,0,0,0,0}; //we dont want 0 in the number
    char *c = s;
    while (*c != '\0') digit_count[*(c++) - '0']++;

    //Check for "non 1" digit counts
    int i;
    for (i = 0; i < 10; i++) {
        if (digit_count[i] != 1) {
            //printf("%d x %d = %d is NOT pandigital\n", a, b, p);
            return 0;
        }
    }

    //Return if pandigital
    //printf("%d x %d = %d is pandigital\n", a, b, p);
    return 1;
}

void problem(char *info)
{
    unsigned int sum = 0;

    //Checking numbers
    int a, b, p;
    int pandigital[10] = {0};
    int i;
    for (a = 1; a < 9999; a++) {
        for (b = a; a*b < 9999; b++) {
            //Check a x b = a*b
            p = a*b;
            if (is_pandigital(a, b, p)) {
                //Check if product alreadiy exists
                i = 0;
                while (i < 10) {
                    //If product exists
                    if (pandigital[i] == p) {
                        break;
                    }
                    //If empty slot is found in array, product does not exist 
                    else if (pandigital[i] == 0) {
                        pandigital[i] = p;
                        sum += p;
                        break;
                    }
                    i++;
                }
            }
        }
    }

    printf("Answer: %u\n", sum);
}
