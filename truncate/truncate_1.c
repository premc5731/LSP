#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = truncate("Demo.txt",2);
     if(iRet == 0)
     {
        printf("truncate sucessfully");
     }
     else
     {
        printf("trunctae is unsuccessfull");
     }
    return 0;
}