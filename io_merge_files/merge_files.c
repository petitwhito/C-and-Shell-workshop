#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int merge_files(const char *file_1, const char *file_2)
{
    FILE *open_write = fopen(file_1, "a");
    if (!open_write)
        return -1;

    FILE *open_read = fopen(file_2, "r");
    if (!open_read)
        return -1;

    char c = '\0';
    while ((c = fgetc(open_read)) != EOF)
    {
        fputc(c, open_write);
    }
    fclose(open_write);
    fclose(open_read);
    return 0;
}
