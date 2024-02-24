#include "my_memset.h"

#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    char *temp = s;
    for (size_t i = 0; i < n; i++)
    {
        temp[i] = c;
    }
    return s;
}
