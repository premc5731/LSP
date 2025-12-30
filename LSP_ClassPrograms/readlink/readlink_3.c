#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>

int main()
{
    char path[100];
    char Arr[20] = {'\0'};
    int iRet = 0;
    int fd = 0;
    memset(path, '\0', sizeof(path));

    iRet = readlink("../test/lspl.txt", path, sizeof(path));

    if(iRet == -1)
    {
        printf("Error : %s", strerror(errno));
        return -1;
    }

    path[iRet] = '\0';

    printf("Data from readlink is : %s \n", path);

    fd = open(path, O_RDONLY);

    if(fd == -1)
    {
        printf("Error : %s", strerror(errno));
        return -1;
    }

    read(fd, Arr, 10);
    printf("Data from original file : %s \n", Arr);

    close(fd);
    return 0;
}