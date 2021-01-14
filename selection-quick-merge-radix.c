#include<stdio.h>

void sel_sort();
void quick_sort(int st,int end);
void merge_sort(int p,int r);
void merge(int p,int q,int r);
void radix_sort();
int getMax(int n);
void countSort(int n, int exp);

int ar1[100];

void main()
{
    int i,shw;

    while(shw!=5)
    {
        for(i=0; i<100; i++)
        {
            ar1[i]=rand()%800;
        }

        printf("\n\t\t\t1.SELECTION SORT\t\t\t2.QUICK SORT\n\t\t\t3.MERGE SORT\t\t\t\t4.RADIX SORT\n\t\t\t5.EXIT\n");
        scanf("%d",&shw);
        switch(shw)
        {
        case 1:
            sel_sort();
            break;
        case 2:
            quick_sort(0,99);
            break;
        case 3:
            merge_sort(0,99);
            break;
        case 4:
            radix_sort();
            break;
        }

            printf("\n\n\n\n");
        if(shw!=5)
        for(i=0; i<100; i++)
        {
            printf("%d\n",ar1[i]);
        }
    }
}

void sel_sort()
{
    int j,k,t,temp;
    for(j=100-1;j>=1;j--)
    {
        t=0;
        for(k=1;k<=j;k++)
        {
            if(ar1[t]<ar1[k])
                t=k;
        }
        temp=ar1[t];
        ar1[t]=ar1[j];
        ar1[j]=temp;
    }
}

void quick_sort(int st,int end)
{
    int p=ar1[st],i=st+1,j=end,temp,temp2;
    while(i<j)
    {
        while(ar1[i]<p)
            i++;
        while(ar1[j]>p)
            j--;
        if(i<j)
        {
            temp=ar1[j];
            ar1[j]=ar1[i];
            ar1[i]=temp;
        }

    }
    temp2=ar1[j];
    ar1[j]=p;
    ar1[st]=temp2;
    if(st<j-1)
        quick_sort(st,j-1);
    if(j+1<end)
        quick_sort(j+1,end);
}

void merge_sort(int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(p,q);
        merge_sort(q+1,r);
        merge(p,q,r);
    }
}
void merge(int p,int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=ar1[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=ar1[q+j+1];
    }

    i=0;j=0;k=p;
    while (i < n1 && j < n2)

    {
        if(L[i]<R[j])
        {
            ar1[k]=L[i];
            i++;
        }
        else
        {
            ar1[k]=R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        ar1[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        ar1[k] = R[j];
        j++;
        k++;
    }
}

int getMax(int n)
{
    int mx = ar1[0];
    int i;
    for (i = 1; i < 100; i++)
        if (ar1[i] > mx)
            mx = ar1[i];
    return mx;
}
void countSort(int n, int exp)
{
    int output[100];
    int i, count[10] = { 0 };

    for (i = 0; i < 100; i++)
        count[(ar1[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = 100 - 1; i >= 0; i--) {
        output[count[(ar1[i] / exp) % 10] - 1] = ar1[i];
        count[(ar1[i] / exp) % 10]--;
    }

    for (i = 0; i < 100; i++)
        ar1[i] = output[i];
}
void radix_sort()
{
    int m = getMax(100);

    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(100, exp);
}
