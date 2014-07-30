#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include "Browser.h"
#include "UrlParser.h"
#include "HostInfo.h"

using namespace std;

Browser::Browser(){
}
void Browser::openPage(char* url, bool newPage){
    mURL = url;
    mParser = new UrlParser(mURL);
    mParser->parse();
    mParser->dumpUrlParser();
}
void Browser::initHostInfo(){
    const int MAX_IP_LEN = 16;
    const int MAX_NUM_IPS = 16;
    struct addrinfo *answer, hint, *curr;
    char currIp[MAX_IP_LEN] ;
    int ret;

    bzero(&hint, sizeof(hint));
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;

    const char* hostName = (mParser->getHostName()).c_str();
    if(NULL == hostName){
        cout<<"Cannot get host name!"<<endl;
        return;
    }
    ret = getaddrinfo(hostName, NULL, &hint, &answer);
    if(ret != 0){
        cout<<"getaddrinfo: \n"<<gai_strerror(ret)<<endl;
        return ;
    }
    HostInfo* hostInfo;
    for(curr = answer; curr != NULL; curr = curr->ai_next){
        cout<<"in loop"<<endl;
        inet_ntop(AF_INET,&(((struct sockaddr_in*)(curr->ai_addr))->sin_addr),
                currIp,16);
        cout<<"after inet_ntop"<<endl;
        hostInfo = new HostInfo();
        cout<<"mParser->getHostName() "<<mParser->getHostName()<<endl;
        hostInfo->setHostName(mParser->getHostName());
        cout<<"mParser->getHostPort() "<<mParser->getHostPort()<<endl;
        hostInfo->setHostPort(mParser->getHostPort());
        cout<<"currIp: "<<currIp<<endl;
        hostInfo->setHostIp(currIp);
        cout<<"mHostInfoList.push_back()"<<endl;
        mHostInfoList.push_back(hostInfo);
    }
    free(hostInfo);
}

void Browser::connectToHost(){
    struct sockaddr_in address;
    int ret;
    int len;
    list<HostInfo*>::iterator hostInfoIterator;
    for(hostInfoIterator = mHostInfoList.begin();
        hostInfoIterator != mHostInfoList.end();
        ++hostInfoIterator){

        mSocket = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(((*hostInfoIterator)->getHostIp()).c_str());
        address.sin_port = htons((*hostInfoIterator)->getHostPort());
        len = sizeof(address);
        ret = connect(mSocket, (struct sockaddr *)&address, len);

        if(ret != -1){
            mCurrentHost = (*hostInfoIterator);
            break;
        }
    }
}

void Browser::dumpPage(){
    const int MAX_COMMAND_LEN = 1024;
    char finalCommand[MAX_COMMAND_LEN];
    char ch;

    sprintf(finalCommand, "GET /%s HTTP/1.1\r\nAccept: */*\r\nUser-Agent:Mozilla/4.0\r\n"
            "Host: %s\r\nConnection:Close\r\n\r\n", (mParser->getPagePath()).c_str(), (mCurrentHost->getHostIp()).c_str());

    write(mSocket, finalCommand, strlen(finalCommand));
    while(read(mSocket, &ch, 1)){
        cout<<ch;
    }
    cout<<endl;

};


Browser::~Browser(){
    close(mSocket);
};
