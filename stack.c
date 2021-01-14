#include<stdio.h>

int end=-1,a[10];

void push();
void pop();

void main()
{
    int shw,i;
    while(shw!=5)
    {
        printf("\nenter a choice : \n");
        printf("\t\t\t1.PUSH\t\t\t2.POP\n\t\t\t3.SIZE\t\t\t4.SHOW\n\t\t\t5.EXIT\n");
        scanf("%d",&shw);
        printf("\n\n\n");
        switch(shw)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("\nthe size of the stack is : %d",end+1);
            break;
        case 4:
            if(end==-1)
                printf("\n\nthe stack is empty\n");
            else
                for(i=end; i>=0; i--)
                {
                    printf("%d\n",a[i]);
                }
            break;
        }
    }
}

void push()
{
    int s;
    if(end==9)
        printf("\n\nstack overflowed");
    else
    {
        printf("\n\nenter a number to push : ");
        scanf("%d",&s);
        end++;
        a[end]=s;
    }
}

void pop()
{
    if(end==-1)
        printf("\n\nthe stack is empty.nothing to pop");
    else
    {
        printf("\n\n%d is popped",a[end]);
        end--;
    }
}
