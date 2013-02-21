CC=gcc
CFLAGS=-g -ansi -Wall


all: zeichne soundex

zeichne: zeichne.o
	$(CC) $(CFLAGS) zeichne.o -o zeichne

zeichne.o: zeichne.c
	$(CC) -c $(CFLAGS) zeichne.c

soundex: soundex.o
	$(CC) $(CFLAGS) soundex.o -o soundex

soundex.o: soundex.c
	$(CC) -c $(CFLAGS) soundex.c

runzeichne: zeichne

r_sound: soundex
	./soundex soundex soundeggs flurbel