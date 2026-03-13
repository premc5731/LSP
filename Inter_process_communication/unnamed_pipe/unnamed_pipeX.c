#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int pipefd[2] = {0,0};
    int iRet = 0;
    char Buffer[100] = {'\0'};

    iRet = pipe(pipefd);

    if(iRet == 0)
    {
        printf("Unamed pipe gets created successfully\n");
    }
    
    write(pipefd[1], "Jayganesh", 10);

    read(pipefd[0], Buffer, 10);

    printf("Data : %s",Buffer);
    return 0;
}