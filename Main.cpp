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
    cout<<"mBrowser->openPage()"<<endl;
    mBrowser->openPage(url, false/*need to open a new page?*/);
    cout<<"mBrowser->initHostInfo()"<<endl;
    mBrowser->initHostInfo();
    cout<<"mBrowser->dumpPage()"<<endl;
    mBrowser->dumpPage();
}
