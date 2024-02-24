#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;
    int *arr = calloc(n + 1, sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
            count++;
    }

    free(arr);
    printf("%d\n", count);
}
