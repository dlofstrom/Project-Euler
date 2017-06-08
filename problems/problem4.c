#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

bool is_palindrome(unsigned int n)
{
    //convert to string
    char ns[10];
    sprintf(ns, "%u", n);

    //Compare digits
    char *head = ns;
    char *tail = ns+strlen(ns)-1;
    while (head < tail) {
        if (*(head++) != *(tail--)) return 0;
    }
    return 1;
}

void problem(char *info)
{   
    unsigned int n,x,y;
    unsigned int largest = 0;
    for (x = 999; x > 99; x--) {
        for (y = 999; y > 99; y--) {
            n = x*y;
            if (is_palindrome(n) && n > largest) largest = n;
        }
    }
    printf("Answer: %u\n", largest);
}
