// 5. Reverse File Content
// Problem Statement:
// Display the contents of a file in reverse order.
// Input:
// File name.
// Output:
// File content printed in reverse.


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
    char fname[50] = {'\0'};
    char c = '\0';
    struct stat sobj;
    off_t size = 0, i = 0;

    if(argc != 2)
    {
        printf("Invalid command line arguments \n");
        return -1;
    }

    strcpy(fname,argv[1]);

    fd1 = open(fname, O_RDONLY);
    if(fd1 < 0)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    size = lseek(fd1,0,SEEK_END);

    for(i = size-1; i >= 0; i--)
    {
        pread(fd1,&c, 1, i);
        putchar(c);
    }

    printf("\n");


    close(fd1);
    return 0;
}