#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void * handle = NULL;

    int (*fp) (int, int);

    int iRet = 0;

    handle = dlopen("./libclient_1.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        dlclose(handle);
        return -1;
    }

    fp = (int (*) (int, int))dlsym(handle, "Addition");

    if(fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iRet = fp(10,20);

    printf("Addition is : %d\n",iRet);

    fp = (int (*) (int, int))dlsym(handle, "Substraction");

    if(fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iRet = fp(21,10);

    printf("Substraction is : %d\n",iRet);

    printf("Library gets loaded successfully\n");

    dlclose(handle);

    return 0;
}
