#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/libstream.h"

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd < 0)
        return NULL;

    struct stream *res = malloc(sizeof(struct stream));
    res->buffering_mode = STREAM_BUFFERED;
    res->error = 0;
    res->io_operation = 0;
    res->buffered_size = 0;
    res->already_read = 0;

    if (isatty(fd))
        res->buffering_mode = STREAM_LINE_BUFFERED;
    if (errno == EBADF)
    {
        free(res);
        return NULL;
    }

    res->fd = fd;

    if (strcmp(mode, "r") == 0)
        res->flags = O_RDONLY;
    else if (strcmp(mode, "w") == 0)
        res->flags = O_WRONLY;
    else if (strcmp(mode, "r+") == 0)
        res->flags = O_RDWR;
    else
        res->flags = O_RDWR | O_CREAT | O_TRUNC;

    return res;
}

struct stream *wri(int fd, struct stream *res)
{
    if (fd == -1)
    {
        free(res);
        return NULL;
    }
    if (isatty(fd))
        res->buffering_mode = STREAM_LINE_BUFFERED;
    res->flags = O_WRONLY | O_CREAT | O_TRUNC;
    res->fd = fd;
    return res;
}

struct stream *rea(int fd, struct stream *res)
{
    if (fd == -1)
    {
        free(res);
        return NULL;
    }
    if (isatty(fd))
        res->buffering_mode = STREAM_LINE_BUFFERED;
    res->flags = O_RDONLY;
    res->fd = fd;
    return res;
}

struct stream *reaplus(int fd, struct stream *res)
{
    if (fd == -1)
    {
        free(res);
        return NULL;
    }
    if (isatty(fd))
        res->buffering_mode = STREAM_LINE_BUFFERED;
    res->flags = O_RDWR;
    res->fd = fd;
    return res;
}

struct stream *wriplus(int fd, struct stream *res)
{
    if (fd == -1)
    {
        free(res);
        return NULL;
    }
    if (isatty(fd))
        res->buffering_mode = STREAM_LINE_BUFFERED;
    res->flags = O_RDWR | O_CREAT | O_TRUNC;
    res->fd = fd;
    return res;
}

struct stream *lbs_fopen(const char *path, const char *mode)
{
    struct stream *res = malloc(sizeof(struct stream));
    res->buffering_mode = STREAM_BUFFERED;
    res->error = 0;
    res->io_operation = 0;
    res->buffered_size = 0;
    res->already_read = 0;

    if (strcmp(mode, "r") == 0)
    {
        int fd = open(path, O_RDONLY);
        return rea(fd, res);
    }
    else if (strcmp(mode, "w") == 0)
    {
        int fd = open(path, O_WRONLY);
        return wri(fd, res);
    }
    else if (strcmp(mode, "r+") == 0)
    {
        int fd = open(path, O_RDWR);
        return reaplus(fd, res);
    }
    else if (strcmp(mode, "w+") == 0)
    {
        int fd = open(path, O_RDWR | O_CREAT | O_TRUNC);
        return wriplus(fd, res);
    }

    return res;
}
