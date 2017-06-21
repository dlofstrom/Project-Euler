#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

//Sequence 1 is the sum of the top right to bottom left diagonal
//The start of the sequence is 1,3,7,13,21...
//It follows the pattern n(0) = 1, n(i) = n(i-1)+2*i where i = 0,1,2,...,m and m<s
int s1(int s) {
    int sum = 0;
    int i;
    //n(0)
    int n = 1;
    for (i = 1; i <= s; i++) {
        //printf("%d,", n);
        sum += n;
        //n(i)
        n = n + 2*i;
    }
    return sum;
}

//Sequence 2 is the sum of the top left to bottom right diagonal
//The start of the sequence is 1,5,9,17,26...
//It follows the pattern n(0) = 1, n(i) = n(i-1)+2*(i+x), where i = 0,1,2,...,m, x=(i is even)?0:1 and m<s
int s2(int s) {
    int sum = 0;
    int i,x;
    //n(0)
    int n = 1;
    for (i = 1; i <= s; i++) {
        //printf("%d,", n);
        sum += n;
        //n(i)
        x = (i % 2 == 0) ? 0 : 1;
        n = n + 2*(i+x);
    }
    return sum;
}

void problem(char *info)
{
    int sum = 0;
    int size = 1001;
    sum = s1(size) + s2(size) - 1;
    printf("Answer: %d\n", sum);
}
