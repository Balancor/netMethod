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
    Browser mBrowser = new Browser();
    mBrowser.openPage(url, false/*need to open a new page?*/);
}
