CC=gcc
CFLAGS=-g -Wall -ansi

all: rotl13 rot13lib.o

rotl13.o: rotl13.c
	$(CC) -c $(CFLAGS) rotl13.c

rot13lib.o: rot13lib.c
	$(CC) -c $(CFLAGS) rot13lib.c

rotl13: rot13lib.o rotl13.o
	$(CC) $(CFLAGS) rot13lib.o rotl13.o -o rotl13