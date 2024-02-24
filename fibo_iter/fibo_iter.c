unsigned long fibo_iter(unsigned long n)
{
    if (n <= 1)
    {
        return n;
    }
    unsigned long a = 0;
    unsigned long b = 1;
    unsigned long tmp;
    for (unsigned long i = 1; n > i; i++)
    {
        tmp = a;
        a = b;
        b = b + tmp;
    }
    return b;
}
