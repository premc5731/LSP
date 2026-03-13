#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
    int pid = 0;

    printf("Enter the pid of process : \n");
    scanf("%d",&pid);

    kill(pid, SIGINT);


    return 0;
}