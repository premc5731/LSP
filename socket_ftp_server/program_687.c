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

int ReadLine(int sock, char *line, int max)
{
    int i = 0;
    char ch = '\0';
    int n = 0;

    while(i < max - 1)
    {
        n = read(sock, &ch , 1);
        if(n <= 0)
        {
            break;
        }

        if(ch == '\n')
        {
            break;
        }

        line[i++] = ch;
    }   // End of while

    line[i] = '\0';

    return i;
}

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

    char Header[64] = {'\0'};

    long FileSize = 0;


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

    ////////////////////////////////////////////////////
    //  step 3 : Send file name
    ////////////////////////////////////////////////////    
    write(sock, Filename, strlen(Filename));
    write(sock, "\n", 1);

    ////////////////////////////////////////////////////
    //  step 4 : read the header
    ////////////////////////////////////////////////////

    iRet = ReadLine(sock, Header, sizeof(Header));

    if(iRet <= 0)
    {
        printf("ERROR : server gets diconnected abnormally\n");
        close(sock);
        return -1;
    }

    sscanf(Header, "OK %ld", &FileSize);
    printf("File size is : %ld",FileSize);

    ////////////////////////////////////////////////////
    //  step 5 : creat new file
    ////////////////////////////////////////////////////

    int outfd = 0;

    outfd = open(OutFilename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if(outfd < 0)
    {
        printf("ERROR : Unable to create downloaded file\n");
        return -1;
    }

    char Buffer[1024] = {'\0'};
    long received = 0;
    long remaining = 0;
    int n = 0;
    int toRead = 0;

    while(received < FileSize)
    {
        remaining = FileSize - received;

        if(remaining > 1024)
        {
            toRead = 1024;
        }
        else
        {
            remaining = 700;
        }

        n = read(sock, Buffer, toRead);
        write(outfd, Buffer, n);

        received = received - n;
    }   // End of while

    close(outfd);
    close(sock);

    if(received == FileSize)
    {
        printf("Download Complete...\n");
        return 0;
    }
    else
    {
        printf("Download failed \n");
        return -1;
    }
    return 0;
}   // End of main