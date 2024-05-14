CC=gcc
OBJFLAG=-o
CFLAG=-c

all: program

program: file_context.o logging.o node_list.o
	$(CC) $(OBJFLAG) program main.c file_context.o logging.o node_list.o

file_context.o:
	$(CC) $(OBJFLAG) file_context.o $(CFLAG) services/file_context.c

logging.o:
	$(CC) $(OBJFLAG) logging.o $(CFLAG) services/logging.c

node_list.o:
	$(CC) $(OBJFLAG) node_list.o $(CFLAG) services/node_list.c

clean:
	rm *.o