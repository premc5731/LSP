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
    
    DIR *dp = NULL;
    struct dirent *ptr = NULL;

    dp = opendir("./Data");

    if(dp == NULL)
    {
        printf("Error : %s\n",strerror(errno));
        return -1;
    }
    while(ptr = readdir(dp))
    {
        printf("inode no : %ld\n",ptr->d_ino);
        printf("File Name : %s\n",ptr->d_name);
    }

    closedir(dp);




    return 0;
}