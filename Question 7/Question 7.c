#include<stdio.h>
#include<stdlib.h>

struct node
{
    char status;
    int spin_count;
    struct node *next;
};

struct node *createnode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->status = 'E';
    temp->spin_count = 0;
    temp->next = NULL;
    return temp;
}

struct node *make(struct node *merry)
{
    struct node *temp;
    temp = createnode();

    if(merry == NULL)
    {
        merry = temp;
        merry->next = merry;
    }
    else
    {
        struct node *p;
        p = merry;
        while(p->next != merry)
            p = p->next;
        p->next = temp;
        temp->next = merry;
    }
    return merry;
}

struct node *ridefinished(struct node *merry)
{
    struct node *finish;
    finish = merry;
    do
    {
        if(finish->spin_count >= 120)
            {
                finish->status = 'E';
                finish->spin_count = 0;
            }
        finish = finish->next;
    }while(finish!=merry);
    return merry;
}

void display(struct node *merry)
{
    ridefinished(merry);
    struct node *display;
    display = merry;
    printf("\n************\nRide Status:\n************\nSeats:\n");
    do{
        printf("%c\t", display->status);
        display = display->next;
    }while(display!=merry);
    printf("\nSpin count:\n");
    do{
        printf("%d\t", display->spin_count);
        display = display->next;
    }while(display!=merry);
    printf("\n");
}

struct node *addcustomer(struct node *merry)
{
    ridefinished(merry);
    int count=0;
    struct node *add;
    add = merry;

    do
    {
        if(add->status == 'E')
        {
            add->status = 'F';
            goto out;
        }
        else
            count++;
        add->spin_count++;
        add = add->next;
    }while (count != 12);
    
    out:
    if(count == 12)
        printf("Sorry the merry-go-round is full\n");
    else
        printf("Enjoy your ride!\n");
    
    return merry;
}

struct node *fullspin(struct node *merry)
{
    ridefinished(merry);
    struct node *temp;
    temp = merry;
    do
    {
        if(temp->status == 'F')
            temp->spin_count += 12;
        temp = temp->next;
    } while (temp!=merry);
    return merry;
}

int main()
{
    int i;
    struct node *merry = NULL;
    int ch;
    char choice;

    //Creating the Merry-Go-Round
    for(i=0;i<12;++i)
        merry = make(merry);

    do
    {
        printf("\nRide options:\n1.Get in the ride\n2.Check status\n3.Spin the ride\n[1/2/3]: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: merry = addcustomer(merry);
                    break;

            case 2: display(merry);
                    break;
            
            case 3: merry = fullspin(merry);
                    break;

            default:printf("\nWrong option\n");
                    break;
        }
        printf("Continue? [Y/N]: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}