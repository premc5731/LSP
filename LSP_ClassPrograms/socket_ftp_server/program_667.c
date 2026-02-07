// Server code

#include <stdio.h>      // printf , scanf
#include <stdlib.h>     // malloc , free
#include <string.h>     // memset, memcmp

#include <fcntl.h>      // close, write , read
#include <unistd.h>     // creat, unlink

#include <sys/socket.h>     // socket , bind, listen, accept, connect
#include <netinet/in.h>     // sockaddr_in , htons

/*
struct sockaddr 
{
    sa_family_t sa_family;
    char   sa_data[14];
}
*/

int main()
{
    int ServerSocket = 0, iRet = 0;
    struct sockaddr_in ServerAddr;  // to configure the socket 
    int port = 1100;

    // step 1 : create TCP socket
    ServerSocket = socket(AF_INET, SOCK_STREAM, 0); // AF_INET == ipv4 . SOCK_STREAM == TCP 
    if(ServerSocket < 0)
    {
        printf("Unable to create socket\n");
        return -1;
    }

    printf("Socket gets created successfully with %d \n",ServerSocket);

    // step 2: attch the socket to IP address and port number

    // set memory with zero
    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = INADDR_ANY;
    ServerAddr.sin_port = htons(port);


    iRet = bind(ServerSocket, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));

    if(iRet < 0)
    {
        printf("bind sys call failed\n");
        close(ServerSocket);
        return -1;
    }

    printf("bind operation with socket is successfull\n");
    return 0;
}