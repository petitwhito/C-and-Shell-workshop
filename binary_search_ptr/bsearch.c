#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    if (begin == end)
    {
        return begin;
    }
    end--;

    while (end >= begin)
    {
        int *middle = begin + (end - begin) / 2;
        if (*middle > elt)
        {
            end = middle - 1;
        }
        else if (*middle < elt)
        {
            begin = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return begin;
}
