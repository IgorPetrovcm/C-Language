# ifndef BINARY_TREE_H
# define BINARY_TREE_H

typedef struct tree_node {
    int value;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

typedef struct tree{
    struct tree_node* head;
    int count;
} tree;

void add_node(tree* tree, int value);

# endif