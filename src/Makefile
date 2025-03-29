CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic -std=c17 -g

boundary/obj/message.o: boundary/message.c boundary/message.h
	$(CC) $(CFLAGS) -c boundary/message.c -o boundary/obj/message.o

boundary/bin/client: boundary/client.c boundary/obj/message.o
	$(CC) $(CFLAGS) -o boundary/bin/client boundary/client.c boundary/obj/message.o

boundary/bin/serveur: boundary/serveur.c boundary/obj/message.o
	$(CC) $(CFLAGS) -o boundary/bin/serveur boundary/serveur.c boundary/obj/message.o

all: boundary/bin/client boundary/bin/serveur

clean:
	rm -f boundary/obj/*.o boundary/bin/client boundary/bin/serveur