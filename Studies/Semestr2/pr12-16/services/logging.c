# include "../domain/business_logic/logging.h"
# include <stdio.h>
# include <time.h>

void log_current_time()
{
    time_t to_time = time(NULL);

    struct tm* current_time = localtime(&to_time);

    printf("%d:%d:%d", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}

void log_to_console(log_worker worker, char* information)
{
    printf("\033[0;33m");
    log_current_time();
    printf("\n");
    printf("\033[0;37m");

    printf("%s", information);
}

void logger_to_console(log_worker worker)
{
    worker.logger[ worker.logger_count ] = log_to_console;

    worker.logger_count++;
}

void log_to_text_file(log_worker worker, char* information)
{
    worker.context.write( worker.context, information );

    printf("\033[0;33m");
    printf("A text file written to - ");
    log_current_time();
    printf("\n");
    printf("\033[0;37m");
}

void logger_to_text_file(log_worker worker)
{
    worker.logger[ worker.logger_count ] = log_to_text_file;

    worker.logger_count++;
}

void log_to_binary_file(log_worker worker, char* information)
{
    worker.context.binary_write( worker.context, information );

    printf("\033[0;33m");
    printf("A binary file written to - ");
    log_current_time();
    printf("\n");
    printf("\033[0;37m");
}

void logger_to_binary_file(log_worker worker)
{
    worker.logger[ worker.logger_count ] = log_to_binary_file;

    worker.logger_count++;
}

void logme(log_worker worker, char* information)
{
    for (int i = 0; i < worker.logger_count; i++)
    {
        worker.logger[i](worker, information);
    }
}