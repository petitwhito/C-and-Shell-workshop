#include "my_strspn.h"

#include <stddef.h>

int test(char c, const char *accept)
{
    for (int i = 0; accept[i]; i++)
    {
        if (accept[i] == c)
        {
            return 1;
        }
    }
    return 0;
}
size_t my_strspn(const char *s, const char *accept)
{
    size_t res = 0;
    int i = 0;
    while (s[i] && test(s[i], accept))
    {
        i++;
        res++;
    }
    return res;
}
