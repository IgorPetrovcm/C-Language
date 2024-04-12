# include <stdio.h>
# include <stdlib.h>

void task(int* ptr);

int main()
{
    int const array_length = 5;

    int* array = (int *)calloc(array_length, sizeof(int));

    for (int i = 0; i < array_length; i++)
    {
        array[i] = 1 + rand() % 50;
    }

    task(array);

    free(array);
}

void task(int* ptr)
{
    int size_sorted_arrray = sizeof(int);
    int* sorted = (int*)malloc(size_sorted_arrray);

    int loop_count = 0;

    int j = 0;

    int i = 0;

    while (*ptr != 0)
    {
        if (*ptr % 2 == 0){
            sorted[j] = *ptr;

            size_sorted_arrray += sizeof(int);

            sorted = realloc(sorted, size_sorted_arrray);

            j++;
        }

        ptr++;
    }

    int* start = sorted;

    for (int i = 0; i < (size_sorted_arrray - sizeof(int)) / sizeof(int); i++)
    {
        printf("%d\n", sorted[i]);
    }

    free(sorted);
}