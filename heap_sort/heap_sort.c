#include "heap_sort.h"

#include <stddef.h>
#include <stdio.h>

void heaporganize(int *array, size_t size, size_t i)
{
    size_t left = (2 * i) + 1;
    size_t right = (2 * i) + 2;
    size_t largest = i;

    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heaporganize(array, size, largest);
    }
}

void heapify(int *array, size_t size)
{
    if (size == 1)
        return;
    for (size_t i = (size / 2) - 1; 1; i--)
    {
        heaporganize(array, size, i);
        if (i == 0)
        {
            break;
        }
    }
}

void heap_sort(int *array, size_t size)
{
    heapify(array, size);

    for (size_t j = size - 1; 1; j--)
    {
        int temp = array[0];
        array[0] = array[j];
        array[j] = temp;
        heaporganize(array, j, 0);
        if (j == 0)
        {
            break;
        }
    }
}
