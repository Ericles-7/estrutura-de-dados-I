CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: teste_vetor

teste_vetor: main.o vetord.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c vetord.h
	$(CC) $(CFLAGS) -c main.c

vetord.o: vetord.c vetord.h
	$(CC) $(CFLAGS) -c vetord.c

clean:
	rm -f *.o teste_vetor

.PHONY: all clean
