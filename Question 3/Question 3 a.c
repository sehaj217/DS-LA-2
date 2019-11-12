#include<stdio.h>
#include<string.h>

int main()
{
    char word_ascii[50];
    int ascii[50];
    int i, j, length;

    printf("Enter the word: ");
    scanf("%s", word_ascii);

    for(i=0; word_ascii[i]!='\0'; ++i)
        ascii[i] = word_ascii[i];

    length = strlen(word_ascii);

    for(i=0; i<length; ++i)
        for(j=0; j<length-1; ++j)
        {
            char temp;
            int t;

            if(ascii[j] > ascii[j+1])
            {
                t = ascii[j+1];
                ascii[j+1] = ascii[j];
                ascii[j] = t;

                temp = word_ascii[j+1];
                word_ascii[j+1] = word_ascii[j];
                word_ascii[j] = temp;
            }
        }
    
    printf("The tuple:\n{");
    for(i=0; i<word_ascii[i]!='\0'; ++i)
        printf(" %c:%d,",word_ascii[i],ascii[i]);
    printf("}");

    return 0;
}