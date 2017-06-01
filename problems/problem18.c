#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

typedef struct {
    uint32_t row;
    uint32_t number;
    uint32_t max;
} t_t;

void problem(char *info)
{
    char row[1000];
    char *rp;
    char *start = info;
    uint32_t r = 0;
    uint32_t t;
    t_t triangle[121] = {{0,0,0}}; //Number of numbers in triangle
    t_t *tp;

    //Save all triangle numbers in an array
    while (get_row(&start, row) != 0) {
        //Find first item in triangle (example is overwritten)
        if (r == 0 && sscanf(row, "%u", &t) == 1) {
            r = 1;
            tp = triangle+1;
        }
        //Go as long as there is a number in the beginning
        if (r > 0 && sscanf(row, "%u ", &t) == 1) {
            rp = row;
            //Scan numbers in triangle
            do {
                sscanf(rp, "%u", &(tp->number));
                tp->row = r;
                tp++;
                rp += 3;
            } while (*(rp-1) != '\0');
            r++;
        } else {
            r = 0;
        }
    }
    //Now triangle array contains all numbers

    
    //Go from bottom and save maximum path sum in node
    //A node n has childs at positions (n.index+n.row) and (n.index+n.row+1)
    //e.g first node(index 0) is connected to (0+1) and (0+1+1)
    for (tp = &triangle[120]; tp->row != 0; tp--) {
        //Save own value as max
        tp->max = tp->number;
        if (tp->row < 15) {
            //Add maximum child
            tp->max += ((tp+tp->row)->max > (tp+tp->row+1)->max) ? (tp+tp->row)->max : (tp+tp->row+1)->max;
        }
    }

    printf("Answer: %u\n", triangle[1].max);
}
