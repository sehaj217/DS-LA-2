#include<stdio.h>
#include<stdlib.h>

struct node
{
    int bun;
    struct node *next;
};

struct node *createbun()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    return temp;
}

struct node *insertbun(struct node *carousel, int bun_id)
{
    struct node *temp;

    temp = createbun();
    temp->bun = bun_id;

    if (carousel == NULL)
    {
        carousel = temp;
        carousel->next = carousel;
    }
    else
    {
        struct node *p;
        p = carousel;

        do
        {
            p=p->next;
        }while(p->next != carousel); 

        p->next = temp;
        temp->next = carousel;  
    }
    return carousel;
}

struct node *pickbun(struct node *carousel)
{
    printf("\nBun Picked!!\n");
    if(carousel->next == carousel)
    {
        carousel = NULL;
    }
    else
    {
        struct node *pick, *last;
        pick = last = carousel;
        do
        {
            last = last->next;
        } while (last->next!=carousel);
        carousel = carousel->next;
        last->next = carousel;
        free(pick);
    }
    return carousel;    
}

void display(struct node *carousel)
{
    struct node *display;
    int hottest;

    display = carousel;
    do{     
        printf("%d\t", display->bun);
        display = display->next;
    }while(display!=carousel);
    printf("\nThe lighted container: %d", display->bun);
}

int main()
{
    struct node *carousel = NULL;
    int ch, id;
    char choice;

    do
    {
        printf("What you want to do?\n1.Bake and put Bun on carousel\n2.Pick bun from carousel\n3.View carousel\n[1/2/3]: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: printf("\nEnter the bun id (barcode): ");
                    scanf("%d", &id);
                    carousel = insertbun(carousel, id);
                    break;

            case 2: if(carousel == NULL)
                        printf("\nCarousel Empty\n");
                    else
                        carousel = pickbun(carousel);
                    break;

            case 3: if(carousel == NULL)
                        printf("\nCarousel Empty\n");
                    else               
                    {
                        printf("The Carousel:\n");
                        display(carousel);
                    }
                    break;

            default: printf("\nWrong choice\n");
                     break;
        }

        printf("\nWant to do anything more? [Y/N]: ");
        scanf(" %c", &choice);

    }while(choice == 'y' || choice == 'Y');

    free(carousel);
    return 0;
}