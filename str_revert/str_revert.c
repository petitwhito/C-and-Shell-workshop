#include "str_revert.h"

void str_revert(char str[])
{
    int len = 0;
    for (int i = 0; str[i]; i++)
    {
        len++;
    }
    if (len == 0)
    {
        return;
    }
    int j = len - 1;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
}
