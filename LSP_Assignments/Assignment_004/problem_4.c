// 4. File Merge Utility
// Problem Statement:
// Merge multiple input files into a single output file.
// Input:
// output_file file1 file2 file3 ...
// Output:
// Combined file content in order.


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

#define BSIZE 1024

int main(int argc, char * argv[])
{
    int fd1 = -1, fd2 = -1, ret = 0, i = 0;
    char fname[50] = {'\0'};
    char Buffer[BSIZE] = {'\0'};
    struct stat sobj;

    fd1 = creat("Merge.txt", 0777);
    if(fd1 < 0)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    for(i = 1; i < argc; i++)
    {
        strcpy(fname, argv[i]);

        fd2 = open(fname,O_RDONLY);

        if(fd2 < 0)
        {
            printf("Error : %s",strerror(errno));
            return -1;
        }

        while((ret = read(fd2, Buffer, BSIZE)) > 0)
        {
            write(fd1, Buffer, ret);
            memset(Buffer, '\0', BSIZE);
        }

    }

    printf("Merge successfull\n");

    close(fd1);
    close(fd2);

    return 0;
}