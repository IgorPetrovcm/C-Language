#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int array_length = rand() % 50;

    int array[array_length];

    int *element = array;

    for (int i = 0; i < array_length; i++)
    {
        *element = (1000 + (rand() % 9001));
        element++;
    }

    for (int i = 0; i < array_length; i++)
    {
        printf("%d\n", *(array + i));
    }

    int max = *array;

    for (int i = 0; i < array_length; i++)
    {
        if (max < *(array + i)){
            max = *(array + i);
        }
    }

    printf("\n%d", max);
}