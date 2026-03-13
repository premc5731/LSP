#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    int iRet = 0;
    iRet = symlink("./lsp.txt", "../test/lspl.txt");

    if(iRet == 0)
    {
        printf("sym link created sucessfully \n");
    }
    else
    {
        printf("error : %s\n",strerror(errno));
    }
    return 0;
}