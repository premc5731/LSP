// 1) Copy File Contents (source → destination)
// • Accept source_file and dest_file.
// • Create destination if not exists (O_CREAT | O_TRUNC).
// • Copy using buffered read()/write() loop.
// • Preserve permissions (optional bonus using stat() + chmod()).

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

#define BSIZE 1024

int main()
{
    int fd1 = -1, fd2 = -1, ret = 0;
    char src[50] = {'\0'};
    char dest[50] = {'\0'};
    char Buffer[BSIZE] = {'\0'};
    struct stat sobj;

    printf("Enter source file : \n");
    scanf("%[^\n]",src);
    getchar();

    printf("Enter destination file : \n");
    scanf("%[^\n]",dest);
    getchar();

    fd1 = open(src, O_RDONLY);
    if(fd1 < 0)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    fd2 = open(dest, O_WRONLY | O_APPEND | O_CREAT, 0777);
    if(fd2 < 0)
    {
        printf("Error : %s",strerror(errno));
        return -1;
    }

    while(ret = read(fd1, Buffer, BSIZE))
    {
        write(fd2, Buffer, ret);
        memset(Buffer, '\0', BSIZE);
    }

    fstat(fd1,&sobj);
    // printf("mode : %o",sobj.st_mode & 0777);

    fchmod(fd2,sobj.st_mode & 0777);

    printf("Copy successfull\n");

    return 0;
}