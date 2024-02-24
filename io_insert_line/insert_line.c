#define _POSIX_C_SOURCE 200809L

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int len(const char *buffer)
{
    int i = 0;
    for (int j = 0; buffer[j]; j++)
    {
        if (buffer[j] == '\n')
            i++;
    }
    return i;
}

int insert_line_new(FILE *openout, FILE *openin, size_t n, const char *content)
{
    int new = 0;

    size_t bufsize = 1024;
    char *buffer = NULL;
    size_t count = 0;

    int got = 0;
    while ((getline(&buffer, &bufsize, openin)) != -1)
    {
        new ++; // nouvelle ligne
        if (count == n)
        {
            fputs(content, openout);
            new += len(content); // si 0 alors 1
            got = 1;
        }
        fputs(buffer, openout);
        count++;
    }

    if (!got)
    {
        while (count < n)
        {
            fputs("\n", openout);
            count++;
            new ++;
        }
        fputs(content, openout);
        new ++;
        if (len(content) != 0 && len(content) != 1)
            new += len(content) - 1;
    }

    free(buffer);
    return new;
}

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    FILE *openin = fopen(file_in, "r");
    if (!openin)
        return -1;

    FILE *openout = fopen(file_out, "w");
    if (!openout)
        return -1;

    int res = insert_line_new(openout, openin, n, content);

    fclose(openout);
    fclose(openin);

    return res;
}
