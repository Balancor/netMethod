#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_IPS 16
#define MAX_IP_LEN 16
char** getIP(const char* hostname){
    char tempIps[MAX_NUM_IPS][MAX_IP_LEN];
    struct addrinfo *answer, hint, *curr;
    int ret;

    bzero(&hint, sizeof(hint));
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(hostname, NULL, &hint, &answer);
    if(ret != 0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return NULL;
    }
    int index = 0;
    for(curr = answer; curr != NULL; curr = curr->ai_next){
        inet_ntop(AF_INET,&(((struct sockaddr_in*)(curr->ai_addr))->sin_addr),
                tempIps[index++],16);
    }
    return tempIps;
}

char* httpCommand(const char* page, const char* hostIp){
    const int MAX_COMMAND_LEN = 1024;
    char finalCommand[MAX_COMMAND_LEN];
    fprintf(stderr, "httpCommand: page: %s\nhostIp: %s \n", page, hostIp);

    sprintf(finalCommand, "GET /%s HTTP/1.1\r\nAccept: */*\r\nUser-Agent:Mozilla/4.0\r\n"
        "Host: %s\r\nConnection:Close\r\n\r\n", page, hostIp);

    return finalCommand;
}

int main()
{
    int socket_fd;
    int len;
    struct sockaddr_in address;
    int result;
//    char *strings = "GET #/c/4174/ HTTP/1.1\r\nHost: 192.168.1.12\r\nConnection: Close\r\n\r\n";
    char ch;

    char* hostname = "www.baidu.com";
    char currIp[MAX_IP_LEN] ;


    struct addrinfo *answer, hint, *curr;
    int ret;

    bzero(&hint, sizeof(hint));
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(hostname, NULL, &hint, &answer);
    if(ret != 0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return NULL;
    }
    for(curr = answer; curr != NULL; curr = curr->ai_next){
        fprintf(stderr, "inet_ntop\n");
        inet_ntop(AF_INET,&(((struct sockaddr_in*)(curr->ai_addr))->sin_addr),
                currIp,16);
        fprintf(stderr, "after inet_ntop: %s\n", currIp);

        socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(currIp);
        address.sin_port = htons(80);
        len = sizeof(address);
        result = connect(socket_fd, (struct sockaddr *)&address, len);
        fprintf(stderr, "after connect\n", currIp);

        if(result != -1){
            break;
        }
    }



    char* page = "";
    char* strings = httpCommand(page, currIp);

    write(socket_fd, strings, strlen(strings));
    while(read(socket_fd, &ch, 1)){
        printf("%c", ch);
    }
    printf("\n");
    close(socket_fd);
}
