#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hash *hashTable = NULL;
int eleCount = 0;

struct node
{
    int key, age;
    //char name[100];
    struct node *next;
};

struct hash
{
    struct node *head;
    int count;
};

struct node * createNode(int key, int age)
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->age = age;
    newnode->next = NULL;
    return newnode;
}

void insertToHash(int key, int age)
{
    int hashIndex=key;
    struct node *newnode = createNode(key,age);
    if (!hashTable[hashIndex].head)
    {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    newnode->next = (hashTable[hashIndex].head);

    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}

void searchInHash(int key,int age)
{
    int hashIndex = key, flag = 0;
    struct node *myNode;
    myNode = hashTable[hashIndex].head;
    if (!myNode)
    {
        printf("Search element unavailable in hash table\n");
        return;
    }
    while (myNode != NULL)
    {
        if (myNode->age == age)
        {
            //printf("Name     : %s\n", myNode->name);
            printf("Age      : %d\nFound at index %d", myNode->age,myNode->key);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("Search element unavailable in hash table\n");
    return;
}

void display()
{
    struct node *myNode;
    int i;
    for (i = 0; i < eleCount; i++)
    {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
        printf("\nData at index %d in Hash Table:\n", i);
        printf("Age   \n");
        printf("-----\n");
        while (myNode != NULL)
        {
            printf("%d\n", myNode->age);
            myNode = myNode->next;
        }
    }
    return;
}

void sum(int key)
{
    struct node *myNode;
    int sum_col=0;
    if (hashTable[key].count == 0)
        printf("\nnothing in the index");
    myNode = hashTable[key].head;
    while (myNode != NULL)
        {
            sum_col+=myNode->age;
            myNode = myNode->next;
        }
        printf("\nsum : %d",sum_col);
}

int main()
{
    int n, ch, key=0, age, i;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    eleCount = n;
    hashTable = (struct hash *) calloc(n, sizeof(struct hash));
    while (1)
    {
        printf("\n1. Insertion\t2. Searching\n");
        printf("3. Display\t4. Sum\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        getchar();
        switch (ch)
        {
        case 1:
            key=0;

            printf("Age:");
            scanf("%d", &age);
            key=age % eleCount;
            insertToHash(key,age);
            break;

        case 2:
            key=0;
            printf("Enter the age to search:");
            scanf("%d", &age);
            key=age % eleCount;
            searchInHash(key,age);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Enter the index to sum:");
            scanf("%d", &key);
            sum(key);
            break;

        case 5:
            exit(0);
        default:
            printf("U have entered wrong option!!\n");
            break;
        }
    }
    return 0;
}
