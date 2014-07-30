#include <string>
#include "HostInfo.h"

using namespace std;

HostInfo::HostInfo()
{
    cout<<"HostInfo constructor"<<endl;
}

void HostInfo::setHostName(string hostname){
    cout<<"HostInfo setHostName"<<endl;
    mHostName = hostname;
}

string HostInfo::getHostName(){
    cout<<"HostInfo getHostName"<<endl;
    return mHostName;
}
void HostInfo::setHostPort(int port){
    cout<<"HostInfo setHostPort"<<endl;
    mHostPort = port;
}

int HostInfo::getHostPort(){
    cout<<"HostInfo getHostPort"<<endl;
    return mHostPort;
}

void HostInfo::setHostIp(string ip){
    cout<<"HostInfo setHostIp"<<endl;
    mHostIp = ip;
}

string HostInfo::getHostIp(){
    cout<<"HostInfo getHostIp"<<endl;
    return mHostIp;
}
