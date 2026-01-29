int SumOfFactors(int No)
{
    int iSum = 0, i = 0;

    for(i = 1; i <= (No)/2; i++)
    {
        if((No % i) == 0)
        {
            iSum = iSum + i;
        }
    }

    return iSum;
}