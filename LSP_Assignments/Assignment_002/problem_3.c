// 3) List All Files From Directory
// • Accept directory name.
// • Use opendir() / readdir() to print only names (skip . and ..).

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>

int main()
{
    DIR * dp = NULL;
    struct dirent * ptr = NULL;
    char dname[50] = {'\0'};

    printf("Enter Directory name : \n");
    scanf("%[^\n]",dname);
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
        if((strcmp(".",ptr->d_name) == 0) || (strcmp("..",ptr->d_name) == 0) )
        {
            continue;
        }
        printf("%s \n",ptr->d_name);
        printf("%d \n",ptr->d_type);
    }

    closedir(dp);

    return 0;
}