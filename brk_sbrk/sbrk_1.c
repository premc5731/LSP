#include<stdio.h>
#include<unistd.h>

int main()
{
    void *ptr = NULL;

    ptr = sbrk(0);
    printf("Current break value: %p\n",ptr);    // data section ends here

    // *(char *)ptr = 'A'; it is illegal because u are accessing the un allocated space above the data section

    return 0;
}