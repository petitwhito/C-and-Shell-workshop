int my_pow(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    else if (b % 2 == 0)
    {
        return my_pow(a * a, b / 2);
    }
    return a * my_pow(a * a, (b - 1) / 2);
}
