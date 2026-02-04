// 1. Create main.c that accepts two integers and prints addition.
// Write a Makefile with targets:
// • all (default) → builds app
// • run → runs ./app
// • clean → removes binary
// Deliverable: app, run, clean


#include<stdio.h>

int main()
{
    int No1 = 0, No2 = 0;
    int Ans = 0;

    printf("Enter first number : \n");
    scanf("%d",&No1);

    printf("Enter second number : \n");
    scanf("%d",&No2);

    Ans = No1 + No2;

    printf("Addition is : %d\n",Ans);
    
    return 0;
}