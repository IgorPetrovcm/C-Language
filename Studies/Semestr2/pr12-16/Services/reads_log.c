# include "../Core/Application/reads_log.h"
# include "../Core/Application/file_context.h"
# include "../Core/Application/universal_pointer.h"
# include "../Core/Application/node_list.h"
# include "../Core/Domain/student.h"

# include <string.h>
# include <stdlib.h>

void* read_bin_file( universal_pointer* value, int count ) {
    file_context* context = (file_context*) value->object;

    char path_to_bin[255];
    strcpy(path_to_bin, (char*)value->value);

    context->binary_file_to_write = fopen(
            strcat( path_to_bin, "/output.bin" ),
            "rb"
        );

    node_list* students = (node_list*)malloc(sizeof(node_list));
    int i;

    int size_struct_student = sizeof(struct student);

    for ( int j = 0; j < count; j++) {
        student* student = (struct student*)malloc(size_struct_student);
        char* c = (char*)student;
        while ( (i = getc( context->binary_file_to_write )) != EOF) {
            *c = i;
            c++;
        }

        node* node = (struct node*)malloc(sizeof(node));

        node->value = student;
        universal_pointer* meta_list = (universal_pointer*)malloc(sizeof(universal_pointer));
        meta_list->object = students;
        meta_list->value = node;

        students->add( meta_list );
    }
}