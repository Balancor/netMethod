#ifndef __BROWSER_H__
#include <iostream>
#include <list>

#include "UrlParser.h"
#include "HostInfo.h"
#define __BROWSER_H__
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
#endif
