#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    iRet = link("Demo.txt", "Demox.txt");

    if(iRet == 0)
    {
        printf("link is sucessfull \n");
    }
    return 0;
}