/* Tamara Alhajj 
 * Mapped-memory example - Writer program
 * Version: March 19, 2018
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "mmap.h"

// return a uniformly generated random number in the range [low,high]
int random_range (unsigned const low, unsigned const high) {
  unsigned const range = high - low + 1;
  return low + (int) (((double) range) * rand () / (RAND_MAX + 1.0));
}

/* Create and write to a shared file for communication with another process.
 *
 * argv[1] = file name
 * argv[2] = number of random digits
 */
int main (int argc, char* const argv[]) {
	int fd, i, count;
	int position = 0;
	char buffer[FILESIZE];
	void* file_memory;
		
	if(argc < 3){
		printf("Usage: ./mmap-write a_file an_int\n");
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
	/* seed the random number generator */
	srand(time (NULL));

	/* open or create a file to hold an unsigned integer  */
	fd = open (argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (!fd)
	{
		printf("ERROR Creating File!\n");
		return 1;
	}

	/* write FILESIZE spaces */
	for (int i=0; i<FILESIZE; i++) write (fd, " ", 1);
	write (fd, "\n", 1); /* write a NULL at EOF */
	
	/* create the memory-mapping  
	 1st param=start addr of mapping into memory, NULL means chosen by OS
	 2nd param=length of map (bytes)
	 3rd param=protection
	 4th param=options, MAP_SHARED used for interprocess communications
	 5th param=file descriptor of mapped file
	 6th param=offset from start of file where mapping starts
	 returns pointer to mapped area
	*/
	file_memory = mmap (NULL, FILESIZE, PROT_WRITE, MAP_SHARED, fd, 0);
	close (fd);
	
	/* write a random integer to memory-mapped area  */
	for(i=0; i<count; i++) {
		int rand = random_range(-100, 100);
		position += snprintf(&buffer[position], FILESIZE - position, "%d ", rand);
	}
	
	/* write to file memory */
	sprintf((char*) file_memory, "%s\n", buffer);
	
	/* release the memory  */
	munmap(file_memory, FILESIZE);
}
