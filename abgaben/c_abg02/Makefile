CC=gcc
DD=-g -ansi -Wall


all: bits

bits: bits.o
	$(CC) $(DD) bits.o -o bits

bits.o: bits.c
	$(CC) -c $(DD) bits.c

run: bits
	./bits 101 and 10
	./bits 1 or 0
	./bits 101 or 10
	./bits 101 and 10
	./bits 101 xor 11
	./bits 101 lshift 10
	./bits 1101 rshift 10