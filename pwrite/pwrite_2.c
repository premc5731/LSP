#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

// pwrite here p == positional
/*
it is used to write the data without changing or effecting the offset widely used in multi thread application */

int main()
{
    int fd = 0, iRet = 0;
    off_t offset = 0;
    char Buffer[100] = "Pune";

    fd = open("./Demox.txt",O_WRONLY);
    
    iRet = pwrite(fd, Buffer, 4, 10);
    offset = lseek(fd, 0, SEEK_CUR);

    printf("Current offset is : %ld \n", offset);  
    
    return 0;
}