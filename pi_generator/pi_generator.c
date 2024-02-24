double pi_generator(int precision)
{
    double pi = 1;
    if (precision <= 0)
    {
        return 2;
    }
    for (double i = precision; i > 0; i--)
    {
        pi = 1 + (i / (i * 2 + 1)) * pi;
    }
    return pi * 2;
}
