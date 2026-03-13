#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    int iRet = 0;

    fd = open("Demo.txt",O_RDWR);

    iRet = ftruncate(fd, 5);
    if(iRet == 0)
     {
        printf("truncate sucessfully");
     }
     else
     {
        printf("trunctae is unsuccessfull");
     }
    return 0;
}