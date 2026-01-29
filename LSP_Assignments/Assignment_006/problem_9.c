// 9. Write a program to demonstrate the use of function pointers with dlsym().
// • Store addresses of multiple dynamically loaded functions in an array of function pointers.
// • Invoke functions using this array.
// • Display function addresses along with results.


#include<stdio.h>
#include<dlfcn.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    void * handle = NULL;
    char str[100] = {'\0'};
    int (*arr[3]) (char*);

    printf("please enter a string \n");
    scanf("%[^\n]s",str);

    handle = dlopen("./stringlib.so",RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open so\n");
        return -1;
    }

    arr[0] = (int(*)(char*))dlsym(handle, "Caps");
    if(arr[0] == NULL)
    {
        printf("Error : unable to call function\n");
        return -1;
    }

    iRet = arr[0](str);
    printf("Address of arr[0] : %p\n",arr[0]);
    printf("Number of uppercase letters : %d\n",iRet);

    arr[1] = (int(*)(char*))dlsym(handle, "Smalls");
    if(arr[1] == NULL)
    {
        printf("Error : unable to call function\n");
        return -1;
    }

    iRet = arr[1](str);
    printf("Address of arr[1] : %p\n",arr[1]);
    printf("Number of lowercase letters :%d\n",iRet);

    arr[2] = (int(*)(char*))dlsym(handle, "Digits");
    if(arr[2] == NULL)
    {
        printf("Error : unable to call function\n");
        return -1;
    }

    iRet = arr[2](str);
    printf("Address of arr[2] : %p\n",arr[2]);
    printf("Number of Digits : %d\n",iRet);

    return 0;
}