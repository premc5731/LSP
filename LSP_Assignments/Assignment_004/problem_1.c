// 1. File Copy Utility
// Problem Statement:
// Write a program that copies the contents of one file into another.
// Input:
// Source file name and destination file name as command-line arguments.
// Output:
// Destination file containing an exact copy of source file.
// • Handle file-not-found and permission errors.
// • Destination file should be created if not present.


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

#define BSIZE 1024

int main(int argc, char * argv[])
{
    int fd1 = -1, fd2 = -1, ret = 0;
    char src[50] = {'\0'};
    char dest[50] = {'\0'};
    char Buffer[BSIZE] = {'\0'};
    struct stat sobj;

    if(argc != 3)
    {
        printf("Invalid command line arguments \n");
        return -1;
    }

    strcpy(src,argv[1]);
    strcpy(dest,argv[2]);

    fd1 = open(src, O_RDONLY);
    if(fd1 < 0)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    fd2 = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fd2 < 0)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    while((ret = read(fd1, Buffer, BSIZE)) > 0)
    {
        write(fd2, Buffer, ret);
        memset(Buffer, '\0', BSIZE);
    }

    printf("Copy successfull\n");

    close(fd1);
    close(fd2);

    return 0;
}