#include "stdio.h"
int main() 
{
    int arrSize = rand()%11;
    int countSortedValues = 0;

    int arrSorted[arrSize] = function(arrSize, &countSortedValues);
    for (int i = 0; i < countSortedValues; i++) {
        printf("%d ",arrSorted[i]);
    }

}

int function(int size, int *count) 
{
    int arrNonSorted[size];
    int arrSorted[size];

    for (int i = 0; i < size; i++) 
    {
        arrNonSorted[i] = (rand()%11) + (-3);
        printf("%d",arrNonSorted[i]);

        if (arrNonsorted[i] >= 0) {
            arrSorted[count] = arrNonSorted[i];
            count++;
        }        
    }
    return arrSorted;
}