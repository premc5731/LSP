// 3) Move All Files (Dir → Dir)
// • Accept source dir and destination dir.
// • Move all regular files:
// ◦ Use rename() if same filesystem
// ◦ Else copy + delete
// • Print count of moved files.



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>

int main()
{
    int count = 0;
    DIR * dp1 = NULL;
    struct stat sobj;
    struct dirent * ptr = NULL;
    char src[50] = {'\0'};
    char dest[50] = {'\0'};
    char srcpath[4096] = {'\0'};
    char destpath[4096] = {'\0'};

    printf("Enter source Directory name : \n");
    scanf("%[^\n]",src);
    getchar();

    printf("Enter destination directory name : \n");
    scanf("%[^\n]",dest);
    getchar();

    dp1 = opendir(src);
    if(dp1 == NULL)
    {
        printf("Error : %s\n",strerror(errno));
        return -1;
    }

    stat(dest, &sobj);
    if(!(S_ISDIR(sobj.st_mode)))
    {
        mkdir(dest,0777);
    }

    while ((ptr = readdir(dp1)) != NULL)
{
    if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        continue;

    snprintf(srcpath, sizeof(srcpath), "%s/%s", src, ptr->d_name);
    snprintf(destpath, sizeof(destpath), "%s/%s", dest, ptr->d_name);

    if (stat(srcpath, &sobj) != 0)
        continue;

    if (S_ISREG(sobj.st_mode))
    {
        if (rename(srcpath, destpath) != 0)
        {
            printf("Error : %s",strerror(errno));
            return -1;
        }
        count++;
    }
}

    printf("Successfully moved %d files \n",count);

    closedir(dp1);
    return 0;
    
}