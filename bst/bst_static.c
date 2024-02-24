#include "bst_static.h"

#include <stddef.h>
#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *res = malloc(sizeof(struct bst));
    if (!res)
        return NULL;
    res->capacity = capacity;
    res->size = 0;

    res->data = calloc(capacity, sizeof(struct value *));
    for (size_t i = 0; i < capacity; i++)
        res->data[i] = NULL;

    if (!res->data)
        return NULL;
    return res;
}

static void _add(struct bst *tree, int value, size_t i)
{
    if (tree->capacity <= i)
    {
        tree->data = realloc(tree->data, sizeof(struct value *) * (i + 1));
        for (size_t j = tree->capacity; j <= i; j++)
            tree->data[j] = NULL;
        tree->capacity = i + 1;
    }

    if (!tree->data[i])
    {
        struct value *a = malloc(sizeof(struct value));
        a->val = value;
        tree->data[i] = a;
        return;
    }

    if (value > tree->data[i]->val)
    {
        _add(tree, value, 2 * i + 2);
    }

    else
    {
        _add(tree, value, 2 * i + 1);
    }
}

void add(struct bst *tree, int value)
{
    if (!tree || !tree->data)
        return;

    tree->size++;
    _add(tree, value, 0);
}

static int _search(struct bst *tree, int value, int i)
{
    if (!tree->data[i])
        return -1;

    if (tree->data[i]->val == value)
    {
        return i;
    }

    if (value > tree->data[i]->val)
    {
        return _search(tree, value, 2 * i + 2);
    }

    return _search(tree, value, 2 * i + 1);
}

int search(struct bst *tree, int value)
{
    if (!tree || !tree->data)
        return -1;
    return _search(tree, value, 0);
}

void bst_free(struct bst *tree)
{
    if (!tree)
        return;

    if (tree && !tree->data)
    {
        free(tree);
        return;
    }

    for (size_t i = 0; i < tree->capacity; i++)
    {
        if (tree->data[i])
            free(tree->data[i]);
    }

    free(tree->data);
    free(tree);
}
