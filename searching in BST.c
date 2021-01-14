#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

typedef struct node BST;
BST *LOC, *PAR;
void search(BST *root, int item)
{
    BST *save,*ptr;
    if (root == NULL)
    {
        LOC = NULL;
        PAR=NULL;
    }
    if (item == root -> key)
    {
        LOC = root;
        PAR = NULL;
        return;
    }
    if (item < root->key)
    {
        save = root;
        ptr = root->left;
    }
    else
    {
        save = root;
        ptr = root -> right;
    }
    while( ptr != NULL)
    {
        if (ptr -> key == item)
        {
            LOC = ptr;
            PAR = save;
            return;
        }
        if(item < ptr->key)
        {
            save = ptr;
            ptr = ptr->left;
        }
        else
        {
            save = ptr;
            ptr = ptr->right;
        }
    }
    LOC = NULL;
    PAR = save;
    return;
}

int main()
{
    int ar[6]= {30,20,40,70,60,80},i,element;

    struct node *root = NULL;
    root = insert(root, 50);

    for(i=0; i<6; i++)
        insert(root, ar[i]);

    printf("Enter element to be searched:  ");
    scanf("%d", &element);
    search(root, element);
    if(LOC != NULL)
        printf("\n%d Found in Binary Search Tree !!\n",element);
    else
        printf("\nIt is not present in Binary Search Tree\n");

    return 0;
}
