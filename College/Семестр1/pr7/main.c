# include <stdio.h>


int main()
{
    char line[] = "Nemo enim ipsam voluptatem, quia voluptas sit. aspernatur aut odit aut fugit. sed quia. consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt. neque porro quisquam est.";

    char* ptr = line;

    int word_count = 0;
    int true_sentence_count = 0;

    for (int i = 0; i < sizeof(line); i++)
    {
        if (*ptr == 32 && *(ptr - 1) != 46){
            word_count++;
        }
        if (*ptr == 46){
            word_count++;
            if (word_count >= 5){
                true_sentence_count++;
            }
            word_count = 0;
        }
        ptr++;
    }

    printf("%d", true_sentence_count);
}