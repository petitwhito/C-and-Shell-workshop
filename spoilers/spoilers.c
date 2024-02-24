#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(STDERR_FILENO, "Invalid number of arguments\n", 28);
        return 1;
    }
    int openf = open(argv[1], O_RDONLY);
    if (openf == -1)
    {
        write(STDERR_FILENO, "Could not open file\n", 20);
        return 1;
    }
    char buff[1024];
    size_t o_read = read(openf, buff, 1024);
    if (o_read <= 2)
    {
        write(STDERR_FILENO, "File is not long enough\n", 24);
        return 1;
    }

    char end[2];
    end[0] = buff[0];
    end[1] = buff[1];

    for (size_t i = 2; i < o_read; i++)
    {
        if (!isspace(buff[i]))
        {
            end[0] = end[1];
            end[1] = buff[i];
        }
    }
    write(STDOUT_FILENO, end, 2);
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}
