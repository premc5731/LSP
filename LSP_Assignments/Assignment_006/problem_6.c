// 6. Write a program to demonstrate dynamic library search path resolution in Linux.
// • Place a shared library in a custom directory.
// • Write a client program that loads the library without specifying full path.
// • Execute the program with and without setting LD_LIBRARY_PATH.
// Explain the output in both cases.



#include<stdio.h>
#include<unistd.h>
#include<dlfcn.h>

int main()
{
    int iRet = 0;
    void * handle = NULL;
    char * error = NULL;
    int (*fp) (int, int) = NULL;

    handle = dlopen("mathlib6.so",RTLD_LAZY);

    if(handle == NULL)
    {
        error = dlerror();
        printf("Error : %s\n",error);
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

    fp = (int (*) (int, int))dlsym(handle, "Substraction");
    if(fp == NULL)
    {
        error = dlerror();
        printf("Error : %s\n",error);
        return -1;
    }

    iRet = fp(10, 20);
    printf("Substraction is : %d\n",iRet);

    dlclose(handle);
}


/*

output : 
"with LD_LIBRARY_PATH"
prem:Assignment_006$ gcc problem_6.c -L. -o myexe
prem:Assignment_006$ LD_LIBRARY_PATH=./test_prob_6 ./myexe 
Addition is : 120
Substraction is : -10

"without LD_LIBRARY_PATH"
prem:Assignment_006$ gcc problem_6.c -L. -o myexe
prem:Assignment_006$ ./myexe 
Error : mathlib6.so: cannot open shared object file: No such file or directory

*/
