#include "my_strlen.h"

#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t j = 0;
    for (int i = 0; s[i]; i++)
    {
        j++;
    }
    return j;
}
