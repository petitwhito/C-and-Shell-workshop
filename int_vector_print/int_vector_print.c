#include "int_vector_print.h"

#include <stddef.h>
#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    size_t size = vec.size;
    for (size_t i = 0; i < size; i++)
    {
        if (i + 1 == size)
        {
            printf("%d\n", vec.data[i]);
        }
        else
        {
            printf("%d ", vec.data[i]);
        }
    }
}
