#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *a = list->head;
    while (a)
    {
        a->data = a->data * a->data;
        a = a->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *a = list->head;
    while (a)
    {
        struct dlist_item *temp = a->next;
        struct dlist_item *temp2 = a->next;
        a->next = a->prev;
        a->prev = temp2;
        a = temp;
    }

    struct dlist_item *temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index > list->size)
    {
        return NULL;
    }
    if (list->size == 0)
    {
        return dlist_init();
    }
    struct dlist *other_half = dlist_init();

    if (index == 0)
    {
        other_half->head = list->head;
        other_half->tail = list->tail;
        list->head = NULL;
        list->tail = NULL;
        other_half->size = list->size;
        list->size = 0;
        return other_half;
    }

    struct dlist_item *a = list->head;
    size_t count = 0;
    while (a && count != index)
    {
        a = a->next;
        count++;
    }
    if (count != index)
        return NULL;

    other_half->tail = list->tail;
    list->tail = a->prev;
    other_half->head = a;
    a->prev->next = NULL;
    a->prev = NULL;
    other_half->size = list->size - index;
    list->size = index;
    return other_half;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list2->size == 0)
    {
        return;
    }
    if (list1->size == 0)
    {
        list1->size = list2->size;
        list1->head = list2->head;
        list1->tail = list2->tail;
        return;
    }
    list1->tail->next = list2->head;
    list1->tail->next->prev = list1->tail;
    list1->tail = list2->tail;
    list1->size = list1->size + list2->size;

    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}
