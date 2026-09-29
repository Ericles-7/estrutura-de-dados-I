CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: teste_matriz

teste_matriz: main.o matriz.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c matriz.h
	$(CC) $(CFLAGS) -c main.c

matriz.o: matriz.c matriz.h
	$(CC) $(CFLAGS) -c matriz.c

clean:
	rm -f *.o teste_matriz

.PHONY: all clean
