#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "wrap_sc.h"


void make_fifo(int *fifo_fd, const char *fifo_file_name)
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

void check_fifo(int *fd_fifo, int *fd_outfile, fd_set *readfds_ptr)
{
	ssize_t bytes_read = 0;
	char buffer[100];
		
	if(FD_ISSET(*fd_fifo, readfds_ptr))
	{
		// read bytes
		bytes_read = read(*fd_fifo, buffer, sizeof(buffer) -1);
		if(bytes_read == -1) 
		{ 	
			perror("Error read from fifo\n"); 	
			exit(EXIT_FAILURE);
		}
		if(bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			printf("Read data from pipe\n");

			// write data from buffer to output file
			if(write(*fd_outfile, buffer, bytes_read) == -1)
			{
				perror("Error write data from fifo to out file!\n");
				exit(EXIT_FAILURE);
			}	
		}
	}
}
