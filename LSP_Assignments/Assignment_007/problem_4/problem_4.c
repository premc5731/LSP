// 4. Write a program in C to create a shared library libmystring.so which implements:
// • int MyStrlen(const char *str);
// Requirements
// 1. Do not use strlen() inside the library.
// 2. Client accepts string from user and calls MyStrlen().
// 3. Display length.
// Additional Condition
// • Handle NULL string safely.

#include<stdio.h>
#include<dlfcn.h>

int main()
{
    int iRet = 0;
    void * handle = NULL;
    int (*fp)(char*) = NULL;
    char Buffer[100] = {'\0'};

    printf("Enter a string : \n");
    scanf("%[^\n]s",Buffer);

    handle = dlopen("./libstrlenx.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open libstrlenx.so\n");
        return -1;
    }

    fp = (int(*)(char *))dlsym(handle, "StrlenX");
    if(fp == NULL)
    {
        printf("Error : unable to load function dlsym()\n");
        return -1;
    }

    iRet = fp(Buffer);

    printf("Length of string is : %d\n",iRet);

    dlclose(handle);
}