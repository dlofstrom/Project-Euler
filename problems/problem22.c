#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"
#include "web_parser.h"

//Node for linked list
typedef struct nn {
    char name[20];
    uint32_t value;
    struct nn *next;
} name_node_t;

void problem(char *info)
{
    uint64_t total = 0;
    
    //Get names from link
    char *names = get_webpage("https://projecteuler.net/project/resources/p022_names.txt");

    //Load names into list
    name_node_t *list = (name_node_t*)malloc(sizeof(name_node_t));
    list->value = 0; //Last node is "empty"
    name_node_t *last = list;
    char *start = names;
    char *stop;
    uint32_t v;
    while (*start != '\0') {
        //Move start to first letter in name
        while (*start == '\"' || *start == ',') start++;
        stop = start;
        v = 0;
        //Move stop to end of name and calculate value
        while (*stop != '\"') {
            v += *stop - 'A' + 1;
            stop++;
        }

        //Create list node
        name_node_t *node = (name_node_t*)malloc(sizeof(name_node_t));
        strncpy(node->name, start, stop-start);
        node->name[stop-start] = '\0';
        node->value = v;
        node->next = list;
        list = node;

        //Move start
        start = stop + 1;
    }
    free(names);

    //Sort names (Bubble sort)
    name_node_t *np, *prev;
    v = 1;
    while (list->value != 0) {
        np = list;
        prev = last;
        //printf("%u", v);
        while (np->next->value != 0) {
            //Compare names
            if (strcmp(np->name, np->next->name) < 0) {
                //printf("Switch %s with %s\n", npt->name, npt->next->name);
                //Switch so that "smallest" string is at the bottom
                name_node_t *t = np->next;
                np->next = t->next;
                if (prev->value != 0) prev->next = t;
                t->next = np;
                if (np == list) list = t;
                prev = t;
            } else {
                prev = np;
                np = np->next;

            }
        }
        //Print add and remove last (alphabetically first) node
        total += v * (np->value);
        if (np == list) list = np->next;
        prev->next = np->next;
        free(np);
        v++;
    }
    printf("Answer: %llu\n", total);
}
