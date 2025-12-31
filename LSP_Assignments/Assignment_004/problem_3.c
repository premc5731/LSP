// 3. File Copy Using pread & pwrite
// Problem Statement:
// Copy a file using pread() and pwrite() without changing the file offset.
// Input:
// Source and destination file names.
// Output:
// Copied file identical to source.



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

#define BSIZE 1024

int main(int argc, char * argv[])
{
    int fd1 = -1, fd2 = -1, ret = 0, offset = 0;
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

    while((ret = pread(fd1, Buffer, BSIZE, offset)) > 0)
    {
        pwrite(fd2, Buffer, ret, offset);
        memset(Buffer, '\0', BSIZE);
        offset = offset + ret;
    }

    printf("Copy successfull\n");

    close(fd1);
    close(fd2);

    return 0;
}