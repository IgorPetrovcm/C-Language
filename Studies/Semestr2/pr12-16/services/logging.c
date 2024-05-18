# include "../domain/business_logic/logging.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void logging_current_time()
{
    time_t to_time = time(NULL);

    struct tm* current_time = localtime(&to_time);

    printf("logging: %d:%d:%d", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}

void register_log(logging* logging, void (*log)(log_settings *, char*))
{    
    logging->logs_count++;

    logging->logs_output = realloc( logging->logs_output, logging->logs_count * sizeof(log_output));

    logging->logs_output[ logging->logs_count - 1 ] = log;
}

void logging_console(log_settings* setting, char* information)
{
    printf("\x1b[33m");
    logging_current_time();
    printf("\n");
    printf("\x1b[0m");

    printf("%s", information);
}

void logging_text_file(log_settings* setting, char* information)
{
    setting->context->write( setting->context, information );

    printf("\x1b[33m");
    printf("A text file written to - ");
    logging_current_time();
    printf("\n");
    printf("\033[0;37m");
}

void logging_binary_file(log_settings* setting, char* information)
{
    setting->context->binary_write( setting->context, information );

    printf("\x1b[33m");
    printf("A binary file written to - ");
    logging_current_time();
    printf("\n");
    printf("\033[0;37m");
}

void launch(logging* logging, char* information)
{
    for (int i = 0; i < logging->logs_count; i++)
    {
        logging->logs_output [i]( logging->settings, information );
    }

    fclose( logging->settings->context->binary_file_to_write );
    fclose( logging->settings->context->file_to_write );

}