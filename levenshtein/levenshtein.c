#include "levenshtein.h"

#include <stddef.h>

size_t count(const char *s)
{
    size_t count = 0;
    for (int i = 0; s[i]; i++)
    {
        count++;
    }
    return count;
}

size_t check(size_t i, size_t j, const char *s1, const char *s2)
{
    return !(s1[i - 1] == s2[j - 1]);
}

size_t lev(size_t i, size_t j, const char *s1, const char *s2)
{
    if (i == 0)
    {
        return j;
    }
    if (j == 0)
    {
        return i;
    }
    size_t a = lev(i - 1, j, s1, s2) + 1;
    size_t b = lev(i, j - 1, s1, s2) + 1;
    size_t c = lev(i - 1, j - 1, s1, s2) + check(i, j, s1, s2);

    return (a < b && a < c) ? a : (b < a && b < c) ? b : c;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t i = count(s1);
    size_t j = count(s2);
    return lev(i, j, s1, s2);
}
