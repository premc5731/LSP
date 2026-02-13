#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{   
    printf("Pid of running process : %d\n",getpid());
    printf("Pid of running parent process : %d\n",getppid());
    
    return 0;
}