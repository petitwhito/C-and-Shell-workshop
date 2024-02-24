CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

library: libdlist.a

libdlist.a: threshold1.o threshold2.o threshold3.o threshold4.o threshold5.o threshold6.o
	 ar csr libdlist.a threshold1.o threshold2.o threshold3.o threshold4.o threshold5.o threshold6.o

clean:
	$(RM) libdlist.a threshold1.o threshold2.o threshold3.o threshold4.o threshold5.o threshold6.o

