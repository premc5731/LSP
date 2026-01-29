#include<stdio.h>

int StrlenX(char * str)
{
    int i = 0;
    if(str == NULL)
    {
        return 0;
    }

    while(str[i] != '\0')
    {
        i++;
    }

    return i;

}