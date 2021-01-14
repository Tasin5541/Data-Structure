#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hash *hashTable = NULL;
int eleCount = 0;

struct node {
    int key, age;
    char name[100];
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};

struct node * createNode(int key, char *name, int age) {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->age = age;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

void insertToHash(int key, char *name, int age) {
    int hashIndex = key % eleCount;
    struct node *newnode = createNode(key, name, age);
    if (!hashTable[hashIndex].head) {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    newnode->next = (hashTable[hashIndex].head);

    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}

void searchInHash(int key) {
    int hashIndex = key % eleCount, flag = 0;
    struct node *myNode;
    myNode = hashTable[hashIndex].head;
    if (!myNode) {
        printf("Search element unavailable in hash table\n");
        return;
    }
    while (myNode != NULL) {
        if (myNode->key == key) {
            printf("Name     : %s\n", myNode->name);
            printf("Age      : %d\n", myNode->age);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("Search element unavailable in hash table\n");
    return;
}

void display() {
    struct node *myNode;
    int i;
    for (i = 0; i < eleCount; i++) {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
        printf("\nData at index %d in Hash Table:\n", i);
        printf("Name          Age   \n");
        printf("--------------------\n");
        while (myNode != NULL) {
            printf("%-15s", myNode->name);
            printf("%d\n", myNode->age);
            myNode = myNode->next;
        }
    }
    return;
}

int main() {
    int n, ch, key=0, age, i;
    char name[100];
    printf("Enter the number of elements:");
    scanf("%d", &n);
    eleCount = n;
    hashTable = (struct hash *) calloc(n, sizeof(struct hash));
    while (1) {
        printf("\n1. Insertion\t2. Searching\n");
        printf("3. Display\t4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        getchar();
        switch (ch) {
        case 1:
            key=0;

            printf("Name:");
            scanf("%[^\n]s",name);

            for(i=0;i<strlen(name);i++)
                key=key+name[i];

            printf("Age:");
            scanf("%d", &age);
            insertToHash(key, name, age);
            break;

        case 2:
            key=0;
            printf("Enter the name to search:");
            scanf("%[^\n]s",name);

            for(i=0;i<strlen(name);i++)
                key=key+name[i];
            searchInHash(key);
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
    return 0;
}
