#include "stdio.h"
int main() 
{
    int arrSize = rand()%11;
    int countSortedValues = 0; 

    int *arr = function(arrSize, &countSortedValues);

    for (int i = 0; i < countSortedValues; i++) {
        printf("%d ",arr[i]);
    }

}

int* function(int size, int *count) 
{
    int arrNonSorted[size];
    int arr[size];
    for (int i = 0; i < size; i++) 
    {        
        arrNonSorted[i] = (rand()%11) + (-3);
        printf("%d ",arrNonSorted[i]);

        if (arrNonSorted[i] >= 0) {
            arr[*count] = arrNonSorted[i];
            *count++;
        } 
    }
    return arr;       

}