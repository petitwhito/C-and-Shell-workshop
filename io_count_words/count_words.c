#include <stddef.h>
#include <stdio.h>

int count_words(const char *file_in)
{
    FILE *open = fopen(file_in, "r");
    if (!open)
        return -1;
    char c;
    int count = 0;
    int previous = 1;
    while ((c = fgetc(open)) != EOF)
    {
        if ((c == '\t' || c == ' ' || c == '\n') && !previous)
        {
            count++;
            previous = 1;
        }
        if (c != '\t' && c != ' ' && c != '\n')
        {
            previous = 0;
        }
    }
    if (!previous)
        count++;
    fclose(open);
    return count;
}
