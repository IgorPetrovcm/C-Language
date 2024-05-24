# include "../domain/business_logic/node_list.h"
// # include "../domain/model/student.h"
# include <stdio.h>
# include "stdlib.h"

void add( void* meta )
{
    node_list_meta* first_meta = (node_list_meta*)meta;

    node* user_node = (node*)malloc(sizeof(node));

    user_node->value = first_meta->value;

    if (first_meta->list->head == NULL){
        first_meta->list->head = user_node;

        first_meta->list->tail = user_node;
    }
    else{
        first_meta->list->tail->next = user_node;

        first_meta->list->tail = user_node;

        struct student* temp = first_meta->list->head->value;
    }

    first_meta->list->count++;
}
