#include<stdio.h>

int Addition(int No1, int No2)
{
    int Ans = 0;
    Ans = No1 + No2;

    return Ans;
}

int main()
{
    int Ret = 0, a = 0, b = 0;

    printf("Enter first number\n");
    scanf("%d",&a);

    printf("Enter second number\n");
    scanf("%d",&b);

    Ret = Addition(a, b);

    printf("Addition is : %d\n",Ret);

    return 0;
}
