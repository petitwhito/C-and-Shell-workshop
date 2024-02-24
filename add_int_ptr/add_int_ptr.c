int *add_int_ptr(int *a, int *b)
{
    if (!a || !b)
    {
        return a;
    }
    *a = *a + *b;
    return a;
}
