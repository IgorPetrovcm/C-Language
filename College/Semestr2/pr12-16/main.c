# include "domain/business_logic/file_context.h"
# include "domain/model/student.h"
# include "domain/business_logic/logging.h"
# include "domain/business_logic/node_list.h"

# include <stdio.h>
# include <stdlib.h>

int main()
{
    log_worker loggers = INIT_LOG_WORKER;

    node_list students = INIT_NODE_LIST;

    for (int i = 0; i < 100; i++)
    {
        struct student* rnd_student = (struct student*)malloc(sizeof(struct student));

        //rnd_student->last_name = 
    }
}