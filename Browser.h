#include <iostream>
#include "UrlParser.h"
using namespace std;

class Browser {
private:
//        Page *mPage;
       char* mURL;
        UrlParser *mParser;

public:
    Browser();
    void openPage(char* url, bool newPage = false);
    void initPage();
    void closePage();
};
