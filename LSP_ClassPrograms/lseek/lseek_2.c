#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

#define SIZE_BUFFER 100
int main()
{
    int fd = 0;
    char Buffer[SIZE_BUFFER];
    int iRet = 0;

    memset(Buffer, '\0', SIZE_BUFFER); 
    fd = open("Demo.txt", O_RDONLY);

    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason for failure %s \n",strerror(errno));
        return -1;
    }

    printf("File sucessfully opened with fd %d \n",fd);

    iRet = lseek(fd, -10, SEEK_END);

    printf("updated file offset is : %d \n",iRet);

    
    close(fd);

    return 0;
}