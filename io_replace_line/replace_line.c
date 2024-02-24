#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    FILE *openin = fopen(file_in, "r");
    if (!openin)
        return -1;

    FILE *openout = fopen(file_out, "w");
    if (!openout)
        return -1;

    size_t bufsize = 1024;
    char *buffer = NULL;
    int count = 0;
    while ((getline(&buffer, &bufsize, openin)) != -1)
    {
        if (count == n)
            fputs(content, openout);
        else
            fputs(buffer, openout);
        count++;
    }

    free(buffer);
    fclose(openout);
    fclose(openin);

    if (count < n)
        return 1;

    return 0;
}
