# include <stdio.h>
# include <stdlib.h>

int main()
{
    int* array = (int *)calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        array[i] = i;
    }

    int size = sizeof(int);

    int* sorted_array = (int *)calloc(1, sizeof(int));

    int j = 0;

    for (int i = 0; i < 5; i++)
    {
        if (array[i] % 2 == 0){
            sorted_array[j] = array[i];

            size += sizeof(int);

            sorted_array = realloc(sorted_array, size);

            j++;
        }
    }
    free(array);

    for (int i = 0; i < size / sizeof(int); i++)
    {
        if (sorted_array[i] == 0) {
            continue;
        }
        printf(" %d\n",sorted_array[i]);
    }

    free(sorted_array);
}