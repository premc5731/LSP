// Client code

#include <stdio.h>      // printf , scanf
#include <stdlib.h>     // malloc , free
#include <string.h>     // memset, memcmp

#include <fcntl.h>      // close, write , read
#include <unistd.h>     // creat, unlink

#include <sys/socket.h>     // socket , bind, listen, accept, connect
#include <netinet/in.h>     // sockaddr_in , htons

#include <arpa/inet.h>      // inet_pton()


int main()
{
    int ClientSocketFD = 0;
    int iRet = 0;
    int port = 11000;
    struct sockaddr_in ClientAddr;  // client configuration struct 
    char Buffer[1024] = {'\0'};

    // step 1: create TCP socket

    ClientSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if(ClientSocketFD < 0)
    {
        printf("ERROR : Unable to create socket\n");
        return -1;
    }

    printf("Socket gets created successfully with ClientSocketFD file : %d\n",ClientSocketFD);

    // step 2 : connect with server

    memset(&ClientAddr, 0, sizeof(ClientAddr));

    ClientAddr.sin_family = AF_INET;
    ClientAddr.sin_port = htons(port);

    // 127.0.0.1(server ip address) -> Binary form
    inet_pton(AF_INET, "127.0.0.1", &ClientAddr.sin_addr);

    iRet = connect(ClientSocketFD, (struct sockaddr *) &ClientAddr, sizeof(ClientAddr));
    if(iRet == -1)
    {
        printf("ERROR : Unable to connect with server\n");
        return -1;
    }

    printf("Successfully Connected with server \n");

    // step 3 : read the data from server
    iRet = read(ClientSocketFD, Buffer, sizeof(Buffer) - 1);

    if(iRet <= 0)
    {
        printf("ERROR : Unable to read the data from server\n");
        return -1;
    }

    printf("Data from server : %s \n",Buffer);

    // step 4: close all resources
    close(ClientSocketFD);

    printf("Terminating the client application ...\n");
    return 0;
}