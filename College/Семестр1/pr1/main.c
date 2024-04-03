#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *line = "Hello world";

    printf("%d\n", sizeof(line[0]));

    int allsize = 1;


    // char allsize = 1;
    // char *ptr = &line[0];

    // printf("%p\n", (void *)line);

    // printf("%p\n", (void *)ptr);
    // ptr++;
    // printf("%p\n", (void *)ptr);


    // for (int i = 0; i < allsize; i++)
    // {
    //     printf("%c", ptr);
    //     if (ptr == '\0' || NULL){
    //         continue;
    //     }

    //     allsize++;
    //     ptr++;
    // }
}