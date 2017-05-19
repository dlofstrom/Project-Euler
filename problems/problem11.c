#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    //The grid contains 20x20 numbers
    uint32_t data[400];
    uint32_t *data_ptr = data;
    
    //Go throug every row in info and fill data array with numbers
    char *start = info;
    while (*start != '\0') {
        //Ugly but effective
        if (sscanf(start,
                   "%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u\n",
                   data_ptr,data_ptr+1,data_ptr+2,data_ptr+3,data_ptr+4,
                   data_ptr+5,data_ptr+6,data_ptr+7,data_ptr+8,data_ptr+9,
                   data_ptr+10,data_ptr+11,data_ptr+12,data_ptr+13,data_ptr+14,
                   data_ptr+15,data_ptr+16,data_ptr+17,data_ptr+18,data_ptr+19) == 20) {
            data_ptr += 20;
        }
            
        if (data_ptr - data == 400) {
            //Done
            break;
        }
        
        //Move to next row
        while (*start != '\0' && *start != '\n') start++;
        start++;
    }

    //To navigate the array up, down, left, right and diagonally
    //we only need down, right and diagonally (left and right down)
    //  For every element in array:
    //  - down: i, i+20, i+40, i+60 if i+60 < 400
    //  - right: i, i+1, i+2, i+3 if i+3 < 400 and i+3 % 20 > i % 20
    //  - diagonal dr: i, i+21, i+42, i+63 if i+63 < 400 and i+3 % 20 > i % 20
    //  - diagonal dl: i, i+19, i+38, i+57 if i+57 < 400 and i-3 % 20 < i % 20
    uint32_t i;
    uint32_t product = 0;
    uint32_t p;
    for (i = 0; i < 400; i++) {
        //down
        if (i+60 < 400) {
            p = data[i]*data[i+20]*data[i+40]*data[i+60];
            if (p > product) product = p;
        }
        //right
        if ((i+3 < 400) && ((i+3) % 20 > i % 20)) {
            p = data[i]*data[i+1]*data[i+2]*data[i+3];
            if (p > product) product = p;
        }
        //diagonal dr
        if ((i+63 < 400) && ((i+3) % 20 > i % 20)) {
            p = data[i]*data[i+21]*data[i+42]*data[i+63];
            if (p > product) product = p;
        }
        //diagonal dl
        if ((i+57 < 400) && ((i-3) % 20 < i % 20)) {
            p = data[i]*data[i+19]*data[i+38]*data[i+57];
            if (p > product) product = p;
        }
    }
    printf("Answer: %u\n", product);
}
