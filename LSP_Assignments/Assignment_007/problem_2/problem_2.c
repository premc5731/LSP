// // 2. Write a program in C to create two shared libraries:
// // • libaddition.so containing:
// // ◦ int Addition(int A, int B);
// // • libsubstraction.so containing:
// // ◦ int Substraction(int A, int B);
// // Requirements
// // 1. Create separate .so for each operation.
// // 2. Client should link both .so libraries.
// 3. Client should accept two numbers and call both functions.
// Expected Output
// • Addition: A + B
// • Substraction: A - B

#include<dlfcn.h>
#include<stdio.h>

int main()
{
    int iNo1 = 0, iNo2 = 0;
    int iRet = 0;
    void *handle = NULL;
    int (*fp)(int, int) = NULL;

    printf("Enter first number : \n");
    scanf("%d",&iNo1);

    printf("Enter second number : \n");
    scanf("%d",&iNo2);

    handle = dlopen("./libaddition.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open libaddition.so\n");
        return -1;
    }

    fp = (int(*)(int, int))dlsym(handle, "Addition");
    if(fp == NULL)
    {
        printf("Error : unable to load function dlsym()\n");
        return -1;
    }

    iRet = fp(iNo1, iNo2);

    printf("Addition is : %d\n",iRet);

    handle = dlopen("./libsubstraction.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open libsubstraction.so\n");
        return -1;
    }

    fp = (int(*)(int, int))dlsym(handle, "Substraction");
    if(fp == NULL)
    {
        printf("Error : unable to load function dlsym()\n");
        return -1;
    }

    iRet = fp(iNo1, iNo2);

    printf("Substraction is : %d\n",iRet);

    dlclose(handle);

    return 0;
}
