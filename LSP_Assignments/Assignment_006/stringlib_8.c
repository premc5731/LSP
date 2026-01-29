int Caps(char * str)
{
    int i = 0, iCount = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            iCount++;
        }

        i++;
    }

    return iCount;
}

int Smalls(char * str)
{
    int i = 0, iCount = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            iCount++;
        }

        i++;
    }

    return iCount;
}

int Digits(char * str)
{
    int i = 0, iCount = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            iCount++;
        }
        i++;
    }

    return iCount;
}