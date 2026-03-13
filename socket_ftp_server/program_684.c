// Client code

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
//  1st Argument : Ip address
//  2nd Argument : Port number
//  3rd Argument : Target filename
//  4th Argument : New filename
//  ./client    127.0.0.1   9000    Demo.txt    A.txt
//  argv[0]     argv[1]     argv[2] argv[3]     argv[4]
//
//  int argc = 5
//  
////////////////////////////////////////////////////

int main(int argc , char * argv[])
{
    int sock = 0;
    int iRet = 0;
    char *ip = NULL;                //argv[1]
    int port = 0;                   //argv[2]
    char *Filename = NULL;          //argv[3]
    char *OutFilename = NULL;       //argv[4]

    struct sockaddr_in ServerAddr;


    if((argc < 5) || (argc > 5))
    {
        printf("ERROR : Unable to proceed as invalid number of arguments\n");
        printf("Please provide below arguments : \n");
        printf("1st Argument : Ip address\n2nd Argument : Port number\n3rd Argument : Target filename\n4th Argument : New filename");

        return -1;
    }

    // store command line arguments into the variables
    ip = argv[1];
    port = atoi(argv[2]);
    Filename = argv[3];
    OutFilename = argv[4];

    ////////////////////////////////////////////////////
    //  step 5 : Create TCP Socket
    ////////////////////////////////////////////////////

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        printf("ERROR : Unable to create client socket\n");
        return -1;
    }

    ////////////////////////////////////////////////////
    //  step 2 : Connect with server
    ////////////////////////////////////////////////////

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(port);

    // Convert the ip address in to binary format
    inet_pton(AF_INET, ip, &ServerAddr.sin_addr);

    iRet = connect(sock, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("Unable to connect with server\n");
        close(sock);
        return -1;
    }

    // Sending filename to server
    write(sock, Filename, strlen(Filename));
    return 0;
}   // End of main