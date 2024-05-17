# ifndef LOGGING
# define LOGGING

# include "file_context.h"

typedef struct log_settings{
    char* title;

    file_context* context;    
} log_settings;

typedef void (*log_output) (struct log_settings*, char*);

typedef struct logging{
    log_output* logs_output;
    int logs_count;

    log_settings* settings;

    void (*register_log) (struct logging*, void (*) (log_settings*, char*));

    void (*logging_current_time) ();

    void (*launch) (struct logging*, char*);

} logging;

void logging_current_time ();
void launch (logging*, char*);

void register_log(logging*, void (*) (log_settings*, char*));

void logging_console(log_settings*, char*);
void logging_text_file(log_settings*, char*);
void logging_binary_file(log_settings*, char*); 

# define INIT_LOGGING {.register_log = register_log, .logging_current_time = logging_current_time, .launch = launch}

# endif