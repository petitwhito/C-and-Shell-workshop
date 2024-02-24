#include <stdio.h>

int reverse_content(const char *file_in, const char *file_out)
{
    FILE *filein = fopen(file_in, "r");
    if (!filein)
        return -1;

    FILE *fileout = fopen(file_out, "w");
    if (!fileout)
        return -1;

    int len = 0;
    char c;
    while ((c = fgetc(filein)) != EOF)
        len++;

    long pos = len - 1;
    char ch;
    while (pos >= 0)
    {
        fseek(filein, pos, SEEK_SET);
        ch = fgetc(filein);
        fputc(ch, fileout);
        pos--;
    }

    fclose(filein);
    fclose(fileout);
    return 0;
}
