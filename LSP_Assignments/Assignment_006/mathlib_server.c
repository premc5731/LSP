#include<stdio.h>

int Addition(int A, int B)
{
    int Ans = 0;

    Ans = A + B;

    return Ans;
}

int Substraction(int A, int B)
{
    int Ans = 0;

    Ans = A - B;

    return Ans;
}

int Multiplication(int A, int B)
{
    int Ans = 0;

    Ans = A * B;

    return Ans;
}

int Division(int A, int B)
{
    if(B == 0)
    {
        printf("Error : Denominator is zero \n");
        return -1;
    }
    int Ans = 0;

    Ans = A / B;

    return Ans;
}