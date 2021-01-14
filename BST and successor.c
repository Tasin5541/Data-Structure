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

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node* find_root(struct node* node, int key)
{

    //i++;
    if(key == node->key)
    {
        inorder(node);
        return node;
    }
    else if (key < node->key)
    {
        node->left  = find_root(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = find_root(node->right, key);
    }
    else
    {
        node=NULL;
        return node;
    }


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

int main()
{
    int ar[6]= {30,20,40,10,60,80},i;

    struct node *root = NULL;
    root = insert(root, 50);

    for(i=0; i<6; i++)
        insert(root, ar[i]);

    printf("Inorder traversal of the subtree : \n\n");
    root=find_root(root,30);

    return 0;
}
