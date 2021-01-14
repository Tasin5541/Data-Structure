#include<stdio.h>
#include<time.h>

void sort();

int ar1[9000];
int count=0,swaps=0;

void main()
{
    int i;
    clock_t start,end;
    start=clock();
    sort();


    for(i=0;i<9000;i++)
    {
        printf("%d\n",ar1[i]);
    }
    printf("number of swaps : %d\n",swaps);
    printf("number of data comparisons : %d\n",count);
    end=clock();
    int time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time required %d ms",1000*time);

}

void sort()
{


    int i,j,k,temp;

    for(i=0;i<9000;i++)
    {
       ar1[i]=rand()%9000;
    }
    for(j=9000;j>0;j--)
    {
        for(k=0;k<(j-1);k++)
        {
            if(ar1[k]>ar1[k+1])
            {
                temp=ar1[k+1];
                ar1[k+1]=ar1[k];
                ar1[k]=temp;
                swaps++;
            }
            count++;
        }
    }


}
