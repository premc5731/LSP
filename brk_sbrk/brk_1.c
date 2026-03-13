#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    void *current_break = NULL;
    int ret = 0;

    current_break = sbrk(0);
    printf("Current process break %p\n",current_break);

    //ret = brk((char *)current_break + 100);
    
    strcpy((char *)current_break, "Jay Ganesh...");
    printf("return value of brk : %d\n",ret);

    printf("Data from new memory : %s\n",(char *)current_break);

    sbrk(-100);

    return 0;
}