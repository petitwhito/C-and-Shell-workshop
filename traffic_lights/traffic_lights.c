#include "traffic_lights.h"

#include <stddef.h>

void init(unsigned char *lights)
{
    *lights = *lights & ~(*lights);
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    unsigned char check = 1 << (light_num - 1);
    *lights = *lights | check;
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    unsigned char check = ~(1 << (light_num - 1));
    *lights = *lights & check;
}

void next_step(unsigned char *lights)
{
    *lights = *lights << 1;
    *lights = *lights | (*lights >> 4);
    *lights = *lights & ~(1 << 4);
}

void reverse(unsigned char *lights)
{
    *lights = ~(*lights);
    *lights = *lights & (0x0F);
}

void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    if (*lights_1 == *lights_2)
        return;
    *lights_1 ^= *lights_2;
    *lights_2 ^= *lights_1;
    *lights_1 ^= *lights_2;
}
