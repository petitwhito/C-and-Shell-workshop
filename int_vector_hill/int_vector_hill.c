#include "int_vector_hill.h"

#include <stddef.h>

int int_vector_hill(struct int_vector vec)
{
    size_t len = vec.size;
    if (len == 0)
    {
        return -1;
    }

    int peak = vec.data[0];
    int res = 0;
    int down = 0;
    for (size_t i = 1; i < len; i++)
    {
        if (vec.data[i] < 0)
        {
            return -1;
        }
        if (peak > vec.data[i] && !down)
        {
            down = 1;
        }
        else if (vec.data[i] > peak && down)
        {
            return -1;
        }
        if (peak != vec.data[i] && !down)
        {
            res = i;
        }
        peak = vec.data[i];
    }
    return res;
}
