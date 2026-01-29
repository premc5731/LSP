// 4. Write a program to demonstrate what happens when:
// • A valid shared library is loaded
// • An invalid or missing function name is passed to dlsym()
// Your program should gracefully handle errors using dlerror() and print meaningful messages.





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

    fp = (int (*) (int, int))dlsym(handle, "Adition");
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
