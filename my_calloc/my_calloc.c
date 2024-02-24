#include "my_calloc.h"

#include <stddef.h>
#include <stdlib.h>

void *my_calloc(size_t n, size_t size)
{
    void *array = malloc(size * n);

    if (!array)
    {
        return NULL;
    }

    char *arr = array;

    for (size_t i = 0; i < n * size; i++)
    {
        *(arr + i) = 0;
    }
    return arr;
}
