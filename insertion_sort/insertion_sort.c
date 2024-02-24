#include "insertion_sort.h"

#include <stddef.h>

int comp(const void *s1, const void *s2)
{
    const unsigned char *temp1 = s1;
    const unsigned char *temp2 = s2;
    while ((*temp1 == *temp2))
    {
        temp1++;
        temp2++;
    }
    return *temp1 - *temp2;
}

void insertion_sort(void **array, f_cmp comp)
{
    if (!array || !array[0])
        return;
    for (int i = 1; array[i]; i++)
    {
        int j = i;
        while (j > 0 && comp(array[j - 1], array[j]) > 0)
        {
            void *temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}
