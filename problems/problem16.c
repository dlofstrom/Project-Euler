#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

//Divide binary number e.g "1010" / "10" = "101"
//returns the modulo/rest of the division
unsigned int divide(char *bo, char *bi, char *bd) {
    int b, t, c;
    int a = 0;
    int divide = 0;
    int l = strlen(bd) - 1;
    while (bi[a] != '1') a++; //Move start to first bit
    for (b = a; b < strlen(bi); b++) {
        if (b - a < l) divide = 0; //bi[a:b] needs to be at least as long as divisor
        else if (b - a > l) divide = 1; //If bi[a:b] is longer it is definitely larger
        else {
            //compare if bi[a:b] is larger than bd
            divide = 1;
            for (t=a; t <= b; t++) {
                if (bi[t] != bd[t-a]) {
                    if (bi[t] < bd[t-a]) divide = 0;
                    break;
                }
            }
        }
        //Divide
        c = 0;
        if (divide == 1) {
            bo[b] = '1';
            //Subtract
            for (t = 0; t <= b-a; t++) {
                if (t >= strlen(bd)) bi[b-t] = (c == 0) ? '1' : '0';
                else if (bd[l-t] != c + '0') {
                    c = (bi[b-t] == '0') ? 1 : 0;
                    bi[b-t] = (bi[b-t] == '0') ? '1' : '0';
                }
            }
        } else bo[b] = '0';
        //Move a to next msb=1
        while (bi[a] != '1' && a <= b) a++;
        divide = 0;
    }
    bo[b] = '\0';

    //Return remainder
    unsigned int s = 0;
    for (t = 0; t < strlen(bd); t++)
        if (bi[strlen(bi)-t-1] == '1') s += (1 << t);
    return s;
}
unsigned int is_empty(char *b) {
    while (*b != '\0') if(*(b++) == '1') return 0; 
    return 1;
}

void problem(char *info)
{
    const unsigned int number = 1000 + 2;
    char no[number], ni[number];
    ni[0] = '1';
    ni[number-1] = '\0';
    unsigned int i;
    for (i = 1; i < number-1; i++) ni[i] = '0';

    unsigned int sum = 0;
    unsigned int rest;
    do {
        rest = divide(no, ni, "1010");
        sum += rest;
        strncpy(ni, no, number);
    } while (is_empty(ni) != 1);
    printf("Answer: %u\n", sum);
}
