# include "../domain/business_logic/logging.h"
# include <stdio.h>

void log_to_console(log_worker worker, char* information)
{
    printf("%s", information);
}

void logger_to_console(log_worker worker)
{
    worker.logger[ worker.logger_count ] = log_to_console;
}

void logger_to_text_file(log_worker worker, )
{

}