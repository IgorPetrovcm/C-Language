CC=gcc
OBJFLAG=-o
CFLAG=-c

all: program

program: file_context.o logging.o node_list.o tools.o
	$(CC) $(OBJFLAG) program main.c file_context.o logging.o node_list.o tools.o

file_context.o:
	$(CC) $(OBJFLAG) file_context.o $(CFLAG) services/file_context.c

logging.o:
	$(CC) $(OBJFLAG) logging.o $(CFLAG) services/logging.c

node_list.o:
	$(CC) $(OBJFLAG) node_list.o $(CFLAG) services/node_list.c

tools.o:
	$(CC) $(OBJFLAG) tools.o $(CFLAG) ../tools_12_16/tools.c
 
clean:
	rm *.o