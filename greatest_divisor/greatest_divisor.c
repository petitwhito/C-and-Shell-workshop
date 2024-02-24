unsigned int greatest_divisor(unsigned int n)
{
    unsigned int gr = 1;
    for (unsigned int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            gr = i;
        }
    }
    return gr;
}
