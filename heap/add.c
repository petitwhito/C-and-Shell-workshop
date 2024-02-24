#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void reorganize(struct heap *heap, int i)
{
    int parent = (i - 1) / 2;

    if (i > 0)
    {
        if (heap->array[i] > heap->array[parent])
        {
            int temp = heap->array[i];
            heap->array[i] = heap->array[parent];
            heap->array[parent] = temp;

            reorganize(heap, parent);
        }
    }
}

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
    }
    heap->array[heap->size] = val;
    reorganize(heap, heap->size);
    heap->size++;
}
