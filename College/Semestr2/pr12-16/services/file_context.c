# include "../domain/business_logic/file_context.h"
# include <stdio.h>
# include <string.h>

void write(file_context context, char* message)
{
    fputs(
        message,
        context.file_to_write
        );
}

void binary_write(file_context context, char* message)
{
    size_t message_length = strlen(message);

    fwrite(
        message,
        sizeof(char), 
        message_length, 
        context.binary_file_to_write
        );
}

void add_path(file_context context, char* path)
{
    context.file_to_write = fopen(
        strcat(path, "\\output.txt"),
        "w+"
    );

    context.binary_file_to_write = fopen(
        strcat(path, "\\output.bin"),
        "a+b"
    );
}

