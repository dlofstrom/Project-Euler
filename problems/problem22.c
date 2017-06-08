#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"
#include "web_parser.h"

//Node for linked list
typedef struct nn {
    char name[20];
    struct nn *next;
} name_node_t;

uint32_t name_value(char *name) {
    uint32_t v = 0;
    while (*name != '\0') v += *(name++) - 'A' + 1;
    return v;
}

void problem(char *info)
{
    uint64_t total = 0;
    
    //Get names from link
    char *names = get_webpage("https://projecteuler.net/project/resources/p022_names.txt");

    //Load names into list
    name_node_t *list = NULL;
    name_node_t *np;
    char *start = names;
    char *stop;
    while (*start != '\0') {
        //Move start to first letter in name
        while (*start == '\"' || *start == ',') start++;
        stop = start;
        //Move stop to end of name
        while (*stop != '\"') stop++;

        //Create list node
        name_node_t *node = (name_node_t*)malloc(sizeof(name_node_t));
        strncpy(node->name, start, stop-start);
        node->name[stop-start] = '\0';
        
        //Insertion sort directly in list
        np = list;
        if (list == NULL || strcmp(node->name, list->name) < 0) {
            node->next = list;
            list = node;
        } else {
            while (np->next != NULL) {
                if (strcmp(node->name, np->next->name) < 0) {
                    node->next = np->next;
                    np->next = node;
                    break;
                }
                np = np->next;
            }
            if (np->next == NULL) {
                node->next = np->next;
                np->next = node;
            }
        }
        //Move start
        start = stop + 1;
    }
    free(names);

    //Calculate total
    np = list;
    uint32_t v = 1;
    while (np != NULL) {
        total += v * name_value(np->name);
        np = np->next;
        v++;
    }
    
    printf("Answer: %llu\n", total);
}
