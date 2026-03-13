#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
    int id = 0;

    id = shmget(11, 1024, 0666);

    if(id != -1)
    {
        printf("Shared  memory gets allocated by client\n");
    }

    return 0;
}