CC = gcc
CFLAGS = -Wall -g

program: main.o options.o
	$(CC) $(CFLAGS) -o program main.o options.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

options.o: options.c
	$(CC) $(CFLAGS) -c options.c

clean:
	rm -f *.o program
