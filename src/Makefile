CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic -std=c17 -g

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o


main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f main main.o