# include <stdio.h> 
# include <stdlib.h> 


int main()
{
    char* user_text = (char*)malloc(1024);
    
    FILE* file1 = fopen("textto.txt", "w");

    scanf("%s", user_text);

    fprintf(file1, "%s", user_text);

    fclose(file1);

    char* in_user_text = (char*)malloc(1024);

    file1 = fopen("textto.txt", "r");

    fscanf(file1, "%s", in_user_text);

    printf("\n\n%s", in_user_text);

    fclose(file1);
}