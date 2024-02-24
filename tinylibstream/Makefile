CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

library: libstream.a

libstream.a: src/lbs_fopen.o src/lbs_fflush.o src/lbs_fputc.o
	 ar csr libstream.a src/lbs_fopen.o src/lbs_fflush.o src/lbs_fputc.o

clean:
	$(RM) libstream.a src/lbs_fopen.o src/lbs_fflush.o src/lbs_fputc.o
