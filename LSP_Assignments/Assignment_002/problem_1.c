// 1) Read Whole File
// • Accept file name and print full content on console.
// • Use a buffer loop (read() until 0).
// • Show total bytes read.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define BSIZE 1024

int main()
{
    char fname[50] = {'\0'};
    char Buffer[BSIZE] = {'\0'};
    int fd = -1, ret = -1, size = 0;

    printf("Enter file name : \n");
    scanf("%[^\n]",fname);
    getchar();

    fd = open(fname, O_RDONLY);

    if(fd < 0)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    while((ret = read(fd, Buffer, BSIZE)) != 0)
    {
        printf("Data: %s",Buffer);
        memset(Buffer, '\0', BSIZE);
        size = size + ret;
    }

    printf("\nActual Size : %d \n",size);

    return 0;
}