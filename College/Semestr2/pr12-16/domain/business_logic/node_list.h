# ifndef NODE_LIST
# define NODE_LIST

typedef struct node {
    void* value;
    struct node* next; 
} node;

typedef struct node_list{
    node* head;
    node* tail;
    int count;

    void (*add) (struct node_list* list, void* value);
} node_list;

# endif