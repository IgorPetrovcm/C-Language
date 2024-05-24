# ifndef NODE_LIST
# define NODE_LIST

# include "node.h"

typedef struct node_list{
    node* head;
    node* tail;
    int count;

    void (*add) (void*);
} node_list;

typedef struct node_list_meta{
    node_list* list;
    void* value;
} node_list_meta;

void add(void*);

# define INIT_NODE_LIST {.head = NULL, .tail = NULL, .add = add}

# endif