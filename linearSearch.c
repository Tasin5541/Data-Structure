#include<stdio.h>

int search(int n);

int ar1[50];

void main()
{
    int i,n,s;

    printf("enter the value to search : ");
    scanf("%d",&n);

    FILE *p;
    p=fopen("search.txt","r");
    for(i=0; i<50; i++)
        fscanf(p,"%d\n",&ar1[i]);
        fclose(p);

        s=search(n);

        if(s>-1)
            printf("\nthe value searched for was found at index %d\n",s);
        else
            printf("\nthe value searched for was not found\n");
}

int search(int n)
{
    int i,s=-1;
    for(i=0; i<50; i++)
    {
        if(n==ar1[i])
            return i;
    }
    return s;
}
