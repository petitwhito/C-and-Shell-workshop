#include "my_itoa.h"

char *throw(char *s)
{
    s[0] = '0';
    s[1] = '\0';
    return s;
}

char *my_itoa(int value, char *s)
{
    if (value == 0)
    {
        return throw(s);
    }

    int i = 0;
    int sign = 0;
    if (value < 0)
    {
        s[0] = '-';
        i++;
        sign = 1;
        value = -value;
    }
    while (value != 0)
    {
        int r = value % 10;
        s[i] = r + '0';
        i++;
        value = value / 10;
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
