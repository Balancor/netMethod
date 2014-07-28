#include "UrlParse.h"

using namespace std;

UrlParser::UrlParser(const char* url){
    mUrl = url;
}
void UrlParser::parse(){
    int fileIndex = 0; 
    mUrl = getProtocol();
    fileIndex = find_first_of(mUrl);
    mHostName = mUrl.substr(0, fileIndex - 1)
    mPagePath = mUrl.substr(fileIndex, mUrl.size());

}

string UrlParser::getProtocol(){
    char* protocolType = NULL;
    if(!mUrl.find("https")){
        mProtocol = Protocol.HTTPS;
        protocolType = "https";
    } else if(!mUrl.find("http")){
        mProtocol = Protocol.HTTP;
        protocolType = "http";
    } else if(!mUrl.find("ftp")){
        mProtocol = Protocol.FTP;
        protocolType = "ftp";
    } else if(!mUrl.find("smtp")){
        mProtocol = Protocol.SMTP;
        protocolType = "smtp";
    } else if(!mUrl.find("dns")){
        mProtocol = Protocol.DNS;
        protocolType = "dns";
    } else if(!mUrl.find("telnet")){
        mProtocol = Protocol.TELNET;
        protocolType = "telnet";
    } else if(!mUrl.find("im")){
        mProtocol = Protocol.IM;
        protocolType = "telnet";
    } else if(!mUrl.find("rip")){
        mProtocol = Protocol.RIP;
        protocolType = "rip";
    } else if(!mUrl.find("nfs")){
        mProtocol = Protocol.NFS;
        protocolType = "nfs";
    }
    return mUrl.erase(0, strlen(protocolType)+2);
}

void UrlParser::dumpUrlParser(){
    cout<<"mProcotol: "<<mProcotol<<endl;
    cout<<"mHostName: "<<mHostName<<endl;
    cout<<"mPagePath: "<<mPagePath<<endl;
}
