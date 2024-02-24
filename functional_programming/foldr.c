#include <stdio.h>

#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int res = 0;
    for (size_t n = len - 1; 1; n--)
    {
        res = func(array[n], res);
        if (n == 0)
            break;
    }
    return res;
}
