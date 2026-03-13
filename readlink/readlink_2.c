#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>

int main()
{
    char path[100];
    int iRet = 0;
    memset(path, '\0', sizeof(path));

    iRet = readlink("../test/lspl.txt", path, sizeof(path));

    if(iRet == -1)
    {
        printf("Error : %s", strerror(errno));
        return -1;
    }

    path[iRet] = '\0';

    printf("Data from readlink is : %s \n", path);

    return 0;
}