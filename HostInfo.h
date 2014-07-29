#include <iostream>
#include <string>

using namespace std;

class HostInfo {
private:
    string mHostName;
    int mHostPort;
    string mHostIp;
public:
    HostInfo();
    ~HostInfo();
    void setHostName(string hostname);
    string getHostName();
    void setHostPort(int prot);
    int getHostPort();
    void setHostIp(string ip);
    string getHostIp();
};
