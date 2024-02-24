#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *temp = malloc(sizeof(struct list));
    if (!temp)
    {
        return;
    }
    temp->data = elt;
    temp->next = NULL;
    if (!fifo->head && fifo->size == 0)
    {
        fifo->size++;
        fifo->head = temp;
        fifo->tail = temp;
        return;
    }
    temp->next = NULL;
    fifo->tail->next = temp;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (!fifo || !fifo->head)
    {
        return;
    }
    struct list *temp = fifo->head;
    fifo->head = temp->next;
    free(temp);
    fifo->size--;
}

void fifo_print(const struct fifo *fifo)
{
    if (!fifo || !fifo->head)
        return;

    struct list *tmp = fifo->head;
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
