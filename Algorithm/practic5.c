#include "stdio.h"
int main() 
{
    int arrSize = rand()%11;
    int countSortedValues = 0;

    int arrNonSorted[arrSize];
    int arrSorted[arrSize];
    for (int i = 0; i < arrSize; i++) 
    {
        arrNonSorted[i] = (rand()%11) + (-3/*диапозон минимума, лежащий в рандомном отрицательном числе*/);
        printf("%d ",arrNonSorted[i]);

        if (arrNonSorted[i] >= 0) {
            arrSorted[countSortedValues] = arrNonSorted[i];
            countSortedValues++;
        }
    }
    for (int i = 0; i < countSortedValues;i++) {
        printf("%d ", arrSorted[i]);
    }

}