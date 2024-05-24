# include "../domain/business_logic/logging.h"
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

void register_log(void* meta)
{    
    logging_register_log_meta* single_meta = (logging_register_log_meta*)meta;

    single_meta->logging->logs_count++;

    single_meta->logging->logs_output = realloc( single_meta->logging->logs_output, single_meta->logging->logs_count * sizeof(log_output));

    single_meta->logging->logs_output[ single_meta->logging->logs_count - 1 ] = single_meta->log;
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

int launch(void* meta)
{
    logging_launch_meta* single_meta = (logging_launch_meta*)meta;

    for (int i = 0; i < single_meta->logging->logs_count; i++)
    {
        single_meta->logging->logs_output [i]( single_meta->logging->settings, single_meta->information );
    }

    fclose( single_meta->logging->settings->context->file_to_write );
    fclose( single_meta->logging->settings->context->binary_file_to_write );

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