#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "web_parser.h"
#include "problem.h"
#include "common.h"


int main(int argc, char **argv)
{
    printf("\n\n-----------------------------------------------\n\n");
    //Assemble url string
    //argv[0] = "bin/problemX", find last '/' and increment pointer to X
    char url[50];
    sprintf(url, "https://projecteuler.net/problem=%s", strrchr(argv[0],'/')+8);
    printf("%s",url);
    
    //Read content from a webpage into page_content and filter problem text
    char *page_content = get_webpage(url);
    char *problem_content = filter_webpage(page_content,"div","id","content");

    //Print problem text
    printf("%s\n", problem_content);

    //Run Problem
    problem(problem_content);

    //Clean-up
    free(page_content);
    free(problem_content);
    return 0;
}
