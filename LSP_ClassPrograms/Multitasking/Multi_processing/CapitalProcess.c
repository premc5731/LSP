#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    int iRet = 0, iCount = 0, i = 0;
    char Buffer[1024] = {'\0'};

    fd = open("PPA.txt", O_RDONLY);
    printf("CapC's fd : %d\n",fd);

    while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCount++;
            }
        }
    }

    close(fd);

    printf("Number of capital characters : %d\n",iCount);

    write(1, &iCount, sizeof(int));
    return 0;
}