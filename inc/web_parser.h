//------------------
//
// Web parser
//
//------------------


#ifndef WEB_PARSER_H
#define WEB_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Get content from a url
// Returns a char * to the content
// The memory is dynamically allocated and needs to be freed
char *get_webpage(char *url);

// Filter the content
// Returns a char * to the first occurrence of a html tag,attribute,value
// The returned value is a copy of the original content without any tags
// For example: <div class="test"><h2>Heading</h2><p>Text</p></div> => "Heading\nText"
// Content is dynamically allocated and needs to be freed
char *filter_webpage(char *content, char *tag, char *attr, char *val);

#endif
