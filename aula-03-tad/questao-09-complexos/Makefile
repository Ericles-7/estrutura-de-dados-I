CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: calculadora

calculadora: main.o complexo.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c complexo.h
	$(CC) $(CFLAGS) -c main.c

complexo.o: complexo.c complexo.h
	$(CC) $(CFLAGS) -c complexo.c

clean:
	rm -f *.o calculadora

.PHONY: all clean
