// 10. Design and implement a mini dynamic library inspection tool.
// The program should:
// • Accept shared library path and symbol name as command-line arguments
// • Load the library using dlopen()
// • Check whether the given symbol exists using dlsym()
// • Display symbol address if found
// • Display appropriate error message otherwise


#include<stdio.h>
#include<dlfcn.h>
#include<unistd.h>

int main(int argc , char * argv[])
{
    int iRet = 0;
    void * handle = NULL;
    void * fp = NULL;

    if(argc != 3)
    {
        printf("Invalid no of commandline arguments \n");
        return -1;
    }

    handle = dlopen(argv[1],RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open shared library\n");
        return -1;
    }

    fp = dlsym(handle, argv[2]);
    if(fp == NULL)
    {
        printf("Error : Symbol does not exist in the shared memory\n");
        return -1;
    }

    printf("Address of symbol %s : %p\n",argv[2],fp);
    

    return 0;
}