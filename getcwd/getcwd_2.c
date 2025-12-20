#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
    char Arr[50];
    memset(Arr, '\0', sizeof(Arr));

    getcwd(Arr, sizeof(Arr));
    printf(" Current Directory name : %s \n", Arr); 
    return 0;
}