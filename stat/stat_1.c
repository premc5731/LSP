#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
    struct stat sobj;
    int iRet = 0;
    iRet = stat("Demo.txt",&sobj);

    if(iRet == 0)
    {
        printf("Stat sucesfull");
        
    }
    else
    {
        printf("stat unsucessfull");
    }

    return 0;
}