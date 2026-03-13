#include<stdio.h>
#include<unistd.h>
#include<limits.h>

int main()
{
    int ret = 0;
    ret = nice(0);  //default average priority

    printf("Current nice value : %d\n",ret);

    return 0;
}
