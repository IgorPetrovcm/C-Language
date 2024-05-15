# ifndef LOGGING
# define LOGGING

# include "file_context.h"


typedef struct log_worker{
    char* title;
    int logger_count;
    file_context context;
    
    void (*logme) (struct log_worker, char* information);

    void (*log_current_time) ();

    void (*logger[]) (struct log_worker worker, char* information);
} log_worker;

void logme (log_worker, char*);
void log_current_time ();

void logger_to_console(log_worker);
void logger_to_text_file(log_worker);
void logger_to_binary_file(log_worker); 

# define INIT_LOG_WORKER {.log_current_time = log_current_time, .logme = logme, .context = INIT_FILE_CONTEXT}

# endif