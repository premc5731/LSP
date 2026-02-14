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

    iRet = read(fd, Buffer, 10);

    iRet = lseek(fd, 5, SEEK_CUR);

    printf("updated file offset is : %d \n",iRet);

    memset(Buffer, '\0', SIZE_BUFFER);
    iRet = read(fd, Buffer, 9);
    printf("Data from file is %s \n",Buffer);
    
    close(fd);

    return 0;
}