// 3. Write a program in C to create a shared library libdisplay.so which contains:
// • void Display(char *str);
// Requirements
// 1. Client accepts a string from user.
// 2. Client calls Display() from shared library.
// 3. Library must display:
// ◦ The string
// ◦ Total characters (optional)

#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void * handle = NULL;
    void (*fp)(char*) = NULL;
    char Buffer[100] = {'\0'};

    printf("Enter a string : \n");
    scanf("%[^\n]s",Buffer);

    handle = dlopen("./libdisplay.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : unable to open libdisplay.so\n");
        return -1;
    }

    fp = (void(*)(char *))dlsym(handle, "Display");
    if(fp == NULL)
    {
        printf("Error : unable to load function dlsym()\n");
        return -1;
    }

    fp(Buffer);

    dlclose(handle);
}