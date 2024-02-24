#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void print(const struct heap *heap, size_t i)
{
    if (i > heap->size)
    {
        return;
    }
    printf("%d", heap->array[i]);

    size_t left = (2 * i) + 1;
    size_t right = (2 * i) + 2;
    if (left < heap->size)
    {
        printf(" ");
        print(heap, left);
    }
    if (right < heap->size)
    {
        printf(" ");
        print(heap, right);
    }
}

void print_heap(const struct heap *heap)
{
    print(heap, 0);
    printf("\n");
}
