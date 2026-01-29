// 8. Write a C program to dynamically load a shared library that performs string operations:
// • Count number of lowercase letters
// • Count number of uppercase letters
// • Count number of digits
// The client program should accept a string from the user and call the appropriate functions using dlsym().

#include<stdio.h>
#include<dlfcn.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    void * handle = NULL;
    char str[100] = {'\0'};
    int (*fp) (char*) = NULL;

    printf("please enter a string \n");
    scanf("%[^\n]s",str);

    handle = dlopen("./stringlib.so",RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open so\n");
        return -1;
    }

    fp = (int(*)(char*))dlsym(handle, "Caps");
    if(fp == NULL)
    {
        printf("Error : unable to call function\n");
        return -1;
    }

    iRet = fp(str);
    printf("Number of uppercase letters : %d\n",iRet);

    fp = (int(*)(char*))dlsym(handle, "Smalls");
    if(fp == NULL)
    {
        printf("Error : unable to call function\n");
        return -1;
    }

    iRet = fp(str);
    printf("Number of lowercase letters :%d\n",iRet);

    fp = (int(*)(char*))dlsym(handle, "Digits");
    if(fp == NULL)
    {
        printf("Error : unable to call function\n");
        return -1;
    }

    iRet = fp(str);
    printf("Number of Digits : %d\n",iRet);

    return 0;
}