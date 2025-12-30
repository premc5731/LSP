#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{

    pid_t pid = 0;

    pid = fork();

    if(pid == 0) // child 
    {

        printf("CHILD SAYS PID of current process : %d , PID of parent : %d , return value of fork : %d \n",getpid(), getppid(), pid);
        execl("./commandexe","",NULL);

    }
    else    // parent
    {

        printf("PARENT SAYS PID of current process : %d , PID of parent : %d , return value of fork : %d \n",getpid(), getppid(), pid);

    }
    
    return 0;
    
}