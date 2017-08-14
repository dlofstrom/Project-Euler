#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

//i:th permutation of n characters using Heap's (I think)
void permutation(int i, char *si, int n, char *so) {
    //Block size
    int bs = factorial(n) / n;
    //printf("Block size: %d\n", bs);

    if (n == 1) {
        so[0] = si[0];
        so[1] = '\0';
    } else {
        //Character index
        int ci = i / bs;
        //printf("Character index: %d\n", ci);
        so[0] = si[ci];
        so[1] = '\0';
        //printf("Character: %c\n", so[0]);
        
        char s[10];
        char *sp = s;
        int j;
        for (j = 0; j < n; j++) if (j != ci) *(sp++) = si[j];
        *sp = '\0';
        //Recursive
        permutation(i%bs, s, n-1, so+1);
    }
}

void problem(char *info)
{
    //unsigned int p = 0;
    char p[10];
    int pi, pd;
    char s[10] = "123456789";
    int n;
    int i;

    //n:th pandigital
    for (n = 9; n > 0; n--) {
        //From the top
        for (i = factorial(n)-1; i >= 0; i--) {
            //Get i:th permutation of s
            permutation(i, s, n, p);
            
            //Convert to integer
            sscanf(p, "%d", &pi);
            
            //Check if prime
            for (pd = 2; pd < pi; pd++) {
                if (pi % pd == 0) {
                    //printf("%d divides %d\n", pd, pi);
                    break;
                }
            }
            //If for loop did not break
            if (pd == pi) {
                printf("%d:th = %d Is prime\n", i, pi);
                break;
            }
        }
        if (pd == pi) break;
    }

    printf("Answer: %u\n", pi);
}
