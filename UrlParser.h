#include <iostream>
#include <string>
using namespace std;

class UrlParser {

private:

    enum Protocol {
        HTTPS  ,
        HTTP   ,
        FTP    ,
        SMTP   ,
        DNS    ,
        TELNET ,
        IM     ,
        RIP    ,
        NFS    
    };
    int mProtocol;
    string mPagePath;
    string mUrl;
    string mHostName;

public:
    UrlParser(const char* url);
    void parse();
    string getProtocol();
    void dumpUrlParser();
};
