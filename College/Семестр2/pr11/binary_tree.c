# include "student.h"
# include "binary_tree.h"
# include "node_list_for_students.h"
# include <stdio.h>
# include <stdlib.h>

void print_word2(char* begin_word)
{
    while (*begin_word != 0)
    {
        printf("%c", *begin_word);
        begin_word++;
    }

    printf("\n");
}

void add_node(tree* tree, struct student* value)
{
    tree_node* new_node = (tree_node*)malloc(sizeof(tree_node));

    new_node->value = value;
    
    if (tree->head == NULL){
        tree->head = (tree_node*)malloc(sizeof(tree_node));

        tree->head->left = (tree_node**)malloc(sizeof(tree_node));
        tree->head->right = (tree_node**)malloc(sizeof(tree_node));

        *tree->head->left = NULL;
        *tree->head->right = NULL;

        tree->head->value = new_node->value;
    }
    else if (value->assessment_by_chemistry > tree->head->value->assessment_by_chemistry){
        adding_node(tree->head->right, new_node);
    }
    else {
        adding_node(tree->head->left, new_node);
    }

    tree->count++;
}

void adding_node(tree_node** current_node, tree_node* node)
{
    tree_node* values_for_node = *current_node;

    if (values_for_node == NULL){

        values_for_node = (tree_node*)malloc(sizeof(tree_node)) ;

        values_for_node->right = (tree_node**)malloc(sizeof(tree_node));
        values_for_node->left = (tree_node**)malloc(sizeof(tree_node));

        values_for_node->right = NULL;
        values_for_node->left = NULL;

        values_for_node->value = node->value;
    }
    else if (node->value->assessment_by_chemistry > values_for_node->value->assessment_by_chemistry){
        adding_node(values_for_node->right, node);
    }
    else {
        adding_node(values_for_node->left, node);
    }
}

node_list* get_students(tree* tree)
{   
    if (tree->head == NULL){
        return NULL; 
    }

    node_list result = {.head = NULL, .tail = NULL};
    node_list* nodes = &result; 

    add_node_in_list(nodes, tree->head->value);

    print_word2(tree->head->value->last_name);

    geting_students(nodes, tree->head->left);

    geting_students(nodes, tree->head->right);

    return nodes;
}

void geting_students(node_list* students, tree_node** node)
{
    if (*node == NULL){
        return;
    }

    tree_node* values_for_node = *node;
    printf("f");

    printf("%p", (void*)values_for_node->value);

    print_word2(values_for_node->value->last_name);

    printf("f");

    add_node_in_list(students, values_for_node->value);

    geting_students(students, values_for_node->left); 

    geting_students(students, values_for_node->right); 

    return;
}
