# include "Core/Application/file_context.h"
# include "Core/Application/node_list.h"
# include "Core/Domain/student.h"
# include "Core/Application/logging.h"

# include "tools/tools.h"

# include <stdlib.h>
# include <string.h>

const char GROUPS_COUNT = 5;
const char GROUP_NAME_COUNT = 3;

const char genders[] = {102, 109}; // [0] = f(female); [1] = m(male)

char input_path[255];

int main() {
    file_context in_stack_context = INIT_FILE_CONTEXT;

    log_settings* log = malloc(sizeof(log_settings));
    log->context = &in_stack_context;

    logging in_stack_logging = INIT_LOGGING;
    logging* logging = &in_stack_logging;

    logging->settings = log;

    strcpy(input_path, ".");

    universal_pointer* meta_into_path = (universal_pointer*) malloc(sizeof(universal_pointer));
    meta_into_path->object = log->context;
    meta_into_path->value = input_path;

    if ( log->context->add_path( meta_into_path ) == -1){
        return -1;
    }

    universal_pointer* logging_register_meta = (universal_pointer*)malloc(sizeof(universal_pointer));
    logging_register_meta->object = logging;

    logging_register_meta->value = logging_console;
    logging->register_log(logging_register_meta);

    logging_register_meta->value = logging_text_file;
    logging->register_log(logging_register_meta);

    // logging_register_meta->value = logging_binary_file;
    // logging->register_log(logging_register_meta);

    char* groups[ GROUPS_COUNT];

    for (int i = 0; i < GROUPS_COUNT; i++)
    {
        groups[i] = get_word((int)GROUP_NAME_COUNT);
    }

    node_list students = INIT_NODE_LIST;

    universal_pointer* students_meta = (universal_pointer*)malloc(sizeof(universal_pointer));
    students_meta->object = &students;

    for (int i = 0; i < 100; i++)
    {
        student* rnd_student = (struct student*)malloc(sizeof(struct student));

        rnd_student->last_name = get_word(6);

        rnd_student->first_name = get_word(5);

        rnd_student->gender = genders[ rand() % 2 ];

        rnd_student->group = groups[ rand() % (GROUPS_COUNT) ];

        rnd_student->math_score =  2 + rand() % 4;
        rnd_student->chemistry_score = 2 + rand() % 4;
        rnd_student->physics_score = 2 + rand() % 4;

        students_meta->value = rnd_student;

        students.add( students_meta );
        // printf("%s\t%s\t%c\t%s\t%d\t%d\n", rnd_student->last_name, rnd_student->first_name, rnd_student->gender, rnd_student->group, rnd_student->math_score, rnd_student->chemistry_score);
    }

    node_list sorted_students = INIT_NODE_LIST;
    node_list* new_sorted = malloc(sizeof(node_list));
    *new_sorted = sorted_students;

    universal_pointer* meta_sorted_students = (universal_pointer*)malloc(sizeof(universal_pointer));
    meta_sorted_students->object = new_sorted;

    node* student = students.head;

    while (student != NULL)
    {
        struct student* current = student->value;

        if (current->chemistry_score == 5 && current->gender == genders[0] ){
            meta_sorted_students->value = current;
            new_sorted->add(meta_sorted_students);
        }
        student = student->next;
    }

    char record[2048];

    student = new_sorted->head;

    while (student != NULL)
    {
        struct student* current = student->value;

        strcat(record, current->last_name);
            strcat(record, "\t");
        strcat(record, current->first_name);
            strcat(record, "\t");
        strcat(record, &current->gender);
            strcat(record, "\t");
        strcat(record, current->group);
            strcat(record, "\t");
        strcat(record, number_to_string(current->math_score));
            strcat(record, "\t");
        strcat(record, number_to_string(current->physics_score));
            strcat(record, "\t");
        strcat(record, number_to_string(current->chemistry_score));

        strcat(record, "\n");

        // free(current);

        student = student->next;
    }

    // printf("%s", record);

    universal_pointer* meta_launch = (universal_pointer*)malloc(sizeof(universal_pointer));
    meta_launch->object = logging;
    meta_launch->value = record;

    universal_pointer* meta_bin_write = (universal_pointer*)malloc(sizeof(universal_pointer));
    meta_bin_write->object = &in_stack_context;
    meta_bin_write->value = new_sorted;

    logging->write_structure( meta_bin_write );

    logging->launch(meta_launch);

    return 0;
}