# ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include "student.h"

typedef struct tree_node {
    struct student* value;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

typedef struct tree{
    struct tree_node* head;
    int count;
} tree;

void add_node(tree* tree, struct student* value);

tree_node* adding_node(tree_node* node, tree_node* value);

char remove_node(tree* tree, tree_node* node);

char removing_node(tree_node* tree, tree_node* node);

struct student* get_students(tree* tree);

int geting_students(struct student** students, int size_students, tree_node* node);

# endif