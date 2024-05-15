# include <stdio.h>
# include <stdlib.h>

int main()
{
    int array[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    int rows_count = sizeof(array) / sizeof(array[0]);
    int columns_count = sizeof(array[0]) / sizeof(array[0][0]);

    int *element = array[0];

    element = array[0];

    int max = *element ; 

    for (int i = 1; i <= rows_count * columns_count; i++)
    {
        if (*element > max){
            max = *element;
        }

        if (i % columns_count == 0){
            printf("%d\n", max);
            max = *(element + 1);
        }

        element++;
    }
    
}