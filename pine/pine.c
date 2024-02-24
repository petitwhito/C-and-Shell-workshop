#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
    {
        return 1;
    }

    unsigned count = 1;
    for (unsigned i = n; i > 0; i--)
    {
        for (unsigned j = 1; j < i; j++)
        {
            putchar(' ');
        }
        for (unsigned k = 0; k < count; k++)
        {
            putchar('*');
        }
        count += 2;
        putchar('\n');
    }
    for (unsigned k = 0; k < n / 2; k++)
    {
        for (unsigned i = 1; i < n; i++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    return 0;
}
