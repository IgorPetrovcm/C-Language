
#ifndef LOGGING_H
#define LOGGING_H

# include "file_context.h"
# include "universal_pointer.h"

typedef struct log_settings{
    char* title;

    file_context* context;
} log_settings;

typedef void (*log_output) ( universal_pointer* value );

typedef struct logging{
    log_output* logs_output;
    int logs_count;

    log_settings* settings;

    void (*register_log) ( universal_pointer* value );

    void (*logging_current_time) ();

    int (*launch) ( universal_pointer* value );

} logging;

void logging_current_time ();
int launch ( universal_pointer* value );

void register_log( universal_pointer* value );

void logging_console( universal_pointer* value );
void logging_text_file( universal_pointer* value );
void logging_binary_file( universal_pointer* value );

# define INIT_LOGGING {.register_log = register_log, .logging_current_time = logging_current_time, .launch = launch}

#endif //LOGGING_H
