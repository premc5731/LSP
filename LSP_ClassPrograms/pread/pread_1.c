#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

// pread here p == positional
/*
it is used to read the data without changing or effecting the offset widely used in muli thread application */

int main()
{
    int fd = 0;
    off_t offset = 0;
    char Buffer[100];

    fd = open("./Demo.txt",O_RDONLY);

    offset = lseek(fd, 0, SEEK_SET);

    printf("Current offset is : %ld \n", offset);  // 0

    read(fd, Buffer, 10);

    offset = lseek(fd, 0, SEEK_CUR);

    printf("Current offset is : %ld \n", offset);  // 10
    
    return 0;
}