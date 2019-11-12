#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *next;
	char info;
};
struct node *create_node()
{
	struct node*t;
	t=(struct node*)malloc(sizeof(struct node));
	t->next=NULL;
	return t;
}
struct node *insertnode(struct node *list, char data)
{
	struct node *t, *p;
    t = create_node();

    t->info = data;

    if(list == NULL)
        list = t;
    else
    {
        p = list;
        while(p->next!=NULL)
            p=p->next;
        p->next=t;
    }
    return list;
}

void display(struct node* list)
{
	struct node*t;
	t = list;

	while(t != NULL)
		{	printf("%c ", t->info);
			t=t->next;
		}
		printf("%c ",t->info);
}

void mix_students(struct node *list1, struct node *list2, struct node *list3)
{
	while(list1!=NULL || list2!=NULL)
	{
		list3->info = list1->info;
		list3 = list3->next;

		list3->info = list2->info;

		list1=list1->next;
		list2=list2->next;
		list3=list3->next;
	}
}


int main()
{	int i,j;
	char student;
	struct node* list1=NULL;
	struct node* list2=NULL;
	struct node* list3=NULL;

	printf("Enter the name of students of Primary Grade Students: ");
	for(i=0;i<5; ++i)
	{
		scanf(" %c", &student);
		list1 = insertnode(list1, student);
	}

	printf("Enter the name of the students of High School Students: ");
	for(i=0;i<5; ++i)
	{
		scanf(" %c", &student);
		list2 = insertnode(list2, student);
	}

	for(i=0;i<10;++i)
		list3 = insertnode(list3, '\0');

	mix_students(list1, list2, list3);

	printf("Shuffled Students: ");
	display(list3);

	return 0;
}