# include "student.h"
# include "binary_tree.h"
# include <stdio.h>
# include <stdlib.h>

void add_node(tree* tree, struct student* value)
{
    tree_node* new_node = (tree_node*)malloc(sizeof(tree_node));

    new_node->value = value;
    
    if (tree->head == NULL){
        tree->head = new_node;

        tree->count++;
    }
    else if (value->assessment_by_chemistry> tree->head->value->assessment_by_chemistry){
        tree->head->right = adding_node(tree->head->right, new_node);
    }
    else {
        tree->head->left = adding_node(tree->head->left, new_node);
    }

    tree->count++;
}

tree_node* adding_node(tree_node* current_node, tree_node* node)
{
    if (current_node == NULL){
        current_node = node;
    }
    else if (node->value->assessment_by_chemistry > current_node->value->assessment_by_chemistry){
        current_node->right = adding_node(current_node->right, node);
    }
    else {
        current_node->left = adding_node(current_node->left, node);
    }
    return current_node;
}

struct student* get_students(tree* tree)
{
    if (tree->head == NULL){
        return NULL; 
    }

    int size_result = sizeof(struct student);

    struct student* result = (struct student*)malloc(size_result);

    *result = *tree->head->value;

    size_result += sizeof(struct student);

    realloc(result, size_result);

    result++;

    size_result = geting_students(&result, size_result, tree->head->left);

    size_result = geting_students(&result, size_result, tree->head->right);

    return result;
}

int geting_students(struct student** students, int size_students, tree_node* node)
{
    if (node == NULL){
        return size_students;
    }

    *students = node->value;

    size_students += sizeof(struct student);

    realloc(*students, size_students);

    *students++;

    size_students = geting_students(&*students, size_students, node->left); 

    size_students = geting_students(&*students, size_students, node->right); 

    return size_students;
}
