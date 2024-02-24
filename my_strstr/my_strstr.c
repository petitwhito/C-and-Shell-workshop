#include "my_strstr.h"

int my_strstr(const char *haystack, const char *needle)
{
    if (!needle || needle[0] == '\0')
        return 0;

    int index = 0;
    for (int i = 0; haystack[i]; i++)
    {
        if (haystack[i] == needle[0])
        {
            index = i;
            for (int j = 0; needle[j] && haystack[j + i]; j++)
            {
                if (!needle[j + 1])
                    return index;

                if (needle[j] != haystack[j + i])
                    break;
            }
        }
    }
    return -1;
}
