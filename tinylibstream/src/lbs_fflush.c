#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/libstream.h"

int lbs_fclose(struct stream *file)
{
    int f = lbs_fflush(file);
    if (f == -1)
        return -1;

    lbs_clearerr(file);
    close(file->fd);
    free(file);
    return 1;
}

int lbs_fflush(struct stream *stream)
{
    if (!stream)
        return -1;

    if (stream->io_operation == STREAM_WRITING)
    {
        char *buff = stream->buffer;
        ssize_t a = 0;
        size_t count = 0;
        while (count < stream->buffered_size)
        {
            a = write(stream->fd, buff + count, stream->buffered_size - count);
            if (a == -1)
            {
                stream->error = -1;
                return -1;
            }
            count += a;
        }

        stream->buffered_size = 0;
        stream->already_read = 0;
    }

    if (stream->io_operation == STREAM_READING)
    {
        size_t remainder = stream_remaining_buffered(stream);
        off_t t = 0;
        if (remainder != 0)
            t = lseek(stream->fd, -remainder, SEEK_CUR);
        if (t == -1)
        {
            stream->error = -1;
            return -1;
        }
        stream->buffered_size = 0;
        stream->already_read = 0;
    }

    return 0;
}
