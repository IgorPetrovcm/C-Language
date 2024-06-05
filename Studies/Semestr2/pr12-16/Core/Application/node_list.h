#ifndef NODE_LIST_H
#define NODE_LIST_H

# include "universal_pointer.h"

typedef struct node {
    void *value;
    struct node *next;
} node;

typedef struct node_list {
    node* head;
    node* tail;

    void (*add) ( universal_pointer* value );
} node_list;

void add( universal_pointer* value );

# define INIT_NODE_LIST {.head = NULL, .tail = NULL, .add = add}

#endif //NODE_LIST_H
