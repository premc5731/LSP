// 7. Create a shared library that maintains a global variable inside the library.
// The library should provide functions to:
// • Modify the global variable
// • Display its value
// • Reset its value
// Write a dynamically linked client program to demonstrate persistence of the global variable across multiple function
// calls.




#include<stdio.h>
#include<unistd.h>
#include<dlfcn.h>

int main()
{
    int iRet = 0;
    void * handle = NULL;
    char * error = NULL;
    int (*fp1)() = NULL;
    int (*fp2)(int) = NULL;

    handle = dlopen("./global_server_7.so",RTLD_LAZY);

    if(handle == NULL)
    {
        error = dlerror();
        printf("Error : %s\n",error);
        return -1;
    }

    fp1 = (int(*)())dlsym(handle, "Display");
    iRet = fp1();
    printf("Value of Global Variable is : %d\n",iRet);

    fp2 = (int(*)(int))dlsym(handle, "Modify");
    iRet = fp2(11);
    if(iRet == 0)
    {
        printf("Successfully Modified value\n");
    }
    else
    {
        printf("Modify unsuccessfull\n");
    }

    fp1 = (int(*)())dlsym(handle, "Display");
    iRet = fp1();
    printf("Value of Global Variable is : %d\n",iRet);

    fp1 = (int(*)())dlsym(handle, "Reset");
    iRet = fp1();
    if(iRet == 0)
    {
        printf("Successfully Reset value\n");
    }
    else
    {
        printf("Reset unsuccessfll\n");
    } 

    fp1 = (int(*)())dlsym(handle, "Display");
    iRet = fp1();
    printf("Value of Global Variable is : %d\n",iRet);

    dlclose(handle);
}



