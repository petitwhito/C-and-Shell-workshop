int int_sqrt(int n)
{
    if (n < 0)
    {
        return -1;
    }
    int i = 1;
    while (i * i <= n)
    {
        i++;
    }
    return i - 1;
}
