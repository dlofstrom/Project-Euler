#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

//Node in nxn grid, n ways to 0,0
typedef struct {
    int32_t x;
    int32_t y;
    uint64_t n;
} node_t;

uint64_t calculate_routes(int32_t x, int32_t y, node_t *a) {
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
    uint64_t n = calculate_routes(x-1,y,a) + calculate_routes(x,y-1,a);
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
    const uint32_t size = 20;
    node_t array[size*size+1] = {{0,0,0}}; //Initialized to 0

    //Calculate number of routes from a x,y position from 0,0
    uint64_t n = calculate_routes(size, size, array);
    printf("Answer: %llu\n", n);
}
