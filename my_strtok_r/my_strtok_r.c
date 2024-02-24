#include "my_strtok_r.h"

#include <stddef.h>

int test(char c, const char *list)
{
    for (int i = 0; list[i]; i++)
    {
        if (list[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

size_t my_strcspn(const char *s, const char *rejected)
{
    size_t res = 0;
    int i = 0;
    while (s[i] && !test(s[i], rejected))
    {
        i++;
        res++;
    }
    return res;
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

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *end;

    if (!str)
        str = *saveptr;

    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }

    str += my_strspn(str, delim);
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }

    end = str + my_strcspn(str, delim);
    if (*end == '\0')
    {
        *saveptr = end;
        return str;
    }

    *end = '\0';
    *saveptr = end + 1;
    return str;
}
