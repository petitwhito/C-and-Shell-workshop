#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *fifo_res = malloc(sizeof(struct fifo));
    if (!fifo_res)
    {
        return NULL;
    }
    fifo_res->head = NULL;
    fifo_res->tail = NULL;
    fifo_res->size = 0;
    return fifo_res;
}

void fifo_clear(struct fifo *fifo)
{
    struct list *temp = fifo->head;
    struct list *temp2 = fifo->head;
    while (temp)
    {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}
