#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "url.h"
int main(int argc, char **argv){

    if(argc < 2){
        fprintf(stderr, "Usage: ./Browser http://www.baidu.com");
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];
    UrlParser* mUrlParser = new Parser(url);
    mUrlParser.getPage(); 
}
