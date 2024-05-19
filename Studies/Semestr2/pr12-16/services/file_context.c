# include "../domain/business_logic/file_context.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>

int write(file_context* context, char* message)
{
    fputs(
        message,
        context->file_to_write
        );
    
    if (errno != 0){
        printf("\x1b[33m");
        perror("In ""write"" funcrion");
        printf("\x1b[31m");
        printf("Exception: %s\n", strerror(errno));
        printf("\x1b[0m");
      
        return -1;
    }

    return 0;
}

int binary_write(file_context* context, char* message)
{
    size_t message_length = strlen(message);

    fwrite(
        message,
        sizeof(char), 
        message_length, 
        context->binary_file_to_write
        );
    
    if (errno != 0){
        printf("\x1b[33m");
        perror("In ""binary_write"" function error: ");
        printf("\x1b[31m");
        printf("Exception: %s\n", strerror(errno));
        printf("\x1b[0m");

        return -1;
    }

    return 0;
}

int add_path(file_context* context, char* path)
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

    if (errno != 0){
        printf("\x1b[31m");
        printf("Exception: %s\n", strerror(errno));
        printf("\x1b[0m");

        return -1;
    }

    return 0;
}

