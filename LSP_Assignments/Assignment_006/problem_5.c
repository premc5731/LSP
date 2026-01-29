// 5. Explain the difference between RTLD_LAZY and RTLD_NOW flags used with dlopen().
// Write a program that loads the same shared library twice:
// • Once using RTLD_LAZY
// • Once using RTLD_NOW
// Observe and explain the behavior.

#include<stdio.h>
#include<unistd.h>
#include<dlfcn.h>

int main()
{
    int iRet = 0;
    void * handle = NULL;
    char * error = NULL;
    int (*fp) (int, int) = NULL;

    handle = dlopen("./problem_5_server.so",RTLD_LAZY);

    if(handle == NULL)
    {
        error = dlerror();
        printf("Error from RTLD_LAZY : %s\n",error);
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

    // fp = (int (*) (int, int))dlsym(handle, "Substraction");
    // if(fp == NULL)
    // {
    //     error = dlerror();
    //     printf("Error from RTLD_LAZY dlsym : %s\n",error);
    //     return -1;
    // }

    //-----------------------------------------

    dlclose(handle);

    handle = dlopen("./problem_5_server.so",RTLD_NOW);

    if(handle == NULL)
    {
        error = dlerror();
        printf("Error from RTLD_NOW: %s\n",error);
        return -1;
    }

    // fp = (int (*) (int, int))dlsym(handle, "Substraction");
    // if(fp == NULL)
    // {
    //     error = dlerror();
    //     printf("Error from RTLD_NOW dlsym : %s\n",error);
    //     return -1;
    // }



    dlclose(handle);
}

/*
RTLD_LAZY performs lazy symbol resolution, so missing symbols cause errors only when the function is invoked at runtime.
RTLD_NOW resolves all symbols during dlopen(), so missing symbols cause immediate load-time failure.
*/