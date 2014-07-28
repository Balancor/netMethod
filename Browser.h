#include <iostream>

using namespace std;

class Browser {
private:
        Page *mPage;
        URL* mURL;
        URLParser *mParser;

public:
    Browser(const char* url);
    void openPage();
    void initPage();
    void closePage();
    
}

