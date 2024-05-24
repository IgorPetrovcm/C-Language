# ifndef NODE
# define NODE

typedef struct node {
    void* value;
    struct node* next; 
} node;

# endif