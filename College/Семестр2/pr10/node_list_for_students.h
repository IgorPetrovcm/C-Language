# ifndef NODE_LIST_FOR_STUDENTS
# define NODE_LIST_FOR_STUDENTS

# include "struct_student.h"

typedef struct node_with_student{
    struct student value;
    struct node_with_student* next;
} node_with_student;

typedef struct node_list{
    node_with_student* head;
    node_with_student* tail;
    int count;
} node_list;

void add_node(node_list* list, struct student* value);

# endif