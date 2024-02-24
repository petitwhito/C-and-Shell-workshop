#include "my_atoi.h"

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_atoi(const char *str)
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
        if (!is_digit(str[len2]))
            break;
    }

    if (len2 != len)
        return 0;

    int res = 0;
    for (int i = tmp; str[i]; i++)
    {
        res = res * 10 + str[i] - '0';
    }

    if (!sign)
        return -res;
    return res;
}
