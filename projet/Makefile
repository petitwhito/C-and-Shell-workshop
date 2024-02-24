CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic
LDLIBS=-lcriterion

TESTNAME=tests/testsuite.c src/tinyprintf.c src/tinyprintf.h

all: src/tinyprintf.o

src/tinyprintf.o: src/tinyprintf.c
	$(CC) $(CFLAGS) -c -o src/tinyprintf.o src/tinyprintf.c

check:
	$(CC) $(CFLAGS) $(LDLIBS) $(TESTNAME) -o res
	./res

clean:
	$(RM) res src/tinyprintf.o


