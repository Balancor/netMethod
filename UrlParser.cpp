#include <string.h>
#include "UrlParser.h"

using namespace std;

UrlParser::UrlParser(const char* url){
    mUrl = url;
}
void UrlParser::parse(){
    int fileIndex = 0; 
    mUrl = getProtocol();
    cout<<"after getProtocol(), remain string: "
        <<mUrl<<endl;
    fileIndex = mUrl.find_first_of("/");
    if(fileIndex < 0 ){
        mHostName = mUrl;
        mPagePath = ""; 
    } else {
        mHostName = mUrl.substr(0, fileIndex - 1);
        mPagePath = mUrl.substr(fileIndex, mUrl.size());
    }
}

string UrlParser::getProtocol(){
    char* protocolType = NULL;
    if(!mUrl.find("https")){
        mProtocol = HTTPS;
        protocolType = "https";
    } else if(!mUrl.find("http")){
        mProtocol = HTTP;
        protocolType = "http";
    } else if(!mUrl.find("ftp")){
        mProtocol = FTP;
        protocolType = "ftp";
    } else if(!mUrl.find("smtp")){
        mProtocol = SMTP;
        protocolType = "smtp";
    } else if(!mUrl.find("dns")){
        mProtocol = DNS;
        protocolType = "dns";
    } else if(!mUrl.find("telnet")){
        mProtocol = TELNET;
        protocolType = "telnet";
    } else if(!mUrl.find("im")){
        mProtocol = IM;
        protocolType = "telnet";
    } else if(!mUrl.find("rip")){
        mProtocol = RIP;
        protocolType = "rip";
    } else if(!mUrl.find("nfs")){
        mProtocol = NFS;
        protocolType = "nfs";
    }
    cout<<"protocolType: "<<protocolType<<endl;
    cout<<"strlen(protocolType): "<<strlen(protocolType)<<endl;
    return mUrl.erase(0, strlen(protocolType)+3);
}

void UrlParser::dumpUrlParser(){
    cout<<"mProtocol: "<<mProtocol<<endl;
    cout<<"mHostName: "<<mHostName<<endl;
    cout<<"mPagePath: "<<mPagePath<<endl;
}
