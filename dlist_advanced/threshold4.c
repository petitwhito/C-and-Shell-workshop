#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_shift(struct dlist *list, int offset)
{
    if (!list || !list->head || !list->tail)
        return;
    while (offset < 0)
    {
        list->head->prev = list->tail;
        list->tail->next = list->head;

        list->head = list->head->next;
        list->tail = list->tail->next;

        list->head->prev = NULL;
        list->tail->next = NULL;

        offset++;
    }
    while (offset > 0)
    {
        list->head->prev = list->tail;
        list->tail->next = list->head;

        list->head = list->head->prev;
        list->tail = list->tail->prev;

        list->head->prev = NULL;
        list->tail->next = NULL;

        offset--;
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (!list)
    {
        return -1;
    }
    struct dlist_item *res = list->head;
    size_t count = 0;
    while (res && res->data < element)
    {
        res = res->next;
        count++;
    }
    return dlist_insert_at(list, element, count);
}

int dlist_remove_eq(struct dlist *list, int element)
{
    if (!list || !list->head)
        return 0;
    struct dlist_item *res = list->head;
    size_t count = 0;
    while (res && res->data != element)
    {
        res = res->next;
        count++;
    }
    if (!res)
        return 0;
    if (res->data != element)
        return 0;

    int a = dlist_remove_at(list, count);
    if (a != 0)
        return 1;
    return 0;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    struct dlist *res = dlist_init();
    if (!res)
        return NULL;
    struct dlist_item *temp = list->head;
    while (temp)
    {
        dlist_push_back(res, temp->data);
        temp = temp->next;
    }
    return res;
}
