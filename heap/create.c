#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *res = malloc(sizeof(struct heap));
    if (!res)
        return NULL;
    res->array = malloc(sizeof(int) * 8);
    if (!res->array)
        return NULL;
    res->capacity = 8;
    res->size = 0;
    return res;
}
