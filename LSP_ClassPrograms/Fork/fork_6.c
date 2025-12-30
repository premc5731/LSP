#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>

int main()
{
    if(fork()  == 0)
    {
        printf("child process scheduled \n");
    }
    else
    {
        printf("parent process scheduled \n");
    }
    
    return 0;
    
}