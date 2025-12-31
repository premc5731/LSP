// 4) Delete All Empty Regular Files
// • Accept directory name.
// • Delete files with size = 0 bytes (regular files only).
// • Print names deleted + total deleted count.


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
    char dname[50] = {'\0'};
    char path[4096] = {'\0'};
    

    printf("Enter Directory name : \n");
    scanf("%[^\n]",dname);
    getchar();

    dp1 = opendir(dname);
    if(dp1 == NULL)
    {
        printf("Error : %s\n",strerror(errno));
        return -1;
    }

    stat(dname, &sobj);

    printf("Deleted files are : \n");

    while ((ptr = readdir(dp1)) != NULL)
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", dname, ptr->d_name);

        if (stat(path, &sobj) != 0)
            continue;

        if (S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size == 0)
            {
                unlink(path);
                printf("%s\n",ptr->d_name);
                count++;
            }
        }
    }

    printf("Total deleted files : %d \n",count);

    closedir(dp1);
    return 0;
    
}