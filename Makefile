CC = gcc
CFLAGS = -g
OBJFLAG = -c
OFLAG = -o
OBJS = main.o wrap_sc.o
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) $(OFLAG) $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) $(OBJFLAG) main.c

wrap_sc.o: wrap_sc.c
	$(CC) $(CFLAGS) $(OBJFLAG) wrap_sc.c

clean:
	rm -rf $(TARGET) $(OBJS) my_fifo out_file.txt
