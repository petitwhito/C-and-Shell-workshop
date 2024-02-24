#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char *rot_x(char *s, int x)
{
    char *tmp = s;
    if (*tmp >= 'a' && *tmp <= 'z')
    {
        while (x < 0)
        {
            x += 26;
        }
        *tmp = (*tmp - 'a' + x) % 26 + 'a';
    }
    else if (*tmp >= 'A' && *tmp <= 'Z')
    {
        while (x < 0)
        {
            x += 26;
        }
        *tmp = (*tmp - 'A' + x) % 26 + 'A';
    }
    else if (*tmp >= '0' && *tmp <= '9')
    {
        while (x < 0)
        {
            x += 10;
        }
        *tmp = (*tmp - '0' + x) % 10 + '0';
    }
    s = tmp;
    return s;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    int x = atoi(argv[1]);
    char c;

    ssize_t check_read = read(STDIN_FILENO, &c, 1);

    ssize_t check_write = write(STDOUT_FILENO, rot_x(&c, x), 1);

    if (check_write == -1 || check_read == -1)
        return 1;

    while (1)
    {
        check_read = read(STDIN_FILENO, &c, 1);
        if (check_read == -1)
            return 1;
        else if (check_read == 0)
            return 0;

        check_write = write(STDOUT_FILENO, rot_x(&c, x), 1);
        if (check_write == -1)
            return 1;
    }
    return 0;
}
