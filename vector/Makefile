CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

library: libvector.a

libvector.a: add.o delete.o
	 ar csr libvector.a add.o delete.o

