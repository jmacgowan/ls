CC = gcc
CFLAGS = -Wall -Wextra -pedantic

.PHONY: all clean

all: ls_program

ls_program: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f ls_program main.o
