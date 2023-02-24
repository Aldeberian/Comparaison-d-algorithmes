CC = gcc
CFLAGS = -Wall -std=c99

all: main

main: main.o comptage.o
	$(CC) $(CFLAGS) -o main main.o comptage.o -lm 

main.o: main.c comptage.h
	$(CC) $(CFLAGS) -c main.c -lm -lc 

comptage.o: comptage.c comptage.h
	$(CC) $(CFLAGS) -c comptage.c 

clean:
	rm -f main main.o comptage.o
