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

char *StrcpyX(char *dest, const char *src)
{
    int i = 0;

    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}

char *Strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }

    return dest;
}


char *StrcatX(char *dest, const char *src)
{
    int i = 0, j = 0;

    while(dest[i] != '\0')
    {
        i++;
    }

    while(src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    return dest;
}

int StrcmpX(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
        {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }

        i++;
    }

    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int StrncmpX(const char *s1, const char *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        i++;
    }

    if (i == n) return 0;  

    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

char *StrrevX(char *str)
{
    int i = 0, j = 0; 
    char c = '\0';
    
    while(str[j] != 0)
    {
        j++;
    }
    j = j -1;

    while(i < j)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }

    return str;
}

char *StrchrX(const char *str, int ch)
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] == ch)
        {
            return &str[i];
        }
        i++;
    }

    return NULL;
}

char *StrstrX(const char *haystack, const char *needle)
{
    if (needle[0] == '\0') // empty needle
        return (char *)haystack;

    for (int i = 0; haystack[i] != '\0'; i++)
    {
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j])
        {
            j++;
        }

        if (needle[j] == '\0') 
            return (char *)&haystack[i];
    }

    return NULL; 
}