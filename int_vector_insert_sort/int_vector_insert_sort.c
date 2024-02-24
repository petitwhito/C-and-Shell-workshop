#include "int_vector_insert_sort.h"

#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int temp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = temp;
    return vec;
}

int is_sorted(int array[], size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    while (!is_sorted(vec.data, vec.size))
    {
        for (size_t i = 0; i < vec.size - 1; i++)
        {
            if (vec.data[i] > vec.data[i + 1])
            {
                vec = swap(vec, i, i + 1);
            }
        }
    }
    return vec;
}
