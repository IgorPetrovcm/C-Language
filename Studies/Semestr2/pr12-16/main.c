# include "domain/business_logic/file_context.h"
# include "domain/model/student.h"
# include "domain/business_logic/logging.h"
# include "domain/business_logic/node_list.h"

# include "../tools_12_16/tools.h"

# include <stdio.h>
# include <stdlib.h>

const char GROUPS_COUNT = 5;
const char GROUP_NAME_COUNT = 3;

int main()
{
    log_worker loggers = INIT_LOG_WORKER;

    char* groups = (char*)calloc(GROUPS_COUNT, sizeof(char));
    for (int i = 0; i < GROUPS_COUNT; i++)
    {
        groups[i] = get_word((int)GROUP_NAME_COUNT);
    }

    node_list students = INIT_NODE_LIST;

    for (int i = 0; i < 100; i++)
    {
        struct student* rnd_student = (struct student*)malloc(sizeof(struct student));

        rnd_student->last_name = get_word(6); 

        rnd_student->first_name = get_word(5);

        rnd_student->gender = (char)rand() % 2;

        rnd_student->group
    }
}