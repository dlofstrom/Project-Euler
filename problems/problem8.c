#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    //Buffer containing 1000 digit number
    char temp[100];
    char number[1000];
    char *np = number;
    
    //Scan line in problem info
    char line[1000];
    size_t len = 0;
    char *start = info;
    char *search = info;
    //While not end of info
    while (*start != '\0') {
        //move search pointer to end of line
        search = start;
        while (*search != '\0' && *search != '\n') search++;
        len = search - start;
        //printf("%d\n", len);
        //copy line to buffer
        strncpy(line, start, len);
        line[len] = '\0';
        //printf("%s\n", line);
        //Move start to start of next line
        start += len + 1;

        //Look numbers ending with newline
        if (sscanf(line, "%[0-9]\n", temp) == 1) {
            //printf("%s\n", temp);
            strncpy(np, temp, strlen(temp));
            np += strlen(temp);
            *np = '\0';
        }
    }

    //Now number contains the 1000 digit number
    //Go through every thirteen adjacent and calculate product
    unsigned long long product = 0;
    unsigned long long p;
    np = number;
    int i;
    while (*(np + 12) != '\0') {
        p = 1;
        for (i = 0; i < 13; i++) p *= *(np+i) - '0';
        if (p > product) product = p;
        np++;
    }
    
    printf("Answer: %llu\n", product);
}
