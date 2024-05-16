# include "domain/business_logic/file_context.h"
# include "domain/model/student.h"
# include "domain/business_logic/logging.h"
# include "domain/business_logic/node_list.h"

# include "../tools_12_16/tools.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

const char GROUPS_COUNT = 5;
const char GROUP_NAME_COUNT = 3;

const char genders[] = {102, 109}; // [0] = f(female); [1] = m(male)

char input_path[255];

int main()
{
    log_worker loggers = INIT_LOG_WORKER;
    logger_to_console(loggers);

    strcpy(input_path, ".");
    loggers.context.add_path( loggers.context, input_path);

    logger_to_text_file(loggers);
    logger_to_binary_file(loggers);

    char* groups[ GROUPS_COUNT];

    for (int i = 0; i < GROUPS_COUNT; i++)
    {
        groups[i] = get_word((int)GROUP_NAME_COUNT);
    }

    node_list students = INIT_NODE_LIST;

    for (int i = 0; i < 100; i++)
    {
        student* rnd_student = (struct student*)malloc(sizeof(struct student));

        rnd_student->last_name = get_word(6); 

        rnd_student->first_name = get_word(5);

        rnd_student->age = 16 + rand() % 5;

        rnd_student->gender = genders[ rand() % 2 ];

        rnd_student->group = groups[ rand() % (GROUPS_COUNT) ];

        rnd_student->math_score =  2 + rand() % 4;
        rnd_student->chemistry_score = 2 + rand() % 4;
        rnd_student->physics_score = 2 + rand() % 4;

        students.add(&students, rnd_student);

        printf("%d\t%s\t%s\t%c\t%s\t%d\t%d\n", rnd_student->age, rnd_student->last_name, rnd_student->first_name, rnd_student->gender, rnd_student->group, rnd_student->math_score, rnd_student->chemistry_score);
    }


    node_list sorted_students = INIT_NODE_LIST;

    node* student = students.head;

    while (student != NULL)
    {
        struct student* current = student->value;

        if (current->chemistry_score == 5 && current->gender == genders[0] ){
            sorted_students.add(&sorted_students, current);
        }
        student = student->next;
    }

    char record[2000];

    student = sorted_students.head;

    strcpy(record, "\n");

    while (student != NULL)
    {
        struct student* current = student->value;

        strcat(record, current->last_name);
            strcat(record, "\t");
        strcat(record, current->first_name);
            strcat(record, "\t");
        strcat(record, &current->gender);
            strcat(record, "\t");
        strcat(record, number_to_string(current->age));
            strcat(record, "\t");
        strcat(record, current->group);
            strcat(record, "\t");
        // strcat(record, number_to_string(current->math_score));
        //     strcat(record, "\t");
        // strcat(record, number_to_string(current->physics_score));
        //     strcat(record, "\t");
        // strcat(record, number_to_string(current->chemistry_score));

        strcat(record, "\n");

        student = student->next;
    }

    printf("%s", record);
}