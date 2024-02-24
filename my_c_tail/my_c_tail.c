#include "my_c_tail.h"

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void stdintail(unsigned int n)
{
    unsigned int count = 0;
    char c;

    char *s = malloc(sizeof(char));
    int i = 0;
    size_t memorysize = 1;
    ssize_t check_read;

    while ((check_read = read(STDIN_FILENO, &c, 1)) == 1)
    {
        if (c == '\n')
            count++;

        s[i] = c;
        memorysize++;
        s = realloc(s, memorysize * sizeof(char));

        i++;
    }

    s[i] = '\0';

    unsigned mini = count - n;

    if (count < n)
        mini = 0;

    for (int j = 0; j < i; j++)
    {
        char ch = s[j];
        if (mini == 0)
        {
            write(STDOUT_FILENO, &ch, 1);
        }
        if (mini > 0 && s[j] == '\n')
            mini--;
    }

    free(s);
}
