// Named pipe server

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>   
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    int iRet = 0;
    char Buffer[100] = {'\0'};

    fd = open("/tmp/marvellous",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open named pipe \n");
        return -1;
    }

    read(fd, Buffer, 3);
    printf("Data gets successfully read from the pipe by the client\n");
    printf("Data : %s",Buffer);

    close(fd);

    //------------------------------------------------------------------

    fd = open("/tmp/marvellous",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open named pipe \n");
        return -1;
    }

    read(fd, Buffer, 9);
    printf("Data gets successfully read from the pipe by the client\n");
    printf("Data : %s",Buffer);

    close(fd);


    return 0;
}
