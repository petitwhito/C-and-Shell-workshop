#include <stdio.h>

int main(void)
{
    for (char i = 'a'; i <= 'z'; i++)
    {
        putchar(i);
        if (i == 'z')
        {
            putchar('\n');
        }
        else
        {
            putchar(' ');
        }
    }
    return 0;
}
