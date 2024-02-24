#include "complex.h"

#include <stddef.h>
#include <stdio.h>

void print_complex(struct complex a)
{
    if (a.img < 0)
    {
        float i = -a.img;
        printf("complex(%.2f - %.2fi)\n", a.real, i);
    }
    else
    {
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
    }
}

struct complex neg_complex(struct complex a)
{
    struct complex z;
    z.img = -a.img;
    z.real = -a.real;
    return z;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex z;
    z.img = a.img + b.img;
    z.real = a.real + b.real;
    return z;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex z;
    float a1 = a.real;
    float b1 = a.img;
    float c = b.real;
    float d = b.img;

    z.real = a1 - c;
    z.img = b1 - d;
    return z;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex z;
    z.real = a.real * b.real - a.img * b.img;
    z.img = a.real * b.img + b.real * a.img;
    return z;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex z;
    float a1 = a.real;
    float b1 = a.img;
    float c = b.real;
    float d = b.img;

    z.real = (a1 * c + b1 * d) / ((c * c) + (d * d));
    z.img = (b1 * c - a1 * d) / ((c * c) + (d * d));
    return z;
}
