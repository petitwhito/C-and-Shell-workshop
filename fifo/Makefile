CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

library: libfifo.a

libfifo.a: fifo_access.o fifo_setup_destroy.o
	 ar csr libfifo.a fifo_access.o fifo_setup_destroy.o

clean:
	$(RM) libfifo.a fifo_access.o fifo_setup_destroy.o

