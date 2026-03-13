#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void MarvellousHandler(int iNo)
{
    if(iNo == SIGUSR1)
    {
        printf("Marvellous message Signal arrived : SIGUSR1\n");
    }
    else if(iNo == SIGINT)
    {
        printf("Marvellous message Signal arrived : SIGINT\n");
    }

}

int main()
{
    printf("PID : %d\n",getpid());

    signal(SIGINT, MarvellousHandler);
    signal(SIGUSR1, MarvellousHandler);

    while(1)
    {
        sleep(1);
    }

    return 0;
}