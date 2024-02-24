CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

library: libbinary_tree.a

libbinary_tree.a: other.o display.o
	 ar csr libbinary_tree.a other.o display.o

clean:
	$(RM) libbinary_tree.a other.o display.o
