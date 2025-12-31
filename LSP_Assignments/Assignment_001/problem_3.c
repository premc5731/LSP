// 3) Check File Access Permission
// • Accept file name and mode (read/write/execute).
// • Use access() to check permission for current process.
// • Print “Accessible / Not accessible” with reason.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    char fname[50] = {'\0'};
    char mode[15] = {'\0'};
    int flag = 0;
    int ret = -1;

    printf("Enter the file name : \n");
    scanf("%[^\n]",fname);
    getchar();

    printf("Enter the mode : \n");
    scanf("%[^\n]",mode);

    if(strcmp("R",mode) == 0)
    {
        flag = R_OK;
    }
    else if(strcmp("W",mode) == 0)
    {
        flag = W_OK;
    }
    else if(strcmp("X",mode) == 0)
    {
        flag = X_OK;
    }

    ret = access(fname,flag);

    if(ret != 0)
    {
        printf("Not Accessible \n");
        return -1;
    }

    printf("Accessible \n");

    return 0;
}