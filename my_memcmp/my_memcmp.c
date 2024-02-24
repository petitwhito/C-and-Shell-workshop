#include "my_memcmp.h"

#include <stddef.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    if (num == 0)
        return 0;

    const unsigned char *temp1 = s1;
    const unsigned char *temp2 = s2;
    size_t i = 0;
    while ((*temp1 == *temp2) && num > i)
    {
        temp1++;
        temp2++;
        i++;
    }
    return *temp1 - *temp2;
}
