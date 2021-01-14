#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char t[5][100]= {"0","0","0","0","0",};
int link[5]= {-1,-1,-1,-1,-1};
bool found=false;

void insert(int key,char *name)
{
    int loc,i,prev,free=4;
    loc=key%5;
    if(strcmp(t[loc],"0"))
    {
        i=loc;
        while(!found || i!=-1)
        {
            if(!strcmp(t[i],name))
                found=true;
            else
            {
                prev=i;
                i=link[i];
            }
        }
    }

    if(!found)
    {
        if(!strcmp(t[loc],"0"))
            strcpy(t[loc],name);
        else
        {
            while(!strcmp(t[free],"0") || free!=-1)
            {
                free=free-1;
            }
            if(free=-1)
                printf("overflow");
            else
            {
                strcpy(t[free],name);
                link[prev]=free;
                link[free]=-1;
            }
        }
    }
}

void display()
{
    int i;
    for(i=0; i<5; i++)
    {
        if(strcmp(t[i],"0"))
        {
            printf("\nData at index %d in Hash Table:\n", i);
            printf("%s",t[i]);
        }
    }
}
void main()
{
    char name[100],i,key=0,ch;

    while(1)
    {
        printf("\n1. Insertion\t2. Searching\n");
        printf("3. Display\t4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        getchar();

        switch (ch)
        {
        case 1:
            key=0;
            printf("enter a name : ");
            scanf("%[^\n]s",name);
            getchar();

            for(i=0; i<strlen(name); i++)
                key=key+name[i];

            insert(key,name);
            break;

        case 2:
            key=0;
            printf("Enter the name to search:");
            scanf("%[^\n]s",name);

            for(i=0; i<strlen(name); i++)
                key=key+name[i];

            insert(key,name);
            if(!found)
                printf("\nnot found");
            if(found)
                printf("found");
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        default:
            printf("U have entered wrong option!!\n");
            break;
        }
    }
}
