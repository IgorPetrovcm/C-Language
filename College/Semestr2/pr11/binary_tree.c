# include "student.h"
# include "binary_tree.h"
# include "node_list_for_students.h"
# include <stdio.h>
# include <stdlib.h>

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
    if ((*current_node) == NULL){

        *current_node = (tree_node*)malloc(sizeof(tree_node)) ;

        (*current_node)->right = (tree_node**)malloc(sizeof(tree_node));
        (*current_node)->left = (tree_node**)malloc(sizeof(tree_node));

        *(*current_node)->right = NULL;
        *(*current_node)->left = NULL;

        (*current_node)->value = node->value;
    }
    else if (node->value->assessment_by_chemistry > (*current_node)->value->assessment_by_chemistry){
        adding_node((*current_node)->right, node);
    }
    else {
        adding_node((*current_node)->left, node);
    }
}

node_list* get_students(tree* tree)
{   
    if (tree->head == NULL){
        return NULL; 
    }

    node_list result = {.head = NULL, .tail = NULL};
    node_list* to_nodes = &result; 

    add_node_in_list(to_nodes, tree->head->value);

    geting_students(to_nodes, tree->head->left);

    geting_students(to_nodes, tree->head->right);

    return to_nodes;
}

void geting_students(node_list* students, tree_node** node)
{
    if (*node == NULL){
        return;
    }

    add_node_in_list(students, (*node)->value);

    geting_students(students, (*node)->left); 

    geting_students(students, (*node)->right); 

    return;
}

node_list* get_students_with_fields_for_task(tree* tree)
{
    if (tree->head == NULL){
        return NULL;
    }

    node_list result = {.head = NULL, .tail = NULL};

    node_list* to_nodes = &result;

    if (tree->head->value->assessment_by_chemistry == 5 && tree->head->value->gender == 1){
        add_node_in_list(to_nodes, tree->head->value);
    } 
    
    geting_students_with_fields_for_task(to_nodes, tree->head->left);

    geting_students_with_fields_for_task(to_nodes, tree->head->right);

    return to_nodes;
}

void geting_students_with_fields_for_task(node_list* students, tree_node** node)
{
    if (node == NULL){
        return;
    }

    printf("%d", (*node)->value->gender);


    if ((*node)->value->assessment_by_chemistry == 5 && (*node)->value->gender == 1){
            printf("F");

        add_node_in_list(students, (*node)->value);
    }

    geting_students_with_fields_for_task(students, (*node)->left);

    geting_students_with_fields_for_task(students, (*node)->right);
}

