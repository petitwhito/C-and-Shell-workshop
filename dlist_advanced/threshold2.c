#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_get(const struct dlist *list, size_t index)
{
    if (index > list->size)
        return -1;
    struct dlist_item *res = list->head;
    size_t count = 0;
    while (res->next && count != index)
    {
        res = res->next;
        count++;
    }
    return res->data;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (index > list->size)
        return -1;

    if (index == list->size)
    {
        return dlist_push_back(list, element);
    }

    if (index == 0)
        return dlist_push_front(list, element);

    if (element < 0)
        return -1;
    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    if (!item)
        return -1;
    item->data = element;
    item->next = NULL;
    item->prev = NULL;

    struct dlist_item *tmp1 = list->head;
    size_t count = 0;
    while (tmp1 && count != index)
    {
        tmp1 = tmp1->next;
        count++;
    }

    if (count != index)
        return -1;

    item->next = tmp1;
    item->prev = tmp1->prev;
    item->prev->next = item;
    tmp1->prev = item;
    list->size++;
    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    struct dlist_item *a = list->head;
    int count = 0;
    while (a)
    {
        if (a->data == element)
            return count;
        a = a->next;
        count++;
    }
    return -1;
}

int rem(struct dlist_item *tmp, struct dlist *list)
{
    list->head = list->head->next;
    int keep = tmp->data;
    free(tmp);
    list->size--;
    return keep;
}

int rem2(struct dlist_item *tmp, struct dlist *list)
{
    int keep = list->tail->data;
    free(list->tail);
    list->tail = tmp;
    list->tail->next = NULL;
    list->size--;
    return keep;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (index >= list->size)
        return -1;

    if (index == 0)
    {
        struct dlist_item *tmp = list->head;
        return rem(tmp, list);
    }

    if (list->size == 1)
    {
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return 1;
    }

    if (index == list->size - 1)
    {
        struct dlist_item *tmp = list->tail->prev;
        return rem2(tmp, list);
    }

    struct dlist_item *tmp1 = list->head;
    struct dlist_item *tmp2 = list->head->next;
    size_t count = 1;
    while (tmp2->next && count != index)
    {
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
        count++;
    }

    if (count != index)
        return -1;

    tmp1->next = tmp2->next;
    tmp2->next->prev = tmp1;
    int keep = tmp2->data;
    free(tmp2);
    list->size--;
    return keep;
}

void dlist_clear(struct dlist *list)
{
    struct dlist_item *temp = list->head;
    struct dlist_item *temp2 = list->head;
    while (temp)
    {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
