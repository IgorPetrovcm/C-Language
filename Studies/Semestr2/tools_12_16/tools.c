# include "tools.h"

# include <stdio.h> 
# include <stdlib.h> 

char* get_word(int word_length)
{
    char* word = (char*)calloc(word_length, sizeof(char));

    for (int i = 0; i < word_length; i++)
    {
        word[i] = 97 + rand() % 26;
    }

    return word;
}

char* number_to_string(char number)
{
    char* string = calloc(3, sizeof(char));
    int factor = 1000;
    char count = 0;

    while (number != 0)
    {
        *string = number / factor + 48;
        factor /= 10;
        number %= factor;
        string++;
        count++;
    }
    //printf("%c", *(string - 1));
    return string ;
}