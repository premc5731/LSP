#include<stdio.h>
#include<string.h>
#include<errno.h>

int main()
{
    int iRet = 0;
    iRet = rename("Demo.txt", "Demox.txt");

    if(iRet == 0)
    {
        printf("rename succesfull\n");
    }
    else
    {
        printf("Error : %s \n",strerror(errno));
        return -1;
    }

    return 0;
}