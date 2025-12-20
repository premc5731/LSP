#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
    fd = open("./test/lspl.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("file opened wih fd : %d \n",fd);

    
    close(fd);

    return 0;
}