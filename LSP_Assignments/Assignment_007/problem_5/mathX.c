double PowX(double base, int exponent)
{
    double result = 1.0;
    int exp = exponent > 0 ? exponent : -exponent;

    for (int i = 0; i < exp; i++)
        result *= base;

    if (exponent < 0)
        return 1.0 / result;

    return result;
}

double SqrtX(double x)
{
    if (x == 0) 
    {
        return 0;
    }

    double i = 0.0;
    double step = 0.0001; 

    while (i * i <= x)
        i += step;

    return (i - step); 
}

int AbsX(int x)
{
    return ((x < 0) ? -x : x);
}

int MaxX(int a, int b)
{
    return (a > b) ? a : b;
}

int MinX(int a, int b)
{
    return (a < b) ? a : b;
}

unsigned long FactorialX(int n)
{
    if (n < 0) 
    {
        return 0; 
    }

    unsigned long result = 1;

    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int GCDX(int a, int b)
{
    int iRet = 0;
    
    if (b == 0) 
    {
        iRet = AbsX(a);
        return iRet;
    }
    iRet = GCDX(b, a % b);

    return iRet;
}

int MyLCM(int a, int b)
{
    int iRet = 0;
    if (a == 0 || b == 0)
    {
        return 0;
    } 
    iRet = AbsX(a * b) / GCDX(a, b);
    
    return iRet;
}