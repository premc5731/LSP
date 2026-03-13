#include<stdio.h>
#include<unistd.h>

int main()
{

    printf("pid of current process is : %d \n",getpid());

    printf("pid of parent process is : %d \n",getppid());
    return 0;
}