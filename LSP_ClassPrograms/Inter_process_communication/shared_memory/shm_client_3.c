#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
    int id = 0;
    char *ptr = NULL;
    key_t key;

    key = ftok(".", 's');

    id = shmget(key, 1024, 0666);

    if(id == -1)
    {
        printf("Failed to allocate shared memory\n");
        return -1;
    }
    
    ptr = shmat(id, NULL, 0);

    if(ptr == (char *)-1)
    {
        printf("Unable to attach memory\n");
        return -1;
    }

    printf("Data : %s\n",ptr);

    shmdt(ptr);

    return 0;
}