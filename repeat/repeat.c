#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return 1;
    }
    int n = argv[2][0] - '0';
    for (int i = 0; i < n; i++)
    {
        puts(argv[1]);
    }
    return 0;
}
