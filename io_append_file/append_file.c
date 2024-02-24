#include <stddef.h>
#include <stdio.h>

int append_file(const char *file_in, const char *content)
{
    if (!content || !file_in)
        return -1;
    FILE *open_filein = fopen(file_in, "a");
    if (!open_filein)
        return -1;

    fprintf(open_filein, "%s", content);
    fclose(open_filein);
    return 0;
}
