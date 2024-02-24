#include <stdio.h>

#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    int res = 0;
    for (size_t n = 0; n < len; n++)
    {
        res = func(res, array[n]);
    }
    return res;
}
