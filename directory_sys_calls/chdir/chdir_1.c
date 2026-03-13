#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main()
{
    char path [50];

    getcwd(path, sizeof(path));
    printf(" Current Directory name : %s \n", path); 

    chdir("./Data");

    getcwd(path, sizeof(path));
    printf(" Current Directory name : %s \n", path);
    return 0;
}