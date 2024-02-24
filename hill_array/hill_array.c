#include "hill_array.h"

#include <stdio.h>

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0)
    {
        return -1;
    }

    int peak = tab[0];
    int res = 0;
    int down = 0;
    for (size_t i = 1; i < len; i++)
    {
        if (tab[i] < 0)
        {
            return -1;
        }
        if (peak > tab[i] && !down)
        {
            down = 1;
        }
        else if (tab[i] > peak && down)
        {
            return -1;
        }
        if (peak != tab[i] && !down)
        {
            res = i;
        }
        peak = tab[i];
    }
    return res;
}
