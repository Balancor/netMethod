#ifndef __URLPARSER__
#define __URLPARSER__
#include <iostream>
#include <string>
#include <map>
using namespace std;

class UrlParser {

private:

    enum Protocol {
        UNKNOWN,
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
    map<Protocol, int> mProtocolAndPort;

public:
    UrlParser(const char* url);
    void parse();
    string getProtocol();
    string getHostName();
    string getPagePath();
    int getHostPort();
    void initProtocolAndPortMap();
    void dumpUrlParser();
};
#endif
