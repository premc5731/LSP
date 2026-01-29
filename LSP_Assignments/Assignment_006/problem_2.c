// 2. Write a C program to demonstrate runtime dynamic linking in Linux.
// Your program should:
// • Load a shared library using dlopen()
// • Fetch function addresses using dlsym()
// • Handle errors using dlerror()
// • Release the library using dlclose()
// Explain the role of each function used in the program.



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
    char * error = NULL;
    int (*fp) (int, int) = NULL;

    handle = dlopen("./mathlib.so",RTLD_LAZY);

    if(handle == NULL)
    {
        error = dlerror();
        printf("Error : %s\n",error);
        return -1;
    }

    fp = (int (*) (int, int))dlsym(handle, "Addition");
    if(fp == NULL)
    {
        error = dlerror();
        printf("Error : %s\n",error);
        return -1;
    }

    iRet = fp(100, 20);
    printf("Addition is : %d\n",iRet);

    fp = (int (*) (int, int))dlsym(handle, "Substraction");
    if(fp == NULL)
    {
        error = dlerror();
        printf("Error : %s\n",error);
        return -1;
    }

    iRet = fp(10, 20);
    printf("Substraction is : %d\n",iRet);

    dlclose(handle);
}
