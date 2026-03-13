// server code

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

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
    pid_t pid = 0;

    char Filename[50] = {'\0'};

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

    ////////////////////////////////////////////////////
    //  loop which accepts client request continuously
    ////////////////////////////////////////////////////

    // loop to accept multiple client request
    while(1)
    {
        ////////////////////////////////////////////////////
        //  step 4 : accept the client request
        ////////////////////////////////////////////////////

        memset(&ClientAddr, 0, sizeof(ClientAddr));

        printf("Server is waiting for client request\n");
        ClientSocket = accept(ServerSocket, (struct sockaddr *)&ClientAddr, &AddrLen);

        if(ClientSocket < 0)
        {
            printf("ERROR : Unable to accept client request\n");
            printf("Error : %s\n",strerror(errno));
            continue;   // return back start of loop
        }

        printf("Client gets connected : %s\n",inet_ntoa(ClientAddr.sin_addr));

        ////////////////////////////////////////////////////
        //  step 5 : create new process to handle client request
        ////////////////////////////////////////////////////

        pid = fork();

        if(pid < 0)
        {
            printf("ERROR : Unable to create a new process for client request \n");
            close(ClientSocket);
            continue;
        }

        // New process gets created for client
        if(pid == 0)    
        {
            printf("New process gets created for client request\n");

            close(ServerSocket);

            iRet = read(ClientSocket, Filename, sizeof(Filename));

            printf("Requested file by client : %s\n",Filename);

            break;
            printf("Child\n");
        }




    }   // End of while
    return 0;
}   // End of main