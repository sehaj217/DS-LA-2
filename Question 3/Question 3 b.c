#include<stdio.h>
#include<stdlib.h>

struct node {
    char word;
    int ascii;
    struct node *next;
};

struct node *create_node()
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->next = NULL;

    return t;
}

struct node *insert_node(struct node *s, char word)
{
    struct node *t, *p;
    t = create_node();

    t->word = word;
    t->ascii = word;

    if(s == NULL)
        s = t;
    else
    {
        p = s;
        while(p->next!=NULL)
            p=p->next;
        p->next=t;
    }
    return s;
}

void prioritize_list(struct node *list)
{
    struct node *temp;
    int t;
    char tem;

    temp = list;
    temp = temp->next;

    while (temp!=NULL)
    {
        if(list->ascii > temp->ascii)
        {
            t = list->ascii;
            list->ascii = temp->ascii;
            temp->ascii = t;

            tem = list->word;
            list->word = temp->word;
            temp->word = tem;
        }

        list = list->next;
        temp = temp->next;
    }
}

void display(struct node *list)
{
    printf("The tuple:\n{");
    while (list!=NULL)
    {
        if(list->word != '\0')
            printf("%c:%d, ", list->word, list->ascii);
        list = list->next;
    }
    printf("}");
}

int main()
{
    int i, length;
    char letter;
    struct node *list=NULL;

    printf("Enter the word: ");
    for(length=0;;++length)
    {
        letter = getchar();
        if(letter == '\n')
            break;

        list = insert_node(list, letter);
    }

    list = insert_node(list, '\0');
    printf("*");

    for(i=0;i<length;++i)
        prioritize_list(list);

    display(list);

    return 0;
}