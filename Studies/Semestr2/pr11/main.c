# include "student.h"
# include "binary_tree.h"
# include "node_list_for_students.h"
# include <stdio.h>
# include <stdlib.h>

char* word_generator(int word_length);
char* get_string_word(char* begin_word);
char* get_string_number(int number);
char* get_string_student_from_node(node_with_student* node, int* count_symbols);



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

    tree tree = INIT_TREE;

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

    int count_entries = 0;
    
    while (current_node->next != NULL)
    {   
        int count_symbols = 0;
        FILE* bin_file;
        FILE* file;

        char* pr = get_string_student_from_node(current_node, &count_symbols);

        printf("%s", pr);

        if (count_entries == 0){
            file = fopen("task14/result.txt", "w");
            bin_file = fopen("task15/result.bin", "wb");

            count_entries++;
        }
        else {
            file = fopen("task14/result.txt", "a");
            bin_file = fopen("task15/result.bin", "ab");
        }

        fprintf(file, "%s", pr);

        fclose(file);

        fwrite(pr, sizeof(char), count_symbols, bin_file);

        fclose(bin_file);
        
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

char* get_string_word(char* begin_word)
{
    char* string = (char*)malloc(24);

    int count = 0;

    while (*begin_word != 0)
    {
        *string = *begin_word;
        count++;

        string++;
        begin_word++;
    }

    return string - count;
}

char* get_string_number(int number)
{

    char* string = (char*)malloc(10);

    while (number != 0)
    {
        *string = number % 10 + 48;

        number /= 10;

        string++;
    }

    return string - 1;
}

char* get_string_student_from_node(node_with_student* node, int* count_symbols)
{
    char* result = (char*)malloc(365);

    *count_symbols = 0;

    char* temp = get_string_word(node->value.last_name);

    while (!(*temp < 97) && !(*temp > 122))
    {
        *result = *temp;
        result++;
        temp++;

        (*count_symbols)++;
    }

    *result = '\t';
    result++;
    (*count_symbols)++;

    temp = get_string_word(node->value.first_name);

    while (!(*temp < 97) && !(*temp > 122))
    {
        *result = *temp;
        result++;
        temp++;

        (*count_symbols)++;
    }

    *result = '\t';
    result++;
    (*count_symbols)++;

    char* digit = get_string_number(node->value.age);

    while (!(*digit < 48) && !(*digit > 57))
    {
        *result = (char)*digit;
        result++;
        digit--;

        (*count_symbols)++;
    }

    *result = '\t';
    result++;
    (*count_symbols)++;

    char* gender_print_v = (char*)calloc(2, sizeof(char));

    if (node->value.gender == 0){
        *gender_print_v = 'm';
        *(gender_print_v + 1) = 'a';
    }
    else {
        *gender_print_v = 'f';
        *(gender_print_v + 1) = 'e';
    }

    *result = *gender_print_v;
    result++;
    (*count_symbols)++;

    *result = *(gender_print_v + 1);
    result++;
    (*count_symbols)++;

    *result = '\t';
    result++;
    (*count_symbols)++;

    temp = get_string_word(node->value.group);

    while (!(*temp < 97) && !(*temp > 122))
    {
        *result = *temp;
        result++;
        temp++;

        (*count_symbols)++;
    }

    *result = '\t';
    result++;
    (*count_symbols)++;

    digit = get_string_number(node->value.assessment_by_chemistry);

    while (!(*digit < 48) && !(*digit > 57))
    {
        *result = (char)*digit;
        result++;
        digit--;

        (*count_symbols)++;
    }

    *result = '\t';
    result++;
    (*count_symbols)++;

    digit = get_string_number(node->value.assessment_by_physics);

    while (!(*digit < 48) && !(*digit > 57))
    {
        *result = (char)*digit;
        result++;
        digit--;

        (*count_symbols)++;
    }

    *result = '\t';
    result++;
    (*count_symbols)++;

    digit = get_string_number(node->value.assessment_by_math);

    while (!(*digit < 48) && !(*digit > 57))
    {
        *result = (char)*digit;
        result++;
        digit--;

        (*count_symbols)++;
    }

    *result = '\t';
    result++;
    (*count_symbols)++;

    *result = '\n';

    return result - *count_symbols;
}