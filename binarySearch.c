#include<stdio.h>
#include<time.h>

int ar1[5000];

void view();
int linear(int data);
void sort();
int binary(int data);

void main()
{
    int i,data,index1,index2,show,e;

    for(i=0; i<5000; i++)
    {
        ar1[i]=rand()%5000;
    }

    sort();

    printf("press 1 to see the array or 2 to continue : ");
    scanf("%d",&show);

    if(show==1)
        view();

    while(e!=3)
    {
        printf("\n\t\t\t1.LINEAR SEARCH\t\t\t2.BINARY SEARCH\n\t\t\t3.EXIT\n");
        scanf("%d",&e);

        if(e==1)
        {
            printf("\nLINEAR SEARCH : ");

            printf("\n\nenter the data to search : ");
            scanf("%d",&data);

            index1=linear(data);

            if(index1==-1)
                printf("\ndata not found!!\n");
            else
                printf("\ndata found at index %d\n",index1);
        }
        if(e==2)
        {
            printf("\n\nBINARY SEARCH : ");

            printf("\n\nenter the data to search : ");
            scanf("%d",&data);
            index2=binary(data);

            if(index2==-1)
                printf("\ndata not found!!\n");
            else
                printf("\ndata found at index %d\n",index2);
        }
    }
}

void view()
{
    int i;
    for(i=0; i<5000; i++)
    {
        printf("%d\n",ar1[i]);
    }
}

int linear(int data)
{
    int i,index=-1;
    for(i=0; i<5000; i++)
    {
        if(data==ar1[i])
            return i;
    }
    return index;
}

void sort()
{
    int i,j,k,temp;

    for(j=5000; j>0; j--)
    {
        for(k=0; k<(j-1); k++)
        {
            if(ar1[k]>ar1[k+1])
            {
                temp=ar1[k+1];
                ar1[k+1]=ar1[k];
                ar1[k]=temp;
            }
        }
    }
}

int binary(int data)
{
    int lowerBound = 0;
    int upperBound = 5000 -1;
    int midPoint = -1;
    int index2 = -1;

    while(lowerBound <= upperBound)
    {
        midPoint = lowerBound + (upperBound - lowerBound) / 2;

        if(ar1[midPoint] == data)
        {
            index2 = midPoint;
            break;
        }
        else if
        (ar1[midPoint] < data)
        {
            lowerBound = midPoint + 1;
        }
        else
        {
            upperBound = midPoint -1;
        }
    }
    return index2;
}
