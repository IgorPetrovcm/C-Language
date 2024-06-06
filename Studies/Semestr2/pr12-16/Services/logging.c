# include "../Core/Application/logging.h"
# include "../Core/Application/node_list.h"
# include "../Core/Domain/student.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <errno.h>

void logging_current_time()
{
    time_t to_time = time(NULL);

    struct tm* current_time = localtime(&to_time);

    printf("logging: %d:%d:%d", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}

void register_log( universal_pointer* value )
{
    logging* logging = (struct logging*)value->object;

    logging->logs_count++;

    logging->logs_output = realloc( logging->logs_output, logging->logs_count * sizeof(log_output));

    logging->logs_output[ logging->logs_count - 1 ] = value->value;
}

void logging_console( universal_pointer* value )
{
    printf("\x1b[33m");
    logging_current_time();
    printf("\n");
    printf("\x1b[0m");

    printf("%s", (char*)value->value);
}

void logging_text_file( universal_pointer* value )
{
    log_settings* settings = (log_settings*)value->object;

    universal_pointer* meta = (universal_pointer*)malloc(sizeof(universal_pointer));
    meta->object = settings->context;
    meta->value = value->value;

    settings->context->write( meta );

    printf("\x1b[33m");
    printf("A text file written to - ");
    logging_current_time();
    printf("\n");
    printf("\033[0;37m");
}

void logging_binary_file( universal_pointer* value )
{
    log_settings* settings = (log_settings*)value->object;

    universal_pointer* meta = (universal_pointer*)malloc(sizeof(universal_pointer));
    meta->object = settings->context;
    meta->value = value->value;

    settings->context->binary_write( meta );

    printf("\x1b[33m");
    printf("A binary file written to - ");
    logging_current_time();
    printf("\n");
    printf("\033[0;37m");
}

int launch( universal_pointer* value )
{
    logging* logging = (struct logging*)value->object;

    for (int i = 0; i < logging->logs_count; i++)
    {
        universal_pointer* meta = (universal_pointer*)malloc(sizeof(universal_pointer));
        meta->object = logging->settings;
        meta->value = value->value;

        logging->logs_output [i]( meta );
    }

    fclose( logging->settings->context->file_to_write );
    // fclose( logging->settings->context->binary_file_to_write );

    if (errno != 0){
        printf("\x1b[33m");
        perror("In ""launch"" function error: ");
        printf("\x1b[31m");
        printf("Exception: %s\n", strerror(errno));
        printf("\x1b[0m");

        return -1;
    }

    return 0;

}

void write_structure( universal_pointer* value ) {
    file_context* context = value->object;

    node_list* students = (node_list*)value->value;

    node* node = students->head;

    while (node != NULL){
        student* student = (struct student*)node->value;

        int size_struct_student = sizeof(struct student);

        char* struct_pointer = (char*)student;
        for ( int j = 0; j < size_struct_student; j++ ) {
            putc( *struct_pointer++, context->binary_file_to_write );
        }

        node = node->next;
    }

    fclose( context->binary_file_to_write );
}