#include<stdio.h>

int main()
{
    int i, j=0, array[10], list[10];

    printf("Enter ten elements: ");
    for(i=0;i<10;++i)
        scanf("%d", &array[i]);

    for(i=0;i<10;i+=2)
    {
        list[j] = array[i];
        ++j;
    }

    for(i=1;i<10;i+=2)
    {
        list[j] = array[i];
        ++j;
    }

    printf("\nModified List: ");
    for(i=0;i<10;++i)
        printf("%d ", list[i]);

    return 0;
}