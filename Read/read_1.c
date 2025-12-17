#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    char Buffer[100] = {'\0'};
    int iRet = 0;

    fd = open("Demo.txt", O_RDONLY);

    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason for failure %s \n",strerror(errno));
        return -1;
    }

    printf("File sucessfully opened with fd %d \n",fd);

    iRet = read(fd,Buffer, 10);    

    printf("%d bytes sucessfully read \n",iRet);
    printf("Data from file : %s \n",Buffer);

    close(fd);

    return 0;
}