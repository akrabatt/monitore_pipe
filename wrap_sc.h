#ifndef WRAP_H
#define WRAP_H

/**
* create fifo and get descriptor
*/
void make_fifo(int *fifo_fd, const char *fifo_file_name);

void create_output_file(int *outfile_fd, const cahr *outfile_name);

#endif // WRAP_H
