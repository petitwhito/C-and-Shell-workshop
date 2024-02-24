int my_round(float n)
{
    int temp = n;
    float vir = n - temp;
    if (n < 0)
    {
        if (vir <= -0.50)
        {
            temp--;
        }
        return temp;
    }
    else
    {
        if (vir >= 0.50)
        {
            temp++;
        }
        return temp;
    }
}
