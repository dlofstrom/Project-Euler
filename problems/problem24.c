#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"


#define LEVELS 10

void problem(char *info)
{
    //The lexiographic order is basically a tree
    //For 0,1,2 it is the size (number of leaves at the end) of 3!
    //        start       level n = 0
    //     /    |    \
    //    0     1     2   level 1
    //   / \   / \   / \
    //  1   2 0   2 0   1 level 2
    //  |   | |   | |   |
    //  2   1 2   0 1   0 level 3
    //Every level contains subnets of size (3 - n)!
    //To find m:th path just go into the right subtree
    //e.g to find 3rd (index from 0) leaf, 3 - 1*(3-1)! - 1*(3-2)! - 0*(3-3)!
    //gives us path 110 -> 1 2 0

    int n = 1000000-1; //index from 0
    //Go through levels and find path
    int l, c;
    int p[LEVELS];
    for (l = 0; l < LEVELS; l++) {
        c = 0;
        //Find next subtree
        while ((c+1)*factorial(LEVELS-l-1) <= n) c++;
        //Adjust n = n - c*(10-level)!
        n -= c*factorial(LEVELS-l-1);
        //Save path
        p[l] = c;
        
    }

    //Lookup path
    char numbers[LEVELS+1] = "0123456789";
    char number[LEVELS+1] = "----------";
    for (l = 0; l < LEVELS; l++) {
        //Lookup number
        number[l] = numbers[p[l]];
        //Pop number from possible
        c = p[l];
        while (numbers[c] != '\0') {
            numbers[c] = numbers[c+1];
            c++;
        }
    }
    
    printf("Answer: %s\n", number);
}
