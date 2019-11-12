#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->prev=temp->next=NULL;
    return temp;
}

struct node *insert(struct node *s, int element)
{
    struct node *temp,*p;

    temp = create_node();
    temp->data = element;

    if(s == NULL)
        s = temp;
    else
    {
        p=s;
        while(p->next!=NULL)
            p=p->next;
        
        temp->prev = p;
        p->next = temp;
    }

    return s;
}

void process_even(struct node *s1, struct node *s2)
{
    while(s1!=NULL)
    {
        if(s1->data%2 == 0)
        {
            s2->data = s1->data;
            s2=s2->next;
        }
        s1=s1->next;
    }
}

void process_odd(struct node *s1, struct node *s2)
{
    int i;
    for(i=0; i<5; ++i)
            s2=s2->next;
            
    while(s1!=NULL)
    {
        if(s1->data%2 != 0)
        {
            s2->data = s1->data;
            s2=s2->next;
        }

        s1=s1->next;
    }
}

void display(struct node *s)
{
    struct node *temp;
    temp = s;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}


int main()
{
    struct node *start1=NULL, *start2=NULL;
    struct node *temp;
    int i, input;

    printf("Enter ten numbers: ");
    for(i=0;i<10;++i)
    {
        scanf("%d", &input);
        start1 = insert(start1, input);
    }
    
    for(i=0;i<10;++i)
        start2 = insert(start2, -99999);

    process_even(start1, start2);
    process_odd(start1, start2);

    printf("List 1: ");
    display(start1);
    printf("\nList 2: ");
    display(start2);
    return 0;
}
