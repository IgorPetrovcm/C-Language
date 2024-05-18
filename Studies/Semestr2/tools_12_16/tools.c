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
    char* string = &number;

    *string += 48;

    return string;
}