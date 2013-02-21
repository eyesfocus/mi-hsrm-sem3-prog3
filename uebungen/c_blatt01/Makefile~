CC=gcc
DD=-g -ansi -Wall


all: hello rot13 io heron zahlen

hello: hello.o
	$(CC) $(DD) hello.o -o hello

hello.o: hello.c
	$(CC) -c $(DD) hello.c

rot13: rot13.o
	$(CC) $(DD) rot13.o -o rot13

rot13.o: rot13.c
	$(CC) -c $(DD) rot13.c

io: io.o
	$(CC) $(DD) io.o -o io

io.o: io.c
	$(CC) -c $(DD) io.c

heron: heron.o
	$(CC) $(DD) heron.o -o heron

heron.o: heron.c
	$(CC) -c $(DD) heron.c

zahlen: zahlen.o
	$(CC) $(DD) zahlen.o -o zahlen

zahlen.o: zahlen.c
	$(CC) -c $(DD) zahlen.c

runhello: hello
	./hello

runrot: rot13
	cat test.txt | ./rot13 | ./rot13 > rotaus

runio: io
	./io

runheron: heron
	./heron 2.0
	./heron 4.0
	./heron 7.0
	./heron 9.0
	./heron 16.0
	./heron 17.0

clean:
	-/bin/rm hello hello.o rot13 rot13.o rotaus io io.o heron heron.o zahlen zahlen.o

