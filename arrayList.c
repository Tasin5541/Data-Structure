#include<stdio.h>

void insert();
void search();
void delete();

#define max 5
int ar[max],link[max],i=0,k=0;

void main()
{
    int n,s,d,c;

    while(1)
    {
        printf("\t\t\t\t1.insert\n\t\t\t\t2.search\n\t\t\t\t3.delete\n\t\t\t\t4.exit");
        printf("\nenter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            insert();
            break;

        case 2:
            search();
            break;

        case 3:
            delete();
            break;

        case 4:
            exit(0);
        }
    }
}

void insert()
{
    int n;

    if(i==max)
        printf("\noverflow\n\n");
    else
    {
        printf("\nenter an integer : ");
        scanf("%d",&n);

        ar[i]=n;
        link[i]=-1;
        if(i>0)
            link[i-1]=i;

        i++;
    }
}

void search()
{
    int n,j=k;

    if(k==-1 || link[j]==NULL)
    {
        printf("\narray empty\n\n");
    }
    else
    {
        printf("\nenter number to search : ");
        scanf("%d",&n);

        while(j!=-1)
        {
            if(ar[j]==n)
            {
                printf("\nfound %d at index %d\n\n",n,j);
                break;
            }
            j=link[j];
        }
        if(j==-1)
        {
            printf("\nnot found!!\n\n");
        }
    }
}

void delete()
{
    int n,j=k;

    if(link[j]==NULL)
    {
        printf("\narray empty\n\n");
    }
    else
    {
        printf("\nenter number to delete : ");
        scanf("%d",&n);

        while(j!=-1)
        {
            if(ar[j]==n)
            {
                if(j==0)
                    k=link[j];
                else
                    link[j-1]=link[j];
                printf("\nfound %d at index %d and deleted\n\n",n,j);
                break;
            }
            j=link[j];
        }
        if(j==-1)
        {
            printf("\nnot found!!\n\n");
        }
    }
}
