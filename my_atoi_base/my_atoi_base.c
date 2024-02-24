#include "my_atoi_base.h"

int is_digit(char c, const char *base)
{
    for (int i = 0; base[i]; i++)
    {
        if (c == base[i])
            return 1;
    }
    return 0;
}

int indice(char c, const char *base)
{
    int index = 0;
    for (int i = 0; base[i]; i++)
    {
        if (c == base[i])
            return i;
    }
    return index;
}

int base_len(const char *base)
{
    int count = 0;
    for (int i = 0; base[i]; i++)
        count++;
    return count;
}

int my_atoi_base(const char *str, const char *base)
{
    if (!str || str[0] == '\0')
    {
        return 0;
    }

    int len = 0;
    for (int i = 0; str[i]; i++)
    {
        len++;
    }

    int len2 = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
            break;
        len2++;
    }

    int sign = 1;
    if (len2 < len)
    {
        if (str[len2] == '-')
        {
            sign = 0;
            len2++;
        }
        else if (str[len2] == '+')
            len2++;
    }

    int tmp = len2;
    for (; len2 < len; len2++)
    {
        if (!is_digit(str[len2], base))
            break;
    }

    if (len2 != len)
        return 0;

    int blen = base_len(base);

    int res = 0;
    for (int i = tmp; str[i]; i++)
    {
        res = res * blen + indice(str[i], base);
    }

    if (!sign)
        return -res;
    return res;
}
