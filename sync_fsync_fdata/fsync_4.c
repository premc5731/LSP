#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    char Buffer[] = "Indiaismycountry\n";
    int iRet = 0;

    fd = open("Demo.txt", O_CREAT | O_WRONLY | O_APPEND , 0777);

    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason for failure %s \n",strerror(errno));
        return -1;
    }

    printf("File sucessfully opened with fd %d \n",fd);

    iRet = write(fd,Buffer, 17);    

    printf("%d bytes sucessfully writen \n",iRet);

    fsync(fd); // process is in waiting state because fsync blocks untill its work is done
    
    close(fd);

    return 0;
}