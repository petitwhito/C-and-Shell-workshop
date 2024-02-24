#include "palindrome.h"

int count(const char *s)
{
    int res = 0;
    for (int i = 0; s[i]; i++)
    {
        res++;
    }
    return res;
}

int check(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

int palindrome(const char *s)
{
    if (!s)
    {
        return 0;
    }
    int n = count(s);
    if (n == 0)
    {
        return 1;
    }
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (!check(s[i]))
        {
            i++;
        }
        else if (!check(s[j]))
        {
            j--;
        }
        else if (s[i] != s[j])
        {
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }
    return 1;
}
