CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

library: libdlist.a

libdlist.a: threshold1.o threshold2.o threshold3.o
	 ar csr libdlist.a threshold1.o threshold2.o threshold3.o

clean:
	$(RM) libdlist.a threshold1.o threshold2.o threshold3.o

