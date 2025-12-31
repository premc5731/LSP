// 3 File Counter + Size Report
// Create dir_report.c that recursively calculates:
// • Total number of files
// • Total number of directories
// • Total size of regular files (in bytes)
// • Largest file name + size
// • Count a directory when you enter it.
// • For size: consider only regular files (S_ISREG).• Ignore symlink target size (treat symlink as link object only).
// Output:
// Files: 120
// Dirs : 15
// Total Size: 9823412 bytes
// Largest: Marvellous.mp4 (2341123 bytes)

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

struct Data
{
    int fCount;
    int dCount;
    long int Size;
    char fname[50];
    long int maxsize;

};

void Report(char *dname,struct Data * dobj) 
{
    struct dirent *ptr = NULL;
    DIR *dp = NULL;
    char path[1024];
    struct stat sobj;

    dp = opendir(dname);

    if (dp == NULL) {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    while (ptr = readdir(dp))
     {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", dname, ptr->d_name);

        if (lstat(path, &sobj) < 0) 
        {
            printf("Error : %s\n",strerror(errno));
            continue;
        }

        if (S_ISDIR(sobj.st_mode))
        {
            dobj->dCount++;
        }
        else if (S_ISREG(sobj.st_mode))
        {
            dobj->fCount++;
            dobj->Size = dobj->Size + sobj.st_size;

            if(sobj.st_size > dobj->maxsize)
            {
                dobj->maxsize = sobj.st_size;
                strcpy(dobj->fname, ptr->d_name);
            }
        }

        if (S_ISDIR(sobj.st_mode))
        {
            Report(path, dobj);
        }
    }

    closedir(dp);
}

int main() 
{
    struct Data dobj;
    char dname[256];

    dobj.dCount = 0;
    dobj.fCount = 0;
    dobj.Size = 0;
    dobj.maxsize = 0;
    memset(dobj.fname,'\0', 50);
    
    printf("Enter the directory name: ");
    scanf("%[^\n]", dname);

    Report(dname, &dobj);

    printf("Files %d\n",dobj.fCount);
    printf("Dir : %d\n",dobj.dCount);
    printf("Size : %ld\n",dobj.Size);
    printf("Largest file : %s\n",dobj.fname);

    return 0;
}
