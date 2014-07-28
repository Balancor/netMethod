#include <iostream>
#include <string>
using namespace std;

class UrlParser {

private:

    enum {
        HTTP   ,
        HTTPS  ,
        FTP    ,
        SMTP   ,
        DNS    ,
        TELNET ,
        IM     ,
        RIP    ,
        NFS    
    }Protocol;
    int mProtocol;
    string mPagePath;
    string mURL;
    string mHostName;

public:
    UrlParser(const char* url);
    void parse();
    string getProtocol();



    void dumpUrlParse();
}
