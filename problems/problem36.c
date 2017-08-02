#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "problem.h"
#include "common.h"

//Converts a decimal number to decimal and binary string
void num_to_base_string(int dec, char *decs, char *bins) {
    //Decimal to string
    sprintf(decs, "%d", dec);
    //Binary to string
    int p = 0;
    while (pow(2, p+1) <= dec) p++;
    while (p >= 0) {
        if (dec >= pow(2, p)) {
            *(bins++) = '1';
            dec -= pow(2, p);
        } else {
            *(bins++) = '0';
        }
        p--;
    }
    *bins = '\0';
}

//Is palindrome
int is_palindrome(char *s) {
    int l = strlen(s);
    int i;
    for (i = 0; i < l; i++) {
        if (s[i] != s[l-i-1]) return 0;
    }
    return 1;
}

void problem(char *info)
{
    int sum = 0;
    char binary[32];
    char decimal[10];
    int i;

    for (i = 1; i < 1000000; i++) {
        num_to_base_string(i, decimal, binary);
        if (is_palindrome(decimal) && is_palindrome(binary)) {
            //printf("%s (%s) is palindrome\n", decimal, binary);
            sum += i;
        }
    }

    printf("Answer: %d\n", sum);
}
