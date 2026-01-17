#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int pipefd[2] = {0,0};
    int iRet = 0;
    char Buffer[100] = {'\0'};

    pipe(pipefd);

    iRet = fork();

    if(iRet == 0)   // child
    {
        close(pipefd[0]);
        write(pipefd[1], "JayGanesh", 10);
        exit(0);
    }
    else            // parent
    {
        
        close(pipefd[1]);
        read(pipefd[0], Buffer, 10);
        printf("Data from pipe is : %s",Buffer);

    }

    return 0;
}