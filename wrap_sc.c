#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "wrap_sc.h"



void make_fifo(int *fifo_fd, const cahr *fifo_file_name)
{
	// create fifo
	if((mkfifo(fifo_file_name, 0666)) == -1) 
	{ 
		perror("Error create FIFO pipe!\n"); 
		exit(EXIT_FAILURE); 
	}	

	// open fifo and get fifo's descriptor
	*fifo_fd = open(fifo_file_name, O_RDONLY);
	if(*fifo_fd == -1) 
	{ 
		perror("Error open fifo!\n"); 
		exit(EXIT_FAILURE); 
	}
}
