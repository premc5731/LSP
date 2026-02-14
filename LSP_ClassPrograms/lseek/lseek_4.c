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
    fd = open("Hole.txt", O_WRONLY | O_CREAT);

    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason for failure %s \n",strerror(errno));
        return -1;
    }

    printf("File sucessfully opened with fd %d \n",fd);

    iRet = lseek(fd,4100,SEEK_SET);
    printf("current offset is : %d \n",iRet);

    iRet = write(fd,"END",3);
    printf("%d bytes gets written sucessfully \n",iRet);
    
    close(fd);

    return 0;
}