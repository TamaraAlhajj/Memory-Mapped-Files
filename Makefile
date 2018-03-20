#for testing of errors without raising recipe for target fails
MAKEFLAGS = --silent --ignore-errors --no-print-directory

test: all
	echo "\nTESTING ./mmap-write tester 10"
	echo "-------------------------------"
	exec ./mmap-write tester 10
	echo "cat tester"
	cat tester
	echo "TESTING ./mmap-read tester 10"
	echo "------------------------------"
	exec ./mmap-read tester 10
	echo "\n"
	echo "ERRORS: no file given, invalid digit"
	echo "---------------------------------------------"
	echo "TESTING write"
	exec ./mmap-write
	exec ./mmap-write fail x
	exec ./mmap-write fail 0
	echo "\nTESTING read"
	exec ./mmap-read
	exec ./mmap-read fail x
	exec ./mmap-read fail 0
	echo "\n"

all: mmap-read.o mmap-write.o
	gcc -o mmap-read mmap-read.o
	gcc -o mmap-write mmap-write.o

mmap-read.o: mmap-read.c
	gcc -c mmap-read.c

mmap-write.o: mmap-write.c
	gcc -c mmap-write.c

clean:
	rm -f *.o mmap-read mmap-write tester *~
