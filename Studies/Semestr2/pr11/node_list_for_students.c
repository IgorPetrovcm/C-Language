# include "student.h"
# include "node_list_for_students.h" 
# include <stdlib.h>
# include <stdio.h>

void add_node_in_list(node_list* list, struct student* value)
{
    node_with_student* new_node = (node_with_student*)malloc(sizeof(node_with_student));

    new_node->value = *value;


    if (list->head == NULL)
    {
        list->head = new_node;

        list->tail = new_node;

        return;
    }

    list->tail->next = new_node;

    list->tail = new_node;

}