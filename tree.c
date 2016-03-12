#include <stdio.h>
#include <stdlib.h>

struct binarytree
{
    int data;
    struct binarytree *left;
    struct binarytree *right;
};

int sum=0;
struct binarytree *node;
void insert(struct binarytree*,int);
int check_leaf(struct binarytree*);
int sumOfLeftLeaves(struct binarytree*);

void insert(struct binarytree *node, int data)
{
    if(node==NULL)
    {
        struct binarytree *node = (struct binarytree*)malloc(sizeof(struct binarytree*));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else 
    {
        if(data <= node->data)              
        {
            insert(node->left,data);
        }
        else                               
        {
            insert(node->right,data);
        }
        return node;
    }
}

int check_leaf(struct binarytree *node)
{
    if(node==NULL)
    {
        return 0;
    }
    if((node->right==NULL) && (node->left==NULL))
    {
        return 1;
    }
    return 0;
    
}

int sumOfLeftLeaves(struct binarytree *root)
{
    sum=0;
    if(root!=0)
    {
        if(check_leaf(root->left))
        {
            sum = sum + root->left->data;
        }
        else
        {
            sum = sum + sumOfLeftLeaves(root->right);
        }
        sum = sum + sumOfLeftLeaves(root->right);
    }
    return sum;
}
int main(void) 
{
    int element;
    printf("Enter the elements...\nEnter 0 to end\n");
    scanf("%d",&element);
    while(element!=0)
    {
        insert(&node,element);
        scanf("%d",&element);
    }
    printf("\nThe sum of left leaves %d",sumOfLeftLeaves(node));
    
    return 0;
}

