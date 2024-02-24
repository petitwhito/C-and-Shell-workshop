#include "check_alphabet.h"

int check_alphabet(const char *str, const char *alphabet)
{
    if (!alphabet || alphabet[0] == '\0')
    {
        return 1;
    }
    if (str[0] == '\0')
    {
        return 0;
    }
    for (int i = 0; alphabet[i]; i++)
    {
        for (int j = 0; str[j]; j++)
        {
            if (str[j] == alphabet[i])
            {
                break;
            }

            if (str[j + 1] == '\0')
            {
                return 0;
            }
        }
    }
    return 1;
}
