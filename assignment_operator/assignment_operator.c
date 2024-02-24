void plus_equal(int *a, int *b)
{
    if (a && b)
    {
        *a = *a + *b;
    }
}

void minus_equal(int *a, int *b)
{
    if (a && b)
    {
        *a = *a - *b;
    }
}

void mult_equal(int *a, int *b)
{
    if (a && b)
    {
        *a = *a * *b;
    }
}

int div_equal(int *a, int *b)
{
    if (!a || !b || *b == 0)
    {
        return 0;
    }
    int rem = *a % *b;
    *a = *a / *b;
    return rem;
}
