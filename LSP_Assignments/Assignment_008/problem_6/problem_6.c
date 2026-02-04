// 6. Shared Library Build (.so)
// Create:
// • libmath.so (PIC code)
// Use flags:
// • -fPIC
// • -shared
// Make targets:
// • so
// • app
// • run (must set LD_LIBRARY_PATH=.)
// Deliverable: working shared library app

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    int No1 = 0, No2 = 0;

    void * handle = NULL;
    int (*fp)(int, int) = NULL;
    int Ans = 0;

    handle = dlopen("./libmathlib.so",RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : error at handle\n");
        return -1;
    }

    printf("Enter first number : \n");
    scanf("%d",&No1);

    printf("Enter second number : \n");
    scanf("%d",&No2);

    fp = (int(*)(int,int))dlsym(handle, "Addition");
    if(fp == NULL)
    {
        printf("Error : error at Addition\n");
        return -1;
    }
    
    Ans = fp(No1, No2);

    printf("Addition is : %d\n",Ans);

    fp = (int(*)(int,int))dlsym(handle, "Substraction");
    if(fp == NULL)
    {
        printf("Error : error at Substraction\n");
        return -1;
    }
    
    Ans = fp(No1, No2);

    printf("Substraction is : %d\n",Ans);

    dlclose(handle);

    return 0;
}