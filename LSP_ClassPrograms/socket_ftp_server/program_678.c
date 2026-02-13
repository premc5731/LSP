// server code

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

////////////////////////////////////////////////////
// 
//  Commandline Argument Application
//  1st Argument : Port number
//  ./server 9000
//  argv[0]  argv[1]
//
////////////////////////////////////////////////////

int main(int argc , char * argv[])
{
    int ServerSocket = 0;
    int ClientSocket = 0;
    int port = 0;
    int iRet = 0;

    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr;

    socklen_t AddrLen = sizeof(ClientAddr);

    if((argc < 2) || (argc > 2))
    {
        printf("ERROR : Unable to proceed as invalid number of arguments \n");
        printf("Please provide the port number\n");

        return -1;
    }

    // port number of server
    port = atoi(argv[1]);

    ////////////////////////////////////////////////////
    //  step 1 : Create TCP Socket
    ////////////////////////////////////////////////////

    ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(ServerSocket < 0)
    {
        printf("ERROR : Unable to create Server Socket\n");
        return -1;
    }

    ////////////////////////////////////////////////////
    //  step 2 : bind Socket to IP and Port
    ////////////////////////////////////////////////////

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    // Intialise the structure

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(port);
    ServerAddr.sin_addr.s_addr = INADDR_ANY;

    iRet = bind(ServerSocket, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
    if(iRet == -1)
    {
        printf("ERROR : Unable to bind \n");
        close(ServerSocket);
        return -1;
    }

    ////////////////////////////////////////////////////
    //  step 3 : listen for client connections
    ////////////////////////////////////////////////////

    iRet = listen(ServerSocket, 11);
    if(iRet == -1)
    {
        printf("ERROR : Server Unable to listen the request\n");
        close(ServerSocket);
        return -1;
    }

    printf("Server is running on port : %d\n",port);

    
    return 0;
}