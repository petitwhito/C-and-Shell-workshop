#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

struct dlist_item *dlist_get_d(const struct dlist *list, size_t index)
{
    struct dlist_item *res = list->head;
    size_t count = 0;
    while (res && count != index)
    {
        res = res->next;
        count++;
    }
    return res;
}

void dlist_sort(struct dlist *list)
{
    if (!list || !list->head)
        return;

    int swapped;
    size_t i;
    size_t j;
    for (i = 0; i < list->size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < list->size - i - 1; j++)
        {
            if (dlist_get(list, j) > dlist_get(list, j + 1))
            {
                swap(&(dlist_get_d(list, j)->data),
                     &(dlist_get_d(list, j + 1)->data));
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    dlist_concat(list1, list2);
    list2->tail = NULL;
    list2->head = NULL;
    list2->size = 0;
    dlist_sort(list1);
}
