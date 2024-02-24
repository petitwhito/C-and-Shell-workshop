#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void double_capacity(struct vector *v)
{
    v->capacity *= 2;
    v->data = realloc(v->data, v->capacity * sizeof(int));
}

struct vector *vector_init(size_t n)
{
    struct vector *vector;
    vector = malloc(sizeof(struct vector));
    if (vector == NULL)
    {
        return NULL;
    }
    vector->capacity = n;
    vector->size = 0;
    vector->data = malloc(vector->capacity * sizeof(int));
    if (!vector->data)
    {
        return NULL;
    }
    return vector;
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (n == v->capacity)
        return v;
    if (n < v->size)
    {
        v->size = n;
    }
    v->data = realloc(v->data, n * sizeof(int));
    v->capacity = n;
    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;
    if (v->size == v->capacity)
    {
        double_capacity(v);
    }
    v->data[v->size] = elt;
    v->size++;
    return v;
}

void vector_print(const struct vector *v)
{
    for (size_t i = 0; i < v->size; i++)
    {
        if (i + 1 == v->size)
            printf("%d", v->data[i]);
        else
            printf("%d,", v->data[i]);
    }
    printf("\n");
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v || !v->data || v->size < i)
        return NULL;
    if (v->size == v->capacity)
        double_capacity(v);
    if (i <= v->size)
    {
        v->size++;
        for (size_t j = v->size - 1; j > i; j--)
            v->data[j] = v->data[j - 1];
        v->data[i] = elt;
    }
    return v;
}
