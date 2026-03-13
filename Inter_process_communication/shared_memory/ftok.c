#include<stdio.h>
#include<sys/ipc.h>

int main()
{
    key_t key;

    key = ftok("./LSP.txt", 's');

    printf("Key is : %d \n",key);
    return 0;
}