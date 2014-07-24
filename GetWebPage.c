#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

char** getIP(const char* hostname){
    char** tempIps;
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
        inet_ntop(AF_INET,&(((struct sockaddr_in*)(curr->ai_addr))->sin_addr),
                *tempIps,16);
    }
    return tempIps;
}

char* httpCommand(const char* page, const char* hostIp){
    char* command ="GET ";
    int lenOfPage = 0;
    strcat(command, page);
    char httpVersion[] = " HTTP/1.1\r\nHost: ";
    strcat(command, httpVersion);
    strcat(command, hostIp);
    char closeHttp[] = "\r\nConnection: Close\r\n\r\n";
    strcat(command, closeHttp);
    printf("Command: %s\n", command);
    return command;
}

int main()
{
    int socket_fd;
    int len;
    struct sockaddr_in address;
    int result;
    char *strings = "GET #/c/4174/ HTTP/1.1\r\nHost: 192.168.1.12\r\nConnection: Close\r\n\r\n";
    char ch;

    char* hostname = "www.baidu.com";
    char** hostIps = NULL;
    char* currIp = NULL;
    int index = 0;
    hostIps = getIP(hostname);
    do{
        currIp = hostIps[index++];
        socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(currIp);
        address.sin_port = htons(80);
        len = sizeof(address);
        result = connect(socket_fd, (struct sockaddr *)&address, len);

        if(result != -1){
            break;
        }
    }while(currIp == NULL);
    char* page = " ";
    httpCommand(page, currIp);

    write(socket_fd, strings, strlen(strings));
    while(read(socket_fd, &ch, 1)){
        printf("%c", ch);
    }
    close(socket_fd);
}
