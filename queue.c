#include<stdio.h>

int start=0,end=-1,a[10];

void queue();
void dequeue();

void main()
{
    int shw,i;
    while(shw!=5)
    {
        printf("\nenter a choice : \n");
        printf("\t\t\t1.QUEUE\t\t\t2.DEQUEUE\n\t\t\t3.SIZE\t\t\t4.SHOW\n\t\t\t5.EXIT\n");
        scanf("%d",&shw);
        printf("\n\n\n");
        switch(shw)
        {
        case 1:
            queue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("\nthe size of the queue is : %d",end-start+1);
            break;
        case 4:
            if(end==-1)
                printf("\n\nthe queue is empty\n");
            else
                for(i=start; i<=end; i++)
                {
                    printf("%d\n",a[i]);
                }
            break;
        }
    }
}

void queue()
{
    int s;
    if(end==9)
        printf("\n\nqueue full");
    else
    {
        printf("\n\nenter a number to queue : ");
        scanf("%d",&s);
        end++;
        a[end]=s;
    }
}

void dequeue()
{
    if(end==-1)
        printf("\n\nthe queue is empty.nothing to dequeue");
    else
    {
        printf("\n\n%d is dequeued",a[start]);
        start++;
    }
}
