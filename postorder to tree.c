#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL;

typedef struct btnode N;
void insert();
N* bt(int arr[],int,int);
N* new(int);
void inorder(N *t);
void create();
void search(N *t);
void preorder(N *t);
void postorder(N *t);

void main()
{
    int ch, i, n;

        insert();
        printf("\npreorder traversal of tree\n");
        preorder(root);
        printf("\nInorder traversal of tree\n");
        inorder(root);
        printf("\npostorder traversal of tree\n");
        postorder(root);

}

N* new(int val)
{
    N* node = (N*)malloc(sizeof(N));

    node->value = val;
    node->l = NULL;
    node->r  =  NULL;
    return node;
}

N* bt(int arr[], int first, int last)
{
    int mid;

    N* root = (N*)malloc(sizeof(N));
    if (first > last)
        return NULL;
    mid = (first + last) / 2;
    root = new(arr[mid]);
    root->l = bt(arr, first, mid - 1);
    root->r = bt(arr, mid + 1, last);
    return root;
}

void insert()
{
    int arr1[] = {10, 30, 20, 90, 80, 60, 40}, i;

    printf("Given post order traversal array\n");
    for (i = 0; i <= 6; i++)
    {
        if(i==6)
            printf("%d", arr1[i]);
            else
        printf("%d->", arr1[i]);

    }
    for (i = 6; i >= 0; i--)
    {
        create(arr1[i]);
        if (root == NULL)
            root = temp;
        else
            search(root);
    }
}

void create(int data)
{
    temp = (N *)malloc(1*sizeof(N));

    temp->value = data;
    temp->l = temp->r = NULL;
}

void search(N *t)
{
    if ((temp->value>t->value)&&(t->r != NULL))
        search(t->r);
    else if ((temp->value>t->value)&&(t->r  == NULL))
        t->r = temp;
    else if ((temp->value<t->value)&&(t->l != NULL))
        search(t->l);
    else if ((temp->value<t->value)&&(t->l == NULL))
        t->l = temp;
}

void inorder(N *t)
{
    if (t->l != NULL)
        inorder(t->l);
    printf("%d ", t->value);
    if (t->r != NULL)
        inorder(t->r);
}

void preorder(N *t)
{
    printf("%d ", t->value);
    if (t->l != NULL)
        inorder(t->l);
    if (t->r != NULL)
        inorder(t->r);
}

void postorder(N *t)
{
    if (t->l != NULL)
        inorder(t->l);
    if (t->r != NULL)
        inorder(t->r);
    printf("%d ", t->value);
}
