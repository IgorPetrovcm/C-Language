# include <stdlib.h>
# include <stdio.h>
# include "../Core/Domain/student.h"
# include "../Core/Application/node_list.h"
# include "../Core/Application/universal_pointer.h"

void add( universal_pointer* value ) {
    node_list* list = value->object;

    node* node = (struct node*)malloc(sizeof(node));

    node->value = value->value;

    if ( list->head == NULL ) {
        list->head = node;

        list->tail = node;
    }
    else {
        list->tail->next = node;
        list->tail = node;
    }
}
