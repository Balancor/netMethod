#include <string>
#include "HostInfo.h"

using namespace std;

HostInfo::HostInfo()
    :mHostName(NULL),
    mHostNameAliasList(NULL),
    mHostPortsList(NULL),
    mHostIpsList(NULL)
{}

void HostInfo::setHostName(const char* hostname){
    mHostName = string(hostname);
}

string HostInfo::getHostName(const char* hostname){
    return mHostName;
}
void HostInfo::setHostPort(int port){
    mHostPort = port;
}

int HostInfo::getHostPort(){
    return mHostPort;
}

void HostInfo::setHostIp(const char* ip){
    mHostIp = string(ip);
}

string HostInfo::getHostIp(){
    return mHostIp;
}
