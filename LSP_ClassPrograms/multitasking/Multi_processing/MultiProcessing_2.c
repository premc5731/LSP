#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>

int main()
{   pid_t pid1 = 0;
    pid_t pid2 = 0;
    int pipe1[2];
    int pipe2[2];
    int Ret = 0, Count1 = 0, Count2 = 0, fd = 0;
    char str[50] = {'\0'};

    if(pipe(pipe1) || pipe(pipe2))
    {
        perror("Pipe error : ");
        return -1;
    }

    pid1 = fork();

    if(pid1 == 0) 
    {
        close(pipe1[0]);
        dup2(pipe1[1], 1);
        execl("./capitalprocess","",NULL);

    }
    else    
    {
    }

    pid2 = fork();

    if(pid2 == 0) 
    {
        close(pipe2[0]);
        dup2(pipe2[1], 1);
        execl("./smallprocess","",NULL);

    }
    else    
    {
    }
    
    close(pipe1[1]);
    close(pipe2[1]);

    read(pipe1[0], &Count1, sizeof(int));
    read(pipe2[0], &Count2, sizeof(int));

    fd = creat("./processing.log", 0777);
    if(fd  < 0)
    {
        perror("Error : ");
        return -1;
    }

    waitpid(pid1, NULL, 0);
    Ret = snprintf(str, sizeof(str), "No of Capital characters : %d\n", Count1);
    write(fd, str, Ret);

    waitpid(pid2, NULL, 0);
    Ret = snprintf(str, sizeof(str), "No of Small characters : %d\n", Count2);
    write(fd, str, Ret);

    printf("End of main process\n");
    return 0;
}