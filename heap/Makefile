CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

library: libheap.a

libheap.a: add.o create.o del.o pop.o print.o
	 ar csr libheap.a add.o create.o del.o pop.o print.o

clean:
	$(RM) libheap.a add.o create.o del.o pop.o print.o

