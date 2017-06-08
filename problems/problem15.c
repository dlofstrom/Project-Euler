#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

#define SIZE 20

//Node in nxn grid, n ways to 0,0
typedef struct {
    int x;
    int y;
    unsigned long long n;
} node_t;

unsigned long long calculate_routes(int x, int y, node_t *a) {
    //Check if non valid coordinate
    if (x < 0 || y < 0) return 0;
    //Check if at origo
    if (x == 0 && y == 0) return 1;
    
    //Search if node x,y already is known
    node_t *as = a;
    while (as->n != 0) {
        if (as->x == x && as->y == y) return as->n;
        else if(as->x == y && as->y == x) return as->n; //Symmetry in nxn grid
        as++;
    }

    //Else calculate how many ways there are to 0,0 from current x,y
    unsigned long long n = calculate_routes(x-1,y,a) + calculate_routes(x,y-1,a);
    //Store in lookup memory
    as = a;
    while (as->n != 0) as++;
    as->x = x;
    as->y = y;
    as->n = n;
    return n;
}

void problem(char *info)
{
    node_t array[SIZE*SIZE+1] = {{0,0,0}}; //Initialized to 0

    //Calculate number of routes from a x,y position from 0,0
    unsigned long long n = calculate_routes(SIZE, SIZE, array);
    printf("Answer: %llu\n", n);
}
