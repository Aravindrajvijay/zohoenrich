#include <stdio.h>
void insert(struct binarytree**,int);

struct binary_tree
{
	int node;
	struct binary_tree *left;
	struct binary_tree *right;
};

struct binarytree *node;

void insert(struct binarytree **node, int data)
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

void inorder(struct binarytree *node)
{
	if(node!=0)
	{
		inorder(node->left);
		printf("%d",node->data);
		inorder(node->right);
	}
}

void preorder(struct binarytree *node)
{
	if(node!=0)
	{
		printf("%d",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(struct binarytree *node)
{
	if(node!=0)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d",node->data);

	}
}

void removal()
{
	
}

int main()
{
	int element;
	printf("Enter the elements....Enter 0 to stop");
	scanf("%d",&element);
	while(element)
	{
		insert(&node,element);
		scanf("%d",&element);
	}
}
