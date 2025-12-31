// 2. File Copy with Offset
// Problem Statement:
// Copy a file starting from a given byte offset of the source file.
// Input:
// source_file destination_file offset
// Output:
// Partial file copied starting from offset.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#define BSIZE 1024

int main(int argc, char * argv[])
{
    int fd1 = -1, fd2 = -1, ret = 0, offset = -1;
    char src[50] = {'\0'};
    char dest[50] = {'\0'};
    char Buffer[BSIZE] = {'\0'};


    if(argc != 4)
    {
        printf("Invalid command line arguments \n");
        return -1;
    }

    strcpy(src,argv[1]);
    strcpy(dest,argv[2]);
    offset = atoi(argv[3]);

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

    lseek(fd1, offset, SEEK_SET);
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