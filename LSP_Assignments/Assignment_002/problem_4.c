// 4) List Files with Type
// • Accept directory name.
// • Print each entry with its type: Regular / Directory / Link / FIFO / Socket / Char / Block
// • Use lstat() for accurate type.


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

void FType(struct stat sobj)
{
    if(S_ISREG(sobj.st_mode))
    {
        printf("Regular\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic link\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("FIFO\n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("Socket\n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("Character\n");
    }
    else if(S_ISBLK(sobj.st_mode))
    {
        printf("Block\n");
    }

}

int main()
{
    DIR * dp = NULL;
    struct stat sobj;
    struct dirent * ptr = NULL;
    char dname[50] = {'\0'};
    char path[256] = {'\0'};

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

        snprintf(path,sizeof(path),"%s/%s",dname,ptr->d_name);
        printf("%s \n",ptr->d_name);
        lstat(path, &sobj);
        FType(sobj);
    }
}