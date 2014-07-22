#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

void getIp(){
    char* host_name = "www.baidu.com";
    struct hostent* host;
    
    host = gethostbyname(host_name);
    if(NULL == host){
        perror("Cannot get host by hostname");
        exit(EXIT_FAILURE);
    }
    printf("host ip = %s\n", inet_ntoa(*((struct in_addr*)host->h_addr)));
    exit(EXIT_SUCCESS);

}


int main()
{
    int socket_fd;
    int len;
    struct sockaddr_in address;
    int result;
    char *strings = "GET #/c/4174/ HTTP/1.1\r\nHost: 192.168.1.12\r\nConnection: Close\r\n\r\n";
    char ch;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.1.12");
    address.sin_port = htons(8080);

    len = sizeof(address);
    result = connect(socket_fd, (struct sockaddr *)&address, len);

    if(result == -1){
        perror("oops: client1");
        return 1;
    }
    write(socket_fd, strings, strlen(strings));
    while(read(socket_fd, &ch, 1)){
        printf("%c", ch);
    }
    getIp();
    close(socket_fd);
}
