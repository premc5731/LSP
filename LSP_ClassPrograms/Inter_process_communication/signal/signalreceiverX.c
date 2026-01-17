#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void MarvellousHandler(int iNo)
{
    printf("Marvellous message Signal arrived : %d\n",iNo);

}

int main()
{
    printf("PID : %d\n",getpid());

    signal(SIGINT, MarvellousHandler);

    while(1)
    {
        sleep(1);
    }

    return 0;
}