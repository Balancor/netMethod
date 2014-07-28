#include <iostream>

using namespace std;

class HostInfo {
private:
    char* mHostName;
    list<char*> mHostNameAliasList;
    list<int> mHostPortsList;
    list<char*> mHostIpsList;
public:
    HostInfo();
    void addHostNameAlia(const char* hostname);
    void removeHostNameAlia(const char* hostname);
    void addHostPort(const int port);
    void removeHostPort(const int port);
    void addHostIps(const char* hostip);
    void removeHostIps(const char* hostip);
}
