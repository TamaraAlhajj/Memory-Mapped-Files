/* Tamara Alhajj
 * Mapped-memory example - Reader program
 * Version: March 19, 2018
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "mmap.h"

int main (int argc, char* const argv[]) {
	int fd, count, i, integer, offset;
	void* file_memory;
	
	if(argc < 3){
		printf("Usage: ./mmap-read a_file an_int\n");
		return 1;
	}

	/* number of random digits to write to file
	note: sscanf will only return 1 if digit is given */
	if (sscanf(argv[2], "%d*c", &count) == 1){
		//check for positive count
		if(count <= 0){
			printf("Error: invalid number of integers\n");
			return 1;
		}
	}else{
		printf("Error: failed to parse number of integers\n");
		return 1;
	}

	/* open the file  */
	fd = open (argv[1], O_RDWR, S_IRUSR | S_IWUSR);
	if(!fd){
		printf("open error: No such file or directory\n");
		return 1;
	}
	/* create the memory-mapping */
	file_memory = mmap (NULL, FILESIZE, PROT_READ | PROT_WRITE,
			  MAP_SHARED, fd, 0);
	close (fd);

	/* read and print the integer */
	printf ("file contains: ");
	for(i=0; i<count; i++){
		sscanf (file_memory, "%d%n", &integer, &offset);
		printf ("%d ", integer);
		//move forward in file memory to the next int based on offset
		file_memory += offset;
	}
	printf("\n");
	/* release the memory */
	munmap (file_memory, FILESIZE);

  return 0;
}
