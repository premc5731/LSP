#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    iRet = unlink("Demox.txt");

    if(iRet == 0)
    {
        printf("File deleted sucessfully \n");
    }
    else
    {
        printf("File did not deleted \n");
    }
    return 0;
}