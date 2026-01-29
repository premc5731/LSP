// 1. Write a program to create a shared library (.so) that contains two functions:
// • Addition(int, int)
// • Substraction(int, int)
// Write a separate client program that loads this library at runtime using dlopen() and calls both functions using
// dlsym().


#include<stdio.h>
#include<unistd.h>
#include<dlfcn.h>

int main()
{
    int iRet = 0;
    void * handle = NULL;
    int (*fp) (int, int) = NULL;

    handle = dlopen("./mathlib.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Error in dlopen\n");
        return -1;
    }

    fp = (int (*) (int, int))dlsym(handle, "Addition");
    if(fp == NULL)
    {
        printf("Unable to load library function\n");
        return -1;
    }

    iRet = fp(10, 20);
    printf("Addition is : %d\n",iRet);

    fp = (int (*) (int, int))dlsym(handle, "Substraction");
    if(fp == NULL)
    {
        printf("Unable to load library function\n");
        return -1;
    }

    iRet = fp(10, 20);
    printf("Substraction is : %d\n",iRet);

    dlclose(handle);
}
