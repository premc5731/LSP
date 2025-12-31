// 1 Directory Traversal Basics
// Create a program ls_clone.c that takes one directory path and prints:
// • Entry name
// • Type (file/dir/link/other)
// • Size (bytes)
// • Permissions in rwxr-xr-x format
// • Last modified time
// • Skip . and ...
// • Build full path using snprintf(dir + "/" + name).


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<time.h>
#include<dirent.h>

void FType(struct stat sobj)
{
    if(S_ISBLK(sobj.st_mode))
    {
        printf("Block device \n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("Character device file\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory file \n");
    }
    else if(S_ISREG(sobj.st_mode))
    {
        printf("Regular file \n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("Socket file\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("Pipe file\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic file \n");
    }

}

void FPermission(struct stat sobj)
{
    //owner permission
    printf((S_IRUSR & sobj.st_mode) ? "r" : "-");
    printf((S_IWUSR & sobj.st_mode) ? "w" : "-");
    printf((S_IXUSR & sobj.st_mode) ? "x" : "-");

    //group permission
    printf((S_IRGRP & sobj.st_mode) ? "r" : "-");
    printf((S_IWGRP & sobj.st_mode) ? "w" : "-");
    printf((S_IXGRP & sobj.st_mode) ? "x" : "-");

    //other permission
    printf((S_IROTH & sobj.st_mode) ? "r" : "-");
    printf((S_IWOTH & sobj.st_mode) ? "w" : "-");
    printf((S_IXOTH & sobj.st_mode) ? "x" : "-");

}

int main()
{
    struct stat sobj;
    int ret = -1;
    char dname[50] = {'\0'};
    char fname[50] = {'\0'};
    char path[1024] = {'\0'};
    DIR * dp = NULL;
    struct dirent * ptr = NULL;

    printf("Enter the Directory name : \n");
    scanf("%[^\n]",dname);
    getchar();


    dp = opendir(dname);
    if(dp == NULL)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    while(ptr = readdir(dp))
    {
        if((strcmp(".",ptr->d_name) == 0) || (strcmp("..",ptr->d_name) == 0))
        {
            continue;
        }
        
        snprintf(path, sizeof(path), "%s/%s", dname,ptr->d_name);

        ret = stat(path, &sobj);
        if(ret == -1 )
        {
            printf("error : %s",strerror(errno));
            return -1;
        }
        printf("Name : %s\n",ptr->d_name);
        printf("Inode number : %ld\n",sobj.st_ino);
        printf("Hardlink : %ld\n",sobj.st_nlink);
        printf("Actual size : %ld\n", sobj.st_size);
        printf("Block size : %ld\n",sobj.st_blksize);
        printf("user id : %d\n",sobj.st_uid);
        printf("group id : %d\n",sobj.st_gid);
        printf("Last access time : %s",ctime(&sobj.st_atime));
        printf("Last modification time : %s",ctime(&sobj.st_mtime));
        printf("File type is : ");
        FType(sobj);

        printf("Permission : ");
        FPermission(sobj);

        printf("\n-------------------------------------\n");
    }

    printf("\n");

    return 0;
}