#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main()
{
    printf(" Current Directory name : %s \n", getcwd()); // Error i.e to few argumnets
    return 0;
}