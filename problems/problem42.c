#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"
#include "web_parser.h"

unsigned int word_value(char *word) {
    unsigned int v = 0;
    while (*word != '\0') v += *(word++) - 'A' + 1;
    return v;
}

void problem(char *info)
{
    int sum = 0;
    
    //Get names from link
    char *words = get_webpage("https://projecteuler.net/project/resources/p042_words.txt");

    //Load names into list
    char *start = words;
    char *stop;
    while (*start != '\0') {
        //Move start to first letter in word
        while (*start == '\"' || *start == ',') start++;
        stop = start;
        //Move stop to end of word
        while (*stop != '\"') stop++;

        //Create word string
        char w[20];
        strncpy(w, start, stop-start);
        w[stop-start] = '\0';

        //Check if word value is a triangle number
        //printf("%s has value %u\n", w, word_value(w));
        int wv = word_value(w);
        int i = 1;
        int tn = 0;
        while(tn <= wv) {
            tn = i*(i+1)/2;
            if (tn == wv) sum++;
            i++;
        }
        
        //Move start
        start = stop + 1;
    }
    free(words);

    printf("Answer: %d\n", sum);
}
