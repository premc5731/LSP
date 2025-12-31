// 2) Write String to File
// • Accept file name and a string from user.
// • Write string using write() (append mode by default).
// • Print number of bytes written.


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
    char Data[BSIZE] = {'\0'};
    int fd = -1, ret = -1, size = 0;

    printf("Enter file name : \n");
    scanf("%[^\n]",fname);
    getchar();

    printf("Enter the data \n");
    scanf("%[^\n]",Data);
    getchar();

    fd = open(fname, O_WRONLY | O_APPEND);

    if(fd < 0)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    ret = write(fd, Data, strlen(Data));
    if(ret < 0)
    {
        printf("write unsuccessfull\n");
        return -1;
    }

    printf("Data written successfully\n");
    printf("Number of bytes written: %d\n", ret);


    return 0;
}