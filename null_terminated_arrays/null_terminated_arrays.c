#include "null_terminated_arrays.h"

void reverse(const char **array)
{
    int count = 0;
    for (int i = 0; array[i]; i++)
    {
        count++;
    }

    for (int i = 0; i < count / 2; i++)
    {
        const char *temp = array[i];
        array[i] = array[count - i - 1];
        array[count - i - 1] = temp;
    }
}

void reverse_matrix(const char ***matrix)
{
    int count = 0;
    for (int i = 0; matrix[i]; i++)
    {
        reverse(matrix[i]);
        count++;
    }

    for (int i = 0; i < count / 2; i++)
    {
        const char **temp = matrix[i];
        matrix[i] = matrix[count - i - 1];
        matrix[count - i - 1] = temp;
    }
}
