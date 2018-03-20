# Memory-Mapped Files #

Last modified: 19th March 2018 <br />
COMP3000, Exercise 8 <br />

## Authors ##

Tamara Alhajj - 100948027<br />
Professor Michel Barbeau

## Purpose  ##

To implement a mmap write and read programs such that, <br />
the former write n random integers to the ﬁle <br />
and the latter reads and prints all integers. <br />

## Getting Started ##

From working directory, compile and run by simply typing make.<br />
n is an argument to both programs; it must be a positive integer.<br />
This will run a test for the programs where n = 10.<br />
Following this the erroneous cases will be tested and print output.<br />
<br />
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

Code sources:<br />
[Makefile info](http://www.gnu.org/software/make/manual/make.html#Special-Targets%20GNU%20Make%20Manual)<br />
[snprintf manual](https://linux.die.net/man/3/snprintf)<br />
[snprintf info](http://joequery.me/code/snprintf-c/)<br />
