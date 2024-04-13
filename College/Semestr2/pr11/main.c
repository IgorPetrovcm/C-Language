# include "student.h"
# include "binary_tree.h"
# include "node_list_for_students.h"
# include <stdio.h>
# include <stdlib.h>

char* word_generator(int word_length);
void print_word(char* begin_word);


const int nodes_list_count = 100;

const int arr_groupse_length = 6;
const int group_name_length = 5;

const int name_length = 7;

int main()
{
    char* groups_list = calloc(arr_groupse_length, sizeof(char));

    for (int i = 0; i < arr_groupse_length; i++)
    {
        groups_list[i] = *word_generator(group_name_length);
    }

    tree tree = INI;

    for (int i = 0; i < 100; i++)
    {
        struct student* new_student = (struct student*)malloc(sizeof(struct student));

        new_student->last_name = word_generator(name_length);

        new_student->first_name = word_generator(name_length);

        // print_word(new_student->last_name);

        new_student->age = 12 + rand() % 7;

        char gen = (char)rand() % 2;
        if (gen < 0){
            gen = 0;
        }

        new_student->gender = gen;

        new_student->group = &groups_list[rand() % 6];

        new_student->assessment_by_chemistry = (char)2 + rand() % 4;

        new_student->assessment_by_math = (char)2 + rand() % 4;

        new_student->assessment_by_physics = (char)2 + rand() % 4;

        tree.add(&tree, new_student);

    }

    node_list* list_res = tree.get_values_with_fields_for_task(&tree);

    node_with_student* current_node = list_res->head;
    
    while (current_node->next != NULL)
    {   
        print_word(current_node->value.last_name); printf("\t");

        print_word(current_node->value.first_name); printf("\t");

        printf("%d\t", current_node->value.age);

        char* gender_print_v = (char*)calloc(2, sizeof(char));

        if (current_node->value.gender == 0){
            *gender_print_v = 'm';
            *(gender_print_v + 1) = 'a';
        }
        else {
            *gender_print_v = 'f';
            *(gender_print_v + 1) = 'e';
        }

        printf("%c%c\t", *gender_print_v, *(gender_print_v + 1));

        print_word(current_node->value.group); printf("\t");

        printf("%d\t", current_node->value.assessment_by_math);

        printf("%d\t", current_node->value.assessment_by_physics);

        printf("%d\t", current_node->value.assessment_by_chemistry);

        printf("\n");

        current_node = current_node->next;
    }
}

char* word_generator(int word_length)
{
    char* name = (char*)calloc(word_length, sizeof(char));

    for (int i = 0; i < word_length; i++)
    {
        name[i] = 97 + rand() % 26;
    }

    return name;
}

void print_word(char* begin_word)
{
    while (*begin_word != 0)
    {
        printf("%c", *begin_word);
        begin_word++;
    }
}