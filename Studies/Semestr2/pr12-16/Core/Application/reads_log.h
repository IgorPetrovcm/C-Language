
#ifndef READS_LOG_H
#define READS_LOG_H

# include "file_context.h"
# include "universal_pointer.h"

typedef struct reads_log {
    file_context* file_context;

    void* (*read_text_file) ( universal_pointer* value );
    void* (*read_bin_file) (universal_pointer* value, int count);
} reads_log;

void* read_text_file( universal_pointer* value);
void* read_bin_file( universal_pointer* value, int count);

#endif //READS_LOG_H
