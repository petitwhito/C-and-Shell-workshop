#include "my_memcpy.h"

#include <stddef.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    const char *copy_source = source;
    char *copy_dest = dest;

    for (size_t i = 0; i < num; i++)
    {
        copy_dest[i] = copy_source[i];
    }

    return copy_dest;
}
