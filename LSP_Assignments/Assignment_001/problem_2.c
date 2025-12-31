// 2) Open File in Given Mode
// • Accept file name and mode (R, W, RW, A) from user.
// • Convert mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT).
// • Open file accordingly and display fd.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    char fname[50] = {'\0'};
    char mode[15] = {'\0'};
    int flag = 0;
    int fd = -1;

    printf("Enter the file name : \n");
    scanf("%[^\n]",fname);
    getchar();

    printf("Enter the mode : \n");
    scanf("%[^\n]",mode);

    if(strcmp("R",mode) == 0)
    {
        flag = O_RDONLY;
    }
    else if(strcmp("W",mode) == 0)
    {
        flag = O_WRONLY;
    }
    else if(strcmp("RW",mode) == 0)
    {
        flag = O_RDWR;
    }
    else if(strcmp("A",mode) == 0)
    {
        flag = O_APPEND;
    }

    fd = open(fname,flag | O_CREAT);

    if(fd < 0)
    {
        printf("Error : %s\n",strerror(errno));
        return -1;
    }

    printf("Success fd : %d\n",fd);




    return 0;
}