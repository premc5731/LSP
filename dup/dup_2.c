#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    int fd1 = 0, fd2 = 0;

    fd1 = open("./Demo.txt",O_RDONLY);
    printf("fd1 : %d \n",fd1); // 3

    fd2 = dup2(fd1, 11);
    printf("fd2 : %d \n",fd2); // 11

    return 0;
}