#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/libstream.h"

int lbs_fputc(int c, struct stream *stream)
{
    if (stream->io_operation == STREAM_READING)
        lbs_fflush(stream);
    stream->io_operation = STREAM_WRITING;

    if (!stream_writable(stream))
        return -1;

    unsigned char ch = c;
    stream->buffer[stream->buffered_size] = ch;
    stream->buffered_size++;

    if (stream->buffered_size == LBS_BUFFER_SIZE)
    {
        if (lbs_fflush(stream) == EOF)
        {
            return -1;
        }
    }
    if (stream->buffering_mode == STREAM_UNBUFFERED)
    {
        if (lbs_fflush(stream) == EOF)
        {
            return -1;
        }
    }
    if (stream->buffering_mode == STREAM_LINE_BUFFERED && ch == '\n')
    {
        if (lbs_fflush(stream) == EOF)
        {
            return -1;
        }
    }

    return c;
}

int lbs_fgetc(struct stream *stream)
{
    if (stream->io_operation == STREAM_WRITING)
        lbs_fflush(stream);
    stream->io_operation = STREAM_READING;

    if (!stream_readable(stream))
        return -1;

    if (stream->buffered_size == stream->already_read)
    {
        size_t j = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        if (j == 0)
            return -1;
        stream->buffered_size = j;
        stream->already_read = 0;
    }
    stream->already_read++;
    unsigned char res = stream->buffer[stream->already_read - 1];
    return res;
}
