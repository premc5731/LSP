// 5. Write a program in C to create two shared libraries:
// 1. libmystring.so implementing major string.h functions
// 2. libmymath.so implementing major math.h functions
// Suggested Functions
// string.h set (implement at least 8)
// • MyStrlen
// • MyStrcpy
// • MyStrncpy
// • MyStrcat
// • MyStrcmp
// • MyStrncmp
// • MyStrrev
// • MyStrchr / MyStrstr
// math.h set (implement at least 8)
// • MyPow
// • MySqrt (approx OK)
// • MyAbs
// • MyMax
// • MyMin
// • MyFactorial
// • MyGCD
// • MyLCM
// Requirements
// 1. Client should call all functions and display output.
// 2. Provide menu-driven client.
// 3. No usage of original library functions internally (implement your own logic).
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *strlib = NULL, *mathlib = NULL;

    int   (*StrlenX)(char*) = NULL;
    char* (*StrcpyX)(char*, const char*) = NULL;
    char* (*Strncpy)(char*, const char*, int) = NULL;
    char* (*StrcatX)(char*, const char*) = NULL;
    int   (*StrcmpX)(const char*, const char*) = NULL;
    int   (*StrncmpX)(const char*, const char*, int) = NULL;
    char* (*StrrevX)(char*) = NULL;
    char* (*StrchrX)(const char*, int) = NULL;
    char* (*StrstrX)(const char*, const char*) = NULL;

    double (*PowX)(double, int) = NULL;
    double (*SqrtX)(double) = NULL;
    int    (*AbsX)(int) = NULL;
    int    (*MaxX)(int, int) = NULL;
    int    (*MinX)(int, int) = NULL;
    unsigned long (*FactorialX)(int) = NULL;
    int    (*GCDX)(int, int) = NULL;
    int    (*MyLCM)(int, int) = NULL;

    int choice;
    char str1[100], str2[100];
    char ch;
    int n, a, b;
    double x, base;
    int exp;

    strlib = dlopen("./libstringX.so", RTLD_LAZY);
    if(!strlib) { printf("Error loading libStringX.so: %s\n", dlerror()); return -1; }

    mathlib = dlopen("./libmathlibX.so", RTLD_LAZY);
    if(!mathlib) { printf("Error loading libMathLib.so: %s\n", dlerror()); dlclose(strlib); return -1; }

    StrlenX  = dlsym(strlib, "StrlenX");
    StrcpyX  = dlsym(strlib, "StrcpyX");
    Strncpy  = dlsym(strlib, "Strncpy");
    StrcatX  = dlsym(strlib, "StrcatX");
    StrcmpX  = dlsym(strlib, "StrcmpX");
    StrncmpX = dlsym(strlib, "StrncmpX");
    StrrevX  = dlsym(strlib, "StrrevX");
    StrchrX  = dlsym(strlib, "StrchrX");
    StrstrX  = dlsym(strlib, "StrstrX");

    PowX       = dlsym(mathlib, "PowX");
    SqrtX      = dlsym(mathlib, "SqrtX");
    AbsX       = dlsym(mathlib, "AbsX");
    MaxX       = dlsym(mathlib, "MaxX");
    MinX       = dlsym(mathlib, "MinX");
    FactorialX = dlsym(mathlib, "FactorialX");
    GCDX       = dlsym(mathlib, "GCDX");
    MyLCM      = dlsym(mathlib, "MyLCM");

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. StrlenX\n2. StrcpyX\n3. Strncpy\n4. StrcatX\n5. StrcmpX\n6. StrncmpX\n7. StrrevX\n8. StrchrX\n9. StrstrX\n");
        printf("10. PowX\n11. SqrtX\n12. AbsX\n13. MaxX\n14. MinX\n15. FactorialX\n16. GCDX\n17. MyLCM\n18. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter string: ");
                scanf(" %[^\n]", str1);
                printf("Length: %d\n", StrlenX(str1));
                break;

            case 2:
                printf("Enter source string: ");
                scanf(" %[^\n]", str2);
                StrcpyX(str1, str2);
                printf("Copied string: %s\n", str1);
                break;

            case 3:
                printf("Enter source string: ");
                scanf(" %[^\n]", str2);
                printf("Enter number of chars to copy: ");
                scanf("%d", &n);
                Strncpy(str1, str2, n);
                printf("Result: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                scanf(" %[^\n]", str1);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                StrcatX(str1, str2);
                printf("Result: %s\n", str1);
                break;

            case 5:
                printf("Enter first string: ");
                scanf(" %[^\n]", str1);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                printf("Result: %d\n", StrcmpX(str1, str2));
                break;

            case 6:
                printf("Enter first string: ");
                scanf(" %[^\n]", str1);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                printf("Number of chars to compare: ");
                scanf("%d", &n);
                printf("Result: %d\n", StrncmpX(str1, str2, n));
                break;

            case 7:
                printf("Enter string: ");
                scanf(" %[^\n]", str1);
                StrrevX(str1);
                printf("Reversed: %s\n", str1);
                break;

            case 8:
                printf("Enter string: ");
                scanf(" %[^\n]", str1);
                printf("Enter character to search: ");
                scanf(" %c", &ch);
                {
                    char *res = StrchrX(str1, ch);
                    if(res) printf("Character found at position: %ld\n", res - str1);
                    else printf("Character not found\n");
                }
                break;

            case 9:
                printf("Enter haystack: ");
                scanf(" %[^\n]", str1);
                printf("Enter needle: ");
                scanf(" %[^\n]", str2);
                {
                    char *res = StrstrX(str1, str2);
                    if(res) printf("Substring found at position: %ld\n", res - str1);
                    else printf("Substring not found\n");
                }
                break;

            case 10:
                printf("Enter base and exponent: ");
                scanf("%lf %d", &base, &exp);
                printf("Result: %lf\n", PowX(base, exp));
                break;

            case 11:
                printf("Enter number: ");
                scanf("%lf", &x);
                printf("Result: %lf\n", SqrtX(x));
                break;

            case 12:
                printf("Enter number: ");
                scanf("%d", &a);
                printf("Result: %d\n", AbsX(a));
                break;

            case 13:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Maximum: %d\n", MaxX(a, b));
                break;

            case 14:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Minimum: %d\n", MinX(a, b));
                break;

            case 15:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Factorial: %lu\n", FactorialX(n));
                break;

            case 16:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD: %d\n", GCDX(a, b));
                break;

            case 17:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("LCM: %d\n", MyLCM(a, b));
                break;

            case 18:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 18);

    dlclose(strlib);
    dlclose(mathlib);

    return 0;
}
