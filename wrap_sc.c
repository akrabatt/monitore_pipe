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

void create_output_file(int *outfile_fd, const char *outfile_name)
{
	*outfile_fd = open(outfile_name, O_CREAT | O_RDWR | O_TRUNC, 
						S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	
	if(*outfile_fd == -1)
	{
		perror("Error open/create output file!\n"); 
		exit(EXIT_FAILURE);
	}
}
