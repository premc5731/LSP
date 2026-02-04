// 4. Two Files Addition
// Create:
// • main.c (takes input, calls function)
// • helper.c (implements Add)
// • helper.h
// Makefile should generate:
// • main.o, helper.o
// • link into app
// Deliverable: correct dependency on helper.h

#include<stdio.h>
#include "helper.h"


int main()
{
    int No1 = 0, No2 = 0;
    int Ans = 0;

    printf("Enter first number : \n");
    scanf("%d",&No1);

    printf("Enter second number : \n");
    scanf("%d",&No2);

    Ans = Addition(No1, No2);

    printf("Addition is : %d\n",Ans);
    
    return 0;
}