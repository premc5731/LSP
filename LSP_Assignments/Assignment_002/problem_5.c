// 5) Find Largest File in Directory
// • Accept directory name.
// • Find and print:
// ◦ largest file name
// ◦ its size in bytes
// • Consider only regular files (ignore directories).


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

int FTypeSize(struct stat sobj)
{
    int size = -1;

    if(S_ISREG(sobj.st_mode))
    {
        size = sobj.st_size;
    }

    return size;
    
}

int main()
{
    DIR * dp = NULL;
    struct stat sobj;
    struct dirent * ptr = NULL;
    char dname[50] = {'\0'};
    char path[256] = {'\0'};
    int size = 0, maxsize = 0;
    char fname[50] = {'\0'};

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
        lstat(path, &sobj);
        size = FTypeSize(sobj);

        if(size > maxsize)
        {
            maxsize = size;
            memset(fname, '\0', 50);
            strcpy(fname, ptr->d_name);
        }
    }
    
        if(maxsize > 0)
        {
            printf("Largest file : %s\n",fname);
            printf("Size : %d\n",maxsize);
        }
        else
        {
            printf("No Regular files\n");
        }
        
        closedir(dp);
        return 0;
    
}