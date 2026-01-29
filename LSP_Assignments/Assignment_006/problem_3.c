// 3. Create a shared library that contains arithmetic functions:
// • Addition
// • Substraction
// • Multiplication
// • Division
// Write a client program that dynamically loads the library and calls the required function based on user choice.


#include<stdio.h>
#include<unistd.h>
#include<dlfcn.h>

int main()
{
    int iRet = 0, Choice = 0, num1 = 0, num2 = 0;;
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

    printf("Please choose the below option\n");
    printf("Addition => [1]\n");
    printf("Substraction => [2]\n");
    printf("Multiplication => [3]\n");
    printf("Division => [4]\n");

    scanf("%d",&Choice);

    printf("Enter the first number : \n");
    scanf("%d",&num1);

    printf("Enter the second number : \n");
    scanf("%d",&num2);

    
    switch(Choice)
    {
        case 1:
        fp = (int (*) (int, int))dlsym(handle, "Addition");
        if(fp == NULL)
        {
            error = dlerror();
            printf("Error : %s\n",error);
            return -1;
        }

        iRet = fp(num1, num2);
        printf("Addition is : %d\n",iRet);
        break;

        case 2:
        fp = (int (*) (int, int))dlsym(handle, "Substraction");
        if(fp == NULL)
        {
            error = dlerror();
            printf("Error : %s\n",error);
            return -1;
        }

        iRet = fp(num1, num2);
        printf("Substraction is : %d\n",iRet);
        break;

        case 3:
        fp = (int (*) (int, int))dlsym(handle, "Multiplication");
        if(fp == NULL)
        {
            error = dlerror();
            printf("Error : %s\n",error);
            return -1;
        }

        iRet = fp(num1, num2);
        printf("Multiplication is : %d\n",iRet);
        break;

        case 4:
        fp = (int (*) (int, int))dlsym(handle, "Division");
        if(fp == NULL)
        {
            error = dlerror();
            printf("Error : %s\n",error);
            return -1;
        }

        iRet = fp(num1, num2);
        printf("Division is : %d\n",iRet);
        break;


        default:
            break;

    }   

    dlclose(handle);
}
