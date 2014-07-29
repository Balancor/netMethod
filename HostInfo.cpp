#include <string>
#include "HostInfo.h"

using namespace std;

HostInfo::HostInfo()
    :mHostName(NULL),
    mHostNameAliasList(NULL),
    mHostPortsList(NULL),
    mHostIpsList(NULL)
{}

void HostInfo::setHostName(string hostname){
    mHostName = hostname;
}

string HostInfo::getHostName(){
    return mHostName;
}
void HostInfo::setHostPort(int port){
    mHostPort = port;
}

int HostInfo::getHostPort(){
    return mHostPort;
}

void HostInfo::setHostIp(string ip){
    mHostIp = ip;
}

string HostInfo::getHostIp(){
    return mHostIp;
}
