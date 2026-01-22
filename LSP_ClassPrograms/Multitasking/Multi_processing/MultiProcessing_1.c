#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>

int main()
{   pid_t pid1 = 0;
    pid_t pid2 = 0;

    pid1 = fork();

    if(pid1 == 0) 
    {
        execl("./capitalprocess","",NULL);

    }
    else    
    {
    }

    pid2 = fork();

    if(pid2 == 0) 
    {
        execl("./smallprocess","",NULL);

    }
    else    
    {
    }
    
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("End of main process\n");
    return 0;
}