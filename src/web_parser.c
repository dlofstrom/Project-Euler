#include "web_parser.h"

#include <string.h>
#include <curl/curl.h>
#include <tidy/tidy.h>
#include <tidy/buffio.h>

//Derived from curl getinmemory example
typedef struct {
    char *memory;
    size_t size;
} memory_s;

//Html compare object
typedef struct {
    ctmbstr tag;
    ctmbstr attr;
    ctmbstr val;
} compare_s;

//Derived from curl getinmemory example
static size_t
callback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    memory_s *mem = (memory_s *)userp;
    
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if(mem->memory == NULL) {
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }
    
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

//Get content from a webpage as a string
char *get_webpage(char *url)
{
    //Derived from curl getinmemory example 
    CURL *curl_handle;
    CURLcode res;
    memory_s chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    
    res = curl_easy_perform(curl_handle);
    
    //Check for errors 
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }
    
    //Any more that needs to be cleaned here? 
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    
    return chunk.memory;
}

//When content is found, write text to memory recursively
void dump_subtree(TidyDoc doc, TidyNode tnod, memory_s *mem)
{
    TidyNode child;
    for(child = tidyGetChild(tnod); child; child = tidyGetNext(child) ) {
        if(!tidyNodeGetName(child)) {
            //If not a tag it's text
            TidyBuffer buf;
            tidyBufInit(&buf);
            if (tidyNodeHasText(doc, child)) {
                if (tidyNodeGetText(doc, child, &buf)) {
                    if (buf.size != 0) {
                        //Copy buffer to memory (similar to curl callback above)
                        mem->memory = realloc(mem->memory, mem->size + buf.size + 1); //why + 1
                        if(mem->memory == NULL) {
                            printf("Not enouch memory (realloc returned NULL)\n");
                            return;
                        }
                        //Copy data ignore newline
                        if (buf.bp[buf.size-1] == '\n') buf.size -= 1;
                        memcpy(&(mem->memory[mem->size]), buf.bp, buf.size);
                        mem->size += buf.size;
                        mem->memory[mem->size] = 0;
                        //printf("%s\n\n", (char *)buf.bp);//buf.bp?(char *)buf.bp:"");
                    }
                }
            }
            tidyBufFree(&buf);
        } else {
            //Look for tags indicating a newline
            ctmbstr tag = tidyNodeGetName(child);
            int newline = 0;
            if (strcmp(tag, "p") == 0) newline = 1;
            else if (strcmp(tag, "div") == 0) newline = 1;
            else if (strcmp(tag, "br") == 0) newline = 1;
            else if (strcmp(tag, "h1") == 0) newline = 1;
            else if (strcmp(tag, "h2") == 0) newline = 1;
            else if (strcmp(tag, "h3") == 0) newline = 1;

            if (newline) {
                 mem->memory = realloc(mem->memory, mem->size + 1);
                 if(mem->memory == NULL) {
                     printf("Not enouch memory (realloc returned NULL)\n");
                     return;
                 }
                 mem->memory[mem->size] = '\n';
                 mem->size += 1;
                 mem->memory[mem->size] = 0;
            }
        }
        //Recursive
        dump_subtree(doc, child, mem); 
    }    
}


//Search the document tree recursively 
int search_tree(TidyDoc doc, TidyNode tnod, memory_s *mem, compare_s *cmp)
{
    TidyNode child;
    for(child = tidyGetChild(tnod); child; child = tidyGetNext(child) ) {
        ctmbstr tag = tidyNodeGetName(child);
        //Searching for tag       
        if(tag) {
            //Check tag match
            //printf("Checking %s\n", tag);
            if(strcmp(tag, cmp->tag) == 0) {
                //If only looking for tag
                //printf("Matched %s\n", tag);
                if(cmp->attr == NULL && cmp->val == NULL) {
                    //printf("attr and val empty\n");
                    dump_subtree(doc, child, mem);
                    return 1;
                }
                //Check attributes and values
                TidyAttr attr;
                //printf("%s", name);
                for(attr=tidyAttrFirst(child); attr; attr=tidyAttrNext(attr) ) {
                    //printf("Checking %s %s %s\n", tag, tidyAttrName(attr), tidyAttrValue(attr));
                    if (strcmp(tidyAttrName(attr), cmp->attr) == 0 && strcmp(tidyAttrValue(attr), cmp->val) == 0) {
                        //printf("MATCH\n");
                        dump_subtree(doc, child, mem);
                        //printf("-----");
                        return 1;
                    }
                    //printf(" %s", tidAttrName(attr));
                    //tidyAttrValue(attr)?printf("=\"%s\" ", tidyAttrValue(attr)):printf("");
                }
                //printf("\n");
            }
        }
        //Recursive
        if (search_tree(doc, child, mem, cmp)) return 1;
    }
    return 0;
}

char *filter_webpage(char *content, char *tag, char *attr, char *val)
{
    //Derived from htmltidy example
    TidyDoc tdoc;
    TidyBuffer docbuf = {0};
    TidyBuffer tidy_errbuf = {0};
    int err;
    
    tdoc = tidyCreate();
    tidyOptSetBool(tdoc, TidyForceOutput, yes); /* try harder */ 
    tidyOptSetInt(tdoc, TidyWrapLen, 4096);
    tidySetErrorBuffer(tdoc, &tidy_errbuf);
    tidyBufInit(&docbuf);

    //Fill TidyBuffer
    tidyBufAppend(&docbuf, content, strlen(content));

    memory_s chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;
    
    compare_s cmp = {tag, attr, val};
    
    err = tidyParseBuffer(tdoc, &docbuf); //parse the input 
    if(err >= 0) {
        err = tidyCleanAndRepair(tdoc); //fix any problems 
        if(err >= 0) {
            err = tidyRunDiagnostics(tdoc); //load tidy error buffer 
            if(err >= 0) {
                search_tree(tdoc, tidyGetRoot(tdoc), &chunk, &cmp); //walk the tree 
                //if (tidy_errbuf.size != 0) fprintf(stderr, "%s\n", tidy_errbuf.bp); //show errors 
            }
        }
    }
    
    tidyBufFree(&docbuf);
    tidyBufFree(&tidy_errbuf);
    tidyRelease(tdoc);

    //Return filtered content
    if (chunk.size != 0) return chunk.memory;
    else return NULL;
}
















