# include <stdio.h>

int plus(int a, int b);

int minus(int a, int b);

int division(int a, int b);

int multiplication(int a, int b);

int main () 
{
    int input;

    int (*operations[4]) (int, int) = {plus, minus, division, multiplication};

    do {
        int firstNumber;
        int secondNumber;


        printf("\n1. +\n2. -\n3. /\n4. *\n");
        scanf_s("%d", &input);

        printf("\nPlease, input first number: ");
        scanf_s("%d", &firstNumber);

        printf("\nPlease, input second number: ");
        scanf_s("%d", &secondNumber);

        printf("\n%d", operations[input - 1](firstNumber, secondNumber));
        
    } while (input != 46);
    
}

int plus (int a, int b){
    return a + b;
}

int minus (int a, int b){
    return a - b;
}

int division (int a, int b){
    return a / b;
}

int multiplication (int a, int b){
    return a * b;
}