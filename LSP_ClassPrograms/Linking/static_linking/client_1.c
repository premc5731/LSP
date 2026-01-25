#include<stdio.h>
#include<stdlib.h>

int Addition(int, int);
int Substraction(int, int);

int main()
{

    int iRet = 0;

    iRet = Addition(11, 10);
    printf("Addition is : %d\n",iRet);

    iRet = Substraction(11, 10);
    printf("Addition is : %d\n",iRet);

    return 0;
}

//ar rcs libserver_1.a server_1.o 

// r - repace
// c - create
// s - symbol index
// ar - archieve utility

