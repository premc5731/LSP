// Client code

#include <stdio.h>      // printf , scanf
#include <stdlib.h>     // malloc , free
#include <string.h>     // memset, memcmp

#include <fcntl.h>      // close, write , read
#include <unistd.h>     // creat, unlink

#include <sys/socket.h>     // socket , bind, listen, accept, connect
#include <netinet/in.h>     // sockaddr_in , htons


int main()
{
    int ClientSocketFD = 0;

    // step 1: reate TCP socket

    ClientSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if(ClientSocketFD < 0)
    {
        printf("ERROR : Unable to create socket\n");
        return -1;
    }

    printf("Socket gets created successfully wit ClientSocketFD : %d\n",ClientSocketFD);

    return 0;
}