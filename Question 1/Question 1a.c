#include<stdio.h>

int main()
{
    int i,j=0, array1[10], array2[20];

    printf("Enter ten numbers: ");
    for(i=0;i<10;++i)
        scanf("%d", &array1[i]);

    printf("List 1: ");
    for(i=0;i<10;++i)
        printf("%d ", array1[i]);

    for(i=0;i<10;++i)
        if(array1[i]%2 == 0)
        {
            array2[j]=array1[i];
            ++j;
        }

    for(i=0;i<10;++i)
        if(array1[i]%2!=0)
        {
            array2[j]=array1[i];
            ++j;
        }

    printf("\nList 2: ");
    for(i=0;i<10;++i)
        printf("%d ", array2[i]);

    return 0;
}