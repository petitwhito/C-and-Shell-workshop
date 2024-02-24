#include "my_itoa_base.h"

char *throw(char *s, const char *base)
{
    s[0] = base[0];
    s[1] = '\0';
    return s;
}

int lenbase(const char *base)
{
    int count = 0;
    for (int i = 0; base[count]; i++)
    {
        count++;
    }
    return count;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    if (n == 0)
    {
        return throw(s, base);
    }
    int i = 0;
    int sign = 0;
    if (n < 0)
    {
        s[0] = '-';
        i++;
        sign = 1;
        n = -n;
    }
    int lbase = lenbase(base);
    while (n != 0)
    {
        int r = n % lbase;
        s[i] = base[r];
        i++;
        n = n / lbase;
    }

    int j = i - 1;
    if (sign)
    {
        for (int k = 1; k <= i / 2; k++)
        {
            char temp = s[k];
            s[k] = s[j];
            s[j] = temp;
            j--;
        }
    }
    else
    {
        for (int k = 0; k < i / 2; k++)
        {
            char temp = s[k];
            s[k] = s[j];
            s[j] = temp;
            j--;
        }
    }
    s[i] = '\0';
    return s;
}
