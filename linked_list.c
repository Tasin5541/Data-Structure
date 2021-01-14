#include<stdio.h>

void create();
void display();
void rev_traverse();
void insert();
void delete();

struct mystruct
{

    int data;
    struct mystruct *next;

}*first=NULL,*cur=NULL,*last=NULL,*temp=NULL,*temp2=NULL;

int n;

void main()
{
    int cho;

    do
    {
        printf("\n\n\n\t\t\t1.create\n\t\t\t2.Display\n\t\t\t3.rev\n\t\t\t4.Insert\n\t\t\t5.Delete\n\t\t\t6.exit\n\n\n");
        scanf("%d",&cho);
        switch(cho)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            temp=first;
            rev_traverse(temp);
            break;
        case 4:
            insert();
            break;
        case 5:
            delete();
            break;
        }
    }
    while(cho!=6);
}

void create()
{
    int value,i;

    while(value!=-1)
    {
        cur=(struct mystruct*)malloc(sizeof(struct mystruct)) ;
        printf("new value(enter -1 to finish) = ");
        scanf("%d",&value);
        if(value!=-1)
        {
            cur->data=value;

            if(first==NULL)
            {
                first = cur;
            }
            else
            {
                last->next=cur;
            }

            last= cur;
        }
    }
    last->next=NULL;
    printf("Successful\n");
}

void display()
{
    temp=first;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert()
{
    int firstValue,value,insertValue,i,j=0,n;

    printf("enter 1 to insert at start or press 2 to insert after a value : ");
    scanf("%d",&n);
    if(n==1)
    {

        int firstValue;
        cur=(struct mystruct*)malloc(sizeof(struct mystruct)) ;
        printf("Enter a new value for first insert ");
        scanf("%d",&firstValue);
        cur->data=firstValue;
        cur->next=first;
        first=cur;
        printf("First insert successful\n");
    }

    else
    {
        printf("After which value u want to insert ? ");
        scanf("%d",&value);

        temp =first;
        for(i=1; temp!=NULL; i++)
        {
            if(temp->data==value )
            {
                printf("Found at index %d \n",i);

                cur=(struct mystruct*)malloc(sizeof(struct mystruct)) ;
                printf("Enter a new value to insert ");
                scanf("%d",&insertValue);
                cur->data=insertValue;

                temp2=temp->next;

                cur->next=temp2;
                temp->next=cur;

                printf("middle insert success\n");
                j++;
                break;
            }
            else
                temp = temp->next;
        }
        if(j==0)
        {
            printf("Not Found!! \n");

            printf("not possible \n");
        }
    }
}

void delete()
{
    int del,i,j=0;
    if(first==NULL)
        printf("nothing to delete\n");
    else
    {
        printf("enter your delete value \n");
        scanf("%d",&del);
        temp =first;
        for(i=1; temp!=NULL; i++)
        {
            if(first->data==del)
            {
                first = first ->next;
                printf("Found at index %d so delete successful\n",i);
                j++;
                break;
            }
            else
            {
                temp2=temp->next;
                if(temp2->data==del)
                {
                    temp->next = temp2->next;
                    j++;
                    break;
                }

                temp=temp->next;
            }
        }
        if(j==0)
            printf("Not Found!! \n");
    }
}

void rev_traverse(struct mystruct *temp)
{
    int i = 0;


    if (first == NULL)
    {
        printf("empty linked list");
    }
    else
    {
        if (temp->next !=  NULL)
        {
            i = temp->data;
            rev_traverse(temp->next);
            printf("%d->", i);
        }
        if (temp->next == NULL)
        {
            printf("%d->", temp->data);
        }
    }
}
