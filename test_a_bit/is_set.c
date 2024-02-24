#include "is_set.h"

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned short flag_set = 1 << (n - 1);
    if (value & flag_set)
        return 1;
    return 0;
}
