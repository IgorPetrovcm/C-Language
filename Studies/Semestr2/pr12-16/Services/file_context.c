# include "../Core/Application/file_context.h"
# include "../Core/Application/universal_pointer.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>

int write( universal_pointer* value )
{
    file_context* context = (file_context*)value->object;

    fputs(
        (char*)value->value,
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

int binary_write( universal_pointer* value )
{
    file_context* context = (file_context*)value->object;

    size_t message_length = strlen( (char*)value->value );

    fwrite(
        (char*)value->value,
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

int add_path( universal_pointer* value )
{
    file_context* context = value->object;

    char path_to_text[255];
    strcpy(path_to_text, (char*)value->value);

    char path_to_bin[255];
    strcpy(path_to_bin, (char*)value->value);

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