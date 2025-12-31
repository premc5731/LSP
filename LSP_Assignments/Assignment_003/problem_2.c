// 2) Check File Present in Directory
// • Accept directory name and file name.
// • Check whether that file exists in that directory.
// • Print absolute matched path if found.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>

int main()
{
    DIR * dp = NULL;
    struct dirent * ptr = NULL;
    char dname[50] = {'\0'};
    char path[4096] = {'\0'};
    char fname[50] = {'\0'};
    bool flag = true;

    printf("Enter Directory name : \n");
    scanf("%[^\n]",dname);
    getchar();

    printf("Enter file name : \n");
    scanf("%[^\n]",fname);
    getchar();

    dp = opendir(dname);
    if(dp == NULL)
    {
        printf("Error : %s\n",strerror(errno));
        return -1;
    }

    printf("Files : \n");
    while(ptr = readdir(dp))
    {
        if((strcmp(fname,ptr->d_name) == 0))
        {
            realpath(fname, path);
            printf("Absolute path : %s\n",path);
            flag = false;
            break;
        }
    }
    
    if(flag)
    {
        printf("No such file\n");
    }
    
    closedir(dp);
    return 0;
    
}