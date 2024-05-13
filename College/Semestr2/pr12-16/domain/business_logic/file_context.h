# ifndef FILE_CONTEXT
# define FILE_CONTEXT

# include <stdio.h>

typedef struct file_context{
    FILE* file_to_write;
    FILE* binary_file_to_write;

    char* path_to_write;
    char* path_to_binary_write;

    void (*add_path) (struct file_context, char* path);
    void (*write) (struct file_context context, char* message);
    //void (*binary_write) (struct file_context context, char* message);
} file_context;

# endif