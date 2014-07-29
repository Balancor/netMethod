#include <iostream>

using namespace std;
#include "Browser.h"
int main(int argc, char **argv){

    if(argc < 2){
        cout<<"Usage: ./Browser http://www.baidu.com"<<endl;
        return 1;
    }

    char *url = argv[1];
    Browser* mBrowser = new Browser();
    mBrowser->openPage(url, false/*need to open a new page?*/);
    mBrowser->initHostInfo();
    mBrowser->dumpPage();
}
