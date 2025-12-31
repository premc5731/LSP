// 1) Open File
// • Accept file name from user and open it using open().
// • Print: success message + returned file descriptor.
// • Handle errors using perror().

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char fname[100] = {'\0'};
    int fd = -1;

    printf("Enter the file name : \n");
    scanf("%s",fname);

    fd = open(fname,O_RDONLY);
    if(fd < 0)
    {
        printf("Error : Unable to open the file\n");
        return -1;
    }

    printf("File opened successfully with fd : %d \n",fd);
    return 0;
}
