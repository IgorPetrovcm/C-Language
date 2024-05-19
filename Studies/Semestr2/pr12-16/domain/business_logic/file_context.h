# ifndef FILE_CONTEXT
# define FILE_CONTEXT

# include <stdio.h>

typedef struct file_context{
    FILE* file_to_write;
    FILE* binary_file_to_write;

    int (*add_path) (struct file_context*, char* path);
    int (*write) (struct file_context*, char*);
    int (*binary_write) (struct file_context*, char*);
} file_context;

int write(file_context*, char* );

int binary_write(file_context*, char*);

int add_path(file_context*, char*);

# define INIT_FILE_CONTEXT {.add_path = add_path, .write = write, .binary_write = binary_write}

# endif