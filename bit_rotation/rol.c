#include <stdio.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    for (unsigned char i = 0; i < roll; i++)
    {
        value = (value << 1) | (value >> 7);
    }
    return value;
}
