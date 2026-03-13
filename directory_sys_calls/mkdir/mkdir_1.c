#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    int iRet = 0;
    iRet = mkdir("./Data",0777);

    if(iRet == 0)
    {
        printf("Directory gets created succesfully \n");
    }
    
    return 0;
}