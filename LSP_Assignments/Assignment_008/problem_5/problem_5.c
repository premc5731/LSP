// 5. Static Library Build (.a)
// Create:
// • libmath.a containing Add, Sub, Mul, Div
// Make targets:
// • lib → builds library
// • app → links app using static library
// • clean
// Deliverable: ar rcs usage inside Makefile

#include<stdio.h>
#include "math.h"

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

    Ans = Substraction(No1, No2);
    printf("Addition is : %d\n",Ans);

    Ans = Multiplication(No1, No2);
    printf("Addition is : %d\n",Ans);

    Ans = Division(No1, No2);
    printf("Addition is : %d\n",Ans);

    
    
    return 0;
}