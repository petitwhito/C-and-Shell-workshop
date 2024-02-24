#include <stddef.h>
#include <stdio.h>

void display_square(int width)
{
    if (width == 0)
        return;
    if (width == 1)
    {
        putchar('*');
        putchar('\n');
        return;
    }
    if (width % 2 == 0)
    {
        width++;
    }
    int rows = (width + 1) / 2;
    for (int i = 0; i < rows; i++)
    {
        if (i == 0 || i == rows - 1)
        {
            for (int j = 0; j < width; j++)
            {
                putchar('*');
            }
        }
        else
        {
            putchar('*');
            for (int j = 0; j < width - 2; j++)
            {
                putchar(' ');
            }
            putchar('*');
        }
        putchar('\n');
    }
}
