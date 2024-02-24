#include "simple_fnmatch.h"

#include <stddef.h>

int simple_fnmatch(const char *pattern, const char *string)
{
    int p = 0;
    int s = 0;
    int p_tmp = -1;
    int s_tmp = -1;

    while (string[s] != '\0')
    {
        if (pattern[p] == '\\')
        {
            p++;
            if (pattern[p] != string[s])
            {
                return FNM_NOMATCH;
            }
            p++;
            s++;
        }

        else if (pattern[p] == '?')
        {
            p++;
            s++;
        }
        else if (pattern[p] == '*')
        {
            p_tmp = p++;
            s_tmp = s;
        }
        else if (pattern[p] == string[s])
        {
            p++;
            s++;
        }
        else if (p_tmp != -1)
        {
            p = p_tmp + 1;
            s = ++s_tmp;
        }
        else
            return FNM_NOMATCH;
    }

    while (pattern[p] == '*')
        p++;

    return (pattern[p] == '\0') ? 0 : FNM_NOMATCH;
}
