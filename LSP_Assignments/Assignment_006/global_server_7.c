int GValue = 0;

int Display()
{
    return GValue;
}

int Modify(int iNo)
{
    GValue = iNo;
    return 0;
}

int Reset()
{
    GValue = 0;
    return 0;
}