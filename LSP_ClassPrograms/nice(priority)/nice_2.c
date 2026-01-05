#include<stdio.h>
#include<unistd.h>
#include<limits.h>

int main()
{
    int ret = 0;
    ret = nice(0);

    printf("Current nice value : %d\n",ret);

    ret = nice(5);  //decreased priority

    printf("Current nice value : %d\n",ret);

    return 0;
}
