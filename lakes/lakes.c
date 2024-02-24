#include "lakes.h"

void chap(char **map, int i, int j)
{
    map[i][j] = '#';
    if (map[i - 1][j] == '.')
        chap(map, i - 1, j);
    if (map[i + 1][j] == '.')
        chap(map, i + 1, j);
    if (map[i][j + 1] == '.')
        chap(map, i, j + 1);
    if (map[i][j - 1] == '.')
        chap(map, i, j - 1);
}

int lakes(char **map, int width, int height)
{
    int count = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == '.')
            {
                count++;
                chap(map, i, j);
            }
        }
    }
    return count;
}
