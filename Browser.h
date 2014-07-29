#include <iostream>
#include <list>

#ifndef __BROWSER_HEAD__
#include "UrlParser.h"
#include "HostInfo.h"
#else
#define __BROWSER_HEAD__ 1
#endif
using namespace std;

class Browser {
private:
//        Page *mPage;
       char* mURL;
        UrlParser *mParser;
        list<HostInfo*> mHostInfoList;
        HostInfo* mCurrentHost;
        int mSocket;

public:
    Browser();
    ~Browser();
    void openPage(char* url, bool newPage = false);
    void initHostInfo();
    void connectToHost();
    void dumpPage();
    void closePage();
};
