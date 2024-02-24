#include "bubble_sort.h"

#include <stddef.h>

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

void bubble_sort(int array[], size_t size)
{
    if (!size)
    {
        return;
    }
    while (!is_sorted(array, size))
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
            }
        }
    }
}
