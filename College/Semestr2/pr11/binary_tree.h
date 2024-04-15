# ifndef BINARY_TREE_H
# define BINARY_TREE_H

# define INIT_TREE {.head = NULL, .count = 0, .add = add_node, .get_values = get_students, .get_values_with_fields_for_task = get_students_with_fields_for_task}

# include "student.h"
# include "node_list_for_students.h"

typedef struct tree_node {
    struct student* value;
    struct tree_node** left;
    struct tree_node** right;
} tree_node;

tree_node* init_tree_node();

typedef struct tree{
    struct tree_node* head;
    int count;
    void (*add) (struct tree*, struct student*);
    node_list* (*get_values) (struct tree*);
    node_list* (*get_values_with_fields_for_task) (struct tree*);
} tree;

void add_node(tree* tree, struct student* value);

void adding_node(tree_node** node, tree_node* value);

node_list* get_students(tree* tree);

void geting_students(node_list* students, tree_node** node);

node_list* get_students_with_fields_for_task(tree* tree);

void geting_students_with_fields_for_task(node_list* students, tree_node** node);

# endif