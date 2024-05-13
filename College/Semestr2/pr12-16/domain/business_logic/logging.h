# ifndef LOGGING
# define LOGGING

# include "file_context.h"

typedef struct log_worker{
    char* title;
    int logger_count;
    file_context context;
    
    void (*log) (struct log_worker);
    
    void (*logger[]) (struct log_worker worker, char* information);
} log_worker;

# endif