#ifndef FILE_CONTEXT_H
#define FILE_CONTEXT_H

# include <stdio.h>
# include "universal_pointer.h"

typedef struct file_context{
    FILE* file_to_write;
    FILE* binary_file_to_write;

    int (*add_path) ( universal_pointer* value  );
    int (*write) ( universal_pointer* value );
    int (*binary_write) ( universal_pointer* value );
} file_context;

int write( universal_pointer* value);

int binary_write( universal_pointer* value );

int add_path( universal_pointer* value );

# define INIT_FILE_CONTEXT {.add_path = add_path, .write = write, .binary_write = binary_write}

#endif //FILE_CONTEXT_H
