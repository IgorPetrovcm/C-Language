# include "binary_tree.h"
# include <stdio.h>
# include <stdlib.h>

void add_node(tree* tree, int value)
{
    tree_node* new_node = (tree_node*)malloc(sizeof(tree_node));

    new_node->value = value;
    
    if (tree->head == NULL){
        tree->head = new_node;

        tree->count++;
    }
    else if (tree->head )
}