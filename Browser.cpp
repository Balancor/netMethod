#include "Browser.h"

using namespace std;

Browser::Browser(const char* url){
    mURL = url;
    mParser = new Pareser(mURL);
    mPareser.parse();
    mParser.dumpUrlParser();
}
