#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

#define DIGIT_LENGTH 1500
#define DIGIT_TEST_LENGTH 1000

typedef struct {
    int digit;
    int length;
    int closed;
} digit_t;

int calculate_unit_fraction(int d, digit_t *dp) {
    int i = 0;
    int t = 10;
    while (t != 0) {
        dp[i].digit = t / d;
        dp[i].length = 1;
        dp[i].closed = 0;
        t = (t % d) * 10;
        i++;
        if (i >= DIGIT_LENGTH) break; //limit
    }
    return t;
}

int get_cycle_length(digit_t *dp) {
    int di, dl, dt, dc;
    //Test with different length until a cycle is found
    for (dl = 1; dl < DIGIT_LENGTH; dl++) {
        for (di = 0; di + dl < DIGIT_TEST_LENGTH; di++) {
            dc = 1; //Assume cycle
            for (dt = 1; dt + di < DIGIT_LENGTH; dt++) {
                if (dp[di+dt].digit != dp[di+(dt%dl)].digit) {
                    dc = 0;
                    break;
                }
            }
            //printf("dc = %d\n", dc);
            if (dc == 1) break;
        }
        if (dc == 1) break;
    }
    return dl;
}

void problem(char *info)
{
    int d, dl;
    digit_t digits[DIGIT_LENGTH];
    int longest = 0;
    int d_longest = 0;
    for (d = 1; d <= 1000; d++) {
        //If recurring decimal places
        if (calculate_unit_fraction(d, digits) != 0) {

            //Print
            //printf("d = %d - 0.", d);
            //for (di = 0; di < DIGIT_LENGTH; di++) {
            //   printf("%d", digits[di].digit);
            //}
            //printf("\n");

            dl = get_cycle_length(digits);
            
            if (dl > longest) {
                printf("d = %d dl = %d\n", d, dl);
                longest = dl;
                d_longest = d;
            }            
        }
    }
    
    printf("Answer: %u\n", d_longest);
}
