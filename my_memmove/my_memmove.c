#include "my_memmove.h"

#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    const unsigned char *copy_source = src;
    unsigned char *copy_dest = dest;
    unsigned char tmp;
    if (*copy_dest <= *copy_source)
    {
        for (size_t i = 0; i < n; i++)
        {
            tmp = copy_source[i];
            copy_dest[i] = tmp;
        }
    }
    else
    {
        for (size_t i = n; i >= 1; i--)
        {
            tmp = copy_source[i - 1];
            copy_dest[i - 1] = tmp;
        }
    }

    return copy_dest;
}
