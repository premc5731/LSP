// 2 Recursive Directory Traversal
// Write tree_clone.c which prints a directory as a tree, like:
// root/
// a.txt
// src/
// Ganesh.c
// • Indentation based on recursion depth
// • Print type markers:
// ◦ [D] directory
// ◦ [F] regular file
// ◦ [L] symbolic link
// • Use lstat() to detect symbolic links.
// • Do not follow symlink directories (avoid loops).

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

void Display(char *dname, int depth) 
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

        for (int i = 0; i < depth; i++)
            printf("    ");

        if (S_ISDIR(sobj.st_mode))
        {
            printf("[D] %s\n", ptr->d_name);
        }
        else if (S_ISREG(sobj.st_mode))
        {
            printf("[F] %s\n", ptr->d_name);
        }
        else if (S_ISLNK(sobj.st_mode))
        {
            printf("[L] %s\n", ptr->d_name);
        }

        if (S_ISDIR(sobj.st_mode))
        {
            Display(path, depth + 1);
        }
    }

    closedir(dp);
}

int main() 
{
    char dname[256];
    printf("Enter the directory name: ");
    scanf("%[^\n]", dname);

    printf("%s/\n", dname);
    Display(dname, 1);

    return 0;
}
