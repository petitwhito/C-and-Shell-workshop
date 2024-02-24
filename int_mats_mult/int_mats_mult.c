#include "int_mats_mult.h"

#include <stddef.h>

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    size_t size1 = matrices_size[0];
    size_t size2 = matrices_size[1];
    size_t size3 = matrices_size[2];

    for (size_t i = 0; i < size1; i++)
        for (size_t j = 0; j < size3; j++)
            for (size_t k = 0; k < size2; k++)
                out[i][j] += mat1[i][k] * mat2[k][j];
}
