#include <stdio.h>

int main(void)
{
    char c = 'A';
    c += 32;

    if (c >= 97 && c <= 122)
        puts("'c' has become a lowercase character!");

    return 0;
}
