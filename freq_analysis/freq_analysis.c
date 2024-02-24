#include <stdio.h>

int my_strlen(const char table[])
{
    int count = 0;
    for (int i = 0; table[i]; i++)
    {
        count++;
    }
    return count;
}

void freq_analysis(const char text[], const char table[])
{
    int hist[26] = { 0 };
    for (int i = 0; text[i]; i++)
    {
        hist[text[i] - 'A']++;
    }

    char histordre[26] = "";

    int len = my_strlen(table);

    for (int i = 0; i < len; i++)
    {
        int max = 0;
        int remove = 0;
        for (int j = 0; j < 26; j++)
        {
            if (hist[j] > max)
            {
                max = hist[j];
                remove = j;
            }
        }
        histordre[i] = remove + 'A';

        hist[remove] = 0;
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (int j = 0; histordre[j]; j++)
        {
            if (histordre[j] == i)
            {
                printf("%c %c\n", i, table[j]);
            }
        }
    }
}
