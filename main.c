#include <stdio.h>
#include "wrap_sc.h"

int main()
{
	// descriptors
	int fd_fifo;
	int fd_outfile;

	// create fd set struct
	fd_set readfds;
	fd_set *readfds_ptr = &readfds;
	
	// create files and get its descriptors
	make_fifo(&fd_fifo, "my_fifo");
	create_output_file(&fd_outfile, "out_file.txt");
	
	// up fifo descriptor for select sys call
	int fd_fifo_up = fd_fifo + 1;
	
	FD_ZERO(&readfds);
	FD_SET(fd_fifo, &readfds);

	while(1)
	{
		int activity_fifo = select(fd_fifo_up, &readfds, NULL, NULL, NULL);
		if(activity_fifo == -1)
		{ 
			perror("Select error!\n");
			exit(EXIT_FAILURE);	
		}

		check_fifo(&fd_fifo, &fd_outfile, read_fds_ptr);
	}	
	
	return 0;
}
