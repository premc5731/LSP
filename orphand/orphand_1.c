//Output depends on scheduling

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    pid_t pid = 0;

    pid = fork();

    if(pid == 0)    // child
    {
        printf("Child process is running\n");
        printf("PID of child is %d and ppid of child is : %d\n",getpid(),getppid());
    }
    else            // parent
    {
        printf("Parent process is running\n");
        printf("PID of parent is %d and ppid of parent is : %d\n",getpid(),getppid());

    }

    return 0;
}