#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void delete_heap(struct heap *heap)
{
    free(heap->array);
    heap->size = 0;
    heap->capacity = 0;
    free(heap);
}
