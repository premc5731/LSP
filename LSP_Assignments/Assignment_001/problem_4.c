// 4) Display Complete File Information
// • Accept file name and display file metadata using stat():
// ◦ Size, inode, permissions, hard links, owner uid/gid, file type, last access/modify time.


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
    struct stat sobj;
    int ret = -1;
    char fname[50] = {'\0'};

    printf("Enter the file name : \n");
    scanf("%[^\n]",fname);
    getchar();

    
    ret = stat(fname, &sobj);
    if(ret == -1 )
    {
        printf("error : %s",strerror(errno));
        return -1;
    }


    printf("Inode number : %ld\n",sobj.st_ino);
    printf("Hardlink : %ld\n",sobj.st_nlink);
    printf("Actual size : %ld\n", sobj.st_size);
    printf("Block size : %ld\n",sobj.st_blksize);
    printf("user id : %d\n",sobj.st_uid);
    printf("group id : %d\n",sobj.st_gid);
    printf("Last access time : %s\n",ctime(&sobj.st_atime));
    printf("Last modification time : %s\n",ctime(&sobj.st_mtime));

    printf("File type is : %d \n",sobj.st_mode);

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

    printf("Permission \n");

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

    printf("\n");


    return 0;
}