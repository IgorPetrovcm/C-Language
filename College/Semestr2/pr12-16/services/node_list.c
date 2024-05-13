# include "../domain/business_logic/node_list.h"
# include <stdio.h>

# define INIT_NODE_LIST {.head = NULL, .tail = NULL, }

void add_node(node_list* list, void* value )
{
    node user_node = {.value = value, .next = NULL};

    if (list->head == NULL){
        list->head = &user_node;

        list->tail = &user_node;
    }
    else{
        list->tail->next = &user_node;

        list->tail = &user_node;
    }

    list->count++;
}