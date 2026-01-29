// 1. Write a program in C to create two shared libraries:
// • Library 1: libperfect.so
// Contains function:
// ◦ int IsPerfect(int No);
// • Library 2: libhelper.so
// Contains helper function(s) used by IsPerfect():
// ◦ int SumOfFactors(int No); (or)
// ◦ int IsFactor(int No, int i); (any helper logic)
// Requirements
// 1. libperfect.so must internally call helper function(s) from libhelper.so.
// 2. Client application should call only IsPerfect() from libperfect.so.
// 3. Demonstrate linking chain:
// Client → libperfect.so → libhelper.so
// Expected Output
// • Input: 28 → “28 is a Perfect Number”
// • Input: 12 → “12 is NOT a Perfect Number”
// Deliverables
// • helper.c, helper.h → libhelper.so
// • perfect.c, perfect.h → libperfect.so (linked with libhelper)
// • client.c

#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void * handle = NULL;
    int iNo = 0, iRet = 0;;
    int (*fp)(int) = NULL;

    printf("Enter a number : ");
    scanf("%d",&iNo);

    handle = dlopen("./libperfect.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open liperfect.so\n");
        return -1;
    }

    fp = (int(*)(int))dlsym(handle, "IsPerfect");
    if(fp == NULL)
    {
        printf("Error : unable to load function dlsym()\n");
        return -1;
    }

    iRet = fp(iNo);

    if(iRet == 0)
    {
        printf("%d is a perfect number\n",iNo);
        return 0;
    }
    printf("%d is not a perfect number\n",iNo);

    dlclose(handle);

    return 0;
}
