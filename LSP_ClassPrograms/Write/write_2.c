#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    char Buffer[] = "Helloworld";
    int iRet = 0;

    fd = open("Demo.txt", O_WRONLY);

    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason for failure %s \n",strerror(errno));
        return -1;
    }

    printf("File sucessfully opened with fd %d \n",fd);

    iRet = write(fd,Buffer, 10);    // Overwrite issue 

    printf("%d bytes sucessfully writen \n",iRet);

    close(fd);

    return 0;
}