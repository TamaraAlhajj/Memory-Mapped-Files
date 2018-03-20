# Memory-Mapped Files #

## Authors ##

Tamara Alhajj 
100948027

Professor Michel Barbeau
COMP3000, Exercise 8

## Purpose  ##

To implement a mmap write and read programs such that, 
the former write n random integers to the ﬁle 
and the latter reads and prints all integers. 

## Getting Started ##

From working directory, compile and run by simply typing make.

n is an argument to both programs; it must be a positive integer. 
This will run a test for the programs where n = 10.
Following this the erroneous cases will be tested.

To run a custom test type:
```
make all
./mmap-write afile anInt
./mmap-read afile anInt
```

To clean:
```
make clean
```

## Acknowledgments ##

Code sources:
[Makefile info](http://www.gnu.org/software/make/manual/make.html#Special-Targets%20GNU%20Make%20Manual)
[snprintf manual](https://linux.die.net/man/3/snprintf)
[snprintf info](http://joequery.me/code/snprintf-c/)