# include "../domain/business_logic/node_list.h"
// # include "../domain/model/student.h"
# include <stdio.h>
# include "stdlib.h"

void add(node_list* list, void* value )
{
    node* user_node = (node*)malloc(sizeof(node));

    user_node->value = value;

    if (list->head == NULL){
        list->head = user_node;

        list->tail = user_node;
    }
    else{
        list->tail->next = user_node;

        list->tail = user_node;

        struct student* temp = list->head->value;
    }

    list->count++;
}
