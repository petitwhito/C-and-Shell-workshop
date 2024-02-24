#include <stdio.h>

void my_hanoi(int disks, int src, int dest, int temp)
{
    if (disks > 0)
    {
        my_hanoi(disks - 1, src, temp, dest);
        printf("%d->%d\n", src, dest);
        my_hanoi(disks - 1, temp, dest, src);
    }
}

void hanoi(unsigned n)
{
    my_hanoi(n, 1, 3, 2);
}
