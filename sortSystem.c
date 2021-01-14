#include<stdio.h>
#include<time.h>

void bubble_sort();
void insertion_sort();

int ar1[9000],ar2[9000];
int count1=0,swaps1=0;
int count2=0,swaps2=0;

void main()
{
    int i,shw;

    ar1[0]=-1;
    ar2[0]=-1;
    for(i=1; i<9000; i++)
    {
        ar1[i]=rand()%9000;
        ar2[i]=ar1[i];
    }
    clock_t start1,end1;
    start1=clock();
    bubble_sort();
    end1=clock();



    printf("\nBUBBLE SORT : \n");
    printf("number of swaps : %d\n",swaps1);
    printf("number of data comparisons : %d\n",count1);

    double time1=((double)(end1-start1))/CLOCKS_PER_SEC;
    printf("time required %f ms",1000*time1);

    printf("\nenter 1 to display sorted array or 2 to continue : ");
    scanf("%d",&shw);

    if(shw==1)
    {
        for(i=1; i<9000; i++)
        {
            printf("%d\n",ar1[i]);
        }
    }

    clock_t start2,end2;
    start2=clock();
    insertion_sort();
    end2=clock();

    printf("\nINSERTION SORT : \n");
    printf("number of swaps : %d\n",swaps2);
    printf("number of data comparisons : %d\n",count2);

    double time2=((double)(end2-start2))/CLOCKS_PER_SEC;
    printf("time required %f ms",1000*time2);

    printf("\nenter 1 to display sorted array or 2 to continue : ");
    scanf("%d",&shw);

    if(shw==1)
    {
        for(i=1; i<9000; i++)
        {
            printf("%d\n",ar1[i]);
        }
    }

    if(time2>time1)
        printf("\ninsertion sort took %f ms longer\n",1000*(time2-time1));
    else if(time1>time2)
        printf("\nbubble sort took %f ms longer\n",1000*(time1-time2));
    else
        printf("\nboth sorting systems took the same time\n");

}

void bubble_sort()
{


    int i,j=9000,k,t,temp;

    while(j!=0)
    {
        t=0;
        for(k=1; k<j; k++)
        {
            if(ar1[k]>ar1[k+1])
            {
                temp=ar1[k+1];
                ar1[k+1]=ar1[k];
                ar1[k]=temp;
                swaps1++;
                t=k;
            }

            count1++;
        }
        j=t;
    }


}

void insertion_sort()
{
    int i,j,temp;
    for(i=2; i<9000; i++)
    {
        temp=ar1[i];
        swaps2++;
        j=i-1;
        while(temp<ar2[j])
        {
            ar2[j+1]=ar2[j];
            j--;
            count2++;
            swaps2++;
        }
        count2++;
        ar2[j+1]=temp;
        swaps2++;
    }
}
