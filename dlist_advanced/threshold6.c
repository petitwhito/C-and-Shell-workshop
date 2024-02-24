#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

size_t check(size_t i, size_t j, const char *s1, const char *s2)
{
    return !(s1[i - 1] == s2[j - 1]);
}

unsigned int lev(size_t i, size_t j, struct dlist *list1, struct dlist *list2)
{
    if (i == 0)
    {
        return j;
    }
    if (j == 0)
    {
        return i;
    }
    size_t a = lev(i - 1, j, list1, list2) + 1;
    size_t b = lev(i, j - 1, list1, list2) + 1;
    size_t c = lev(i - 1, j - 1, list1, list2)
        + (dlist_get(list1, i - 1) != dlist_get(list2, j - 1));

    return (a < b && a < c) ? a : (b < a && b < c) ? b : c;
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    size_t i = list1->size;
    size_t j = list2->size;
    return lev(i, j, list1, list2);
}
