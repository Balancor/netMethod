#include <iostream>

using namespace std;
#include "url.h"
int main(int argc, char **argv){

    if(argc < 2){
        cout<<stderr<<"Usage: ./Browser http://www.baidu.com"<<endl;
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];
    Browser mBrowser = new Browser();
    mBrowser.openPage(url, false/*need to open a new page?*/);
}
