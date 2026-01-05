#include<stdio.h>
#include<unistd.h>
#include<limits.h>
#include<errno.h>
#include<string.h>
int main()
{
    int ret = 0;
    ret = nice(0);

    printf("Current nice value : %d\n",ret);

    ret = nice(-5); //increased priority

    printf("Current nice value : %d\n",ret);

    if(ret == -1)
    {
        printf("Error : %s\n",strerror(errno));
    }

    return 0;
}
