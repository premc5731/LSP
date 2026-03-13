#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    int fd = 0;
    char Arr[10];

    fd = open("./Demo.txt", O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }

    
    iRet = rename("./Demo.txt", "../test/Demox.txt");

    if(iRet == 0)
    {
        printf("rename succesfull\n");
    }
    else
    {
        printf("Error : %s \n",strerror(errno));
        return -1;
    }

    iRet = read(fd, Arr, 10);
    if(iRet != 0)
    {
        printf("Data from file is : %s \n", Arr);
    }

    close(fd);

    return 0;
}