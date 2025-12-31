// 5) Read N Bytes From File
// • Accept file name and number of bytes N.
// • Read exactly N bytes using read() and print on console.
// • If file contains less than N, print only available bytes

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    char fname[50] = {'\0'};
    char * Buffer = NULL;
    int flag = 0;
    int N = -1, fd = -1, ret = 0;;

    printf("Enter the file name : \n");
    scanf("%[^\n]",fname);
    getchar();

    printf("Number of bytes : \n");
    scanf("%d",&N);

    fd = open(fname, O_RDONLY);

    if(fd < -1 )
    {
        printf("Error : %s", strerror(errno));
        return -1;
    }

    Buffer = (char*)malloc(N + 1);
    if(Buffer == NULL)
    {
        printf("Error : Unable to allocate memory\n");
        return -1;
    }

    ret = read(fd, Buffer, N);
    printf("Data : %s\n",Buffer);

    return 0;
}