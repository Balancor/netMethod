#include "HostInfo.h"

using namespace std;

HostInfo::HostInfo()
    :mHostName(NULL),
    mHostNameAliasList(NULL),
    mHostPortsList(NULL),
    mHostIpsList(NULL)
{}
void HostInfo::addHostNameAlia(const char* hostname){
    mHostNameAliasList.push_back(hostname);
}
void HostInfo::removeHostNameAlia(const char* hostname){
    mHostNameAliasList.remove(hostname);
}
void HostInfo::addHostPort(const int port){
    mHostPortsList.push_back(port);
}
void HostInfo::removeHostPort(const int port){
    mHostPortsList.remove(port);
}
void HostInfo::addHostIps(const char* hostip){
    mHostIpsList.push_back(hostip);
}
void HostInfo::removeHostIps(const char* hostip){
    mHostIpsList.remove(hostip);
}
