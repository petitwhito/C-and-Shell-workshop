#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vector_destroy(struct vector *v)
{
    free(v->data);
    free(v);
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    v->data = realloc(v->data, sizeof(int));
    if (!v->data)
        return NULL;
    v->capacity = n;
    v->size = 0;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v)
        return NULL;
    if (i >= v->size)
    {
        return NULL;
    }

    for (size_t j = i; j < v->size - 1; j++)
    {
        v->data[j] = v->data[j + 1];
    }
    v->size--;
    if (v->size < v->capacity / 2)
        vector_resize(v, v->capacity / 2);

    return v;
}
