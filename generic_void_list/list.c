#include "list.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *head = malloc(sizeof(struct list));
    if (!head)
        return NULL;
    head->data = malloc(sizeof(const void *));
    memcpy(head->data, value, data_size);
    head->next = list;
    list = head;
    return list;
}

size_t list_length(struct list *list)
{
    size_t res = 0;
    struct list *temp = list;
    while (temp != NULL)
    {
        res++;
        temp = temp->next;
    }
    return res;
}

void list_destroy(struct list *list)
{
    struct list *current = list;
    struct list *next;
    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}
