#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void heapi(struct heap *heap, size_t i)
{
    size_t left = (2 * i) + 1;
    size_t right = (2 * i) + 2;
    size_t largest = i;

    if (left < heap->size && heap->array[left] > heap->array[largest])
    {
        largest = left;
    }

    if (right < heap->size && heap->array[right] > heap->array[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = heap->array[i];
        heap->array[i] = heap->array[largest];
        heap->array[largest] = temp;

        heapi(heap, largest);
    }
}

int pop(struct heap *heap)
{
    assert(heap->size > 0);

    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size];
    heap->array[heap->size] = root;

    heap->size--;
    heapi(heap, 0);

    if (heap->size < heap->capacity / 2 && heap->capacity > 8)
    {
        heap->capacity /= 2;
        heap->array = realloc(heap->array, heap->capacity * sizeof(int));
    }

    return root;
}
