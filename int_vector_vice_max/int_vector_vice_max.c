#include "int_vector_vice_max.h"

#include <stddef.h>

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int second = vec.data[0];
    if (vec.data[0] > vec.data[1])
    {
        max = vec.data[0];
        second = vec.data[1];
    }
    else
    {
        max = vec.data[1];
        second = vec.data[0];
    }

    size_t size = vec.size;
    for (size_t i = 2; i < size; i++)
    {
        if (vec.data[i] > max)
        {
            second = max;
            max = vec.data[i];
        }
        else if (vec.data[i] > second)
        {
            second = vec.data[i];
        }
    }
    return second;
}
