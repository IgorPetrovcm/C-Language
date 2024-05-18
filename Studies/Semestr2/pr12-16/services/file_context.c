# include "../domain/business_logic/file_context.h"
# include <stdio.h>
# include <string.h>

void write(file_context* context, char* message)
{
    fputs(
        message,
        context->file_to_write
        );
}

void binary_write(file_context* context, char* message)
{
    size_t message_length = strlen(message);

    int true_writes = fwrite(
        message,
        sizeof(char), 
        message_length, 
        context->binary_file_to_write
        );

    printf("%d", true_writes);
}

void add_path(file_context* context, char* path)
{
    char path_to_text[255];
    strcpy(path_to_text, path);

    char path_to_bin[255]; 
    strcpy(path_to_bin, path);

    context->file_to_write = fopen(
        strcat(path_to_text, "/output.txt"),
        "w+"
    );

    context->binary_file_to_write = fopen(
        strcat(path_to_bin, "/output.bin"),
        "a+b"
    );

    if (context->file_to_write == NULL || context->binary_file_to_write == NULL){
        printf("NOOOO");
    }
}

