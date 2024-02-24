#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    if (!list)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
        return 0;
    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    if (!item)
        return 0;
    item->data = element;
    item->next = NULL;
    item->prev = NULL;

    if (!list->head && !list->tail)
    {
        list->head = item;
        list->tail = item;
        list->size++;
        return 1;
    }

    if (list->size == 1)
    {
        item->next = list->head;
        list->head = item;
        list->tail->prev = item;
        list->size++;
        return 1;
    }
    list->head->prev = item;
    item->next = list->head;
    list->head = item;
    list->size++;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    struct dlist_item *check = list->head;
    while (check)
    {
        printf("%d\n", check->data);
        check = check->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
        return 0;
    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    if (!item)
        return 0;
    item->data = element;
    item->next = NULL;
    item->prev = NULL;

    if (!list->head && !list->tail)
    {
        list->head = item;
        list->tail = item;
        list->size++;
        return 1;
    }

    if (list->size == 1)
    {
        list->head->next = item;
        list->tail = item;
        list->tail->prev = list->head;
        list->size++;
        return 1;
    }

    list->tail->next = item;
    item->prev = list->tail;
    list->tail = item;
    list->tail->next = NULL;
    list->size++;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

int main(void)
{
    struct dlist *a = dlist_init();
    dlist_push_front(a, 5);
    dlist_push_front(a, 4);
    dlist_push_front(a, 3);
    dlist_push_front(a, 2);
    dlist_push_front(a, 1);
    dlist_print(a);

    puts("Shift 1");

    dlist_shift(a, 1);
    dlist_print(a);

    dlist_shift(a, -1);
    dlist_print(a);
}
