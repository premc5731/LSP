#include <dlfcn.h>
#include<stdio.h>

int IsPerfect(int No)
{
    int iRet = 0;
    void * handle = NULL;
    int (*fp)(int) = NULL;

    handle = dlopen("./libhelper.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open libhelper.so\n");
        return -1;
    }

    fp = (int(*)(int))dlsym(handle, "SumOfFactors");
    if(fp == NULL)
    {
        printf("Error : unable to load function dlsym()\n");
        return -1;
    }

    iRet = fp(No);

    if(iRet == No)
    {
        return 0;
    }
    return 1;


}