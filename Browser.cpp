#include "Browser.h"

using namespace std;

Browser::Browser(){
}
void Browser::openPage(char* url, bool newPage){
    mURL = url;
    mParser = new UrlParser(mURL);
    mParser->parse();
    mParser->dumpUrlParser();
}
