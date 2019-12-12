#include<stdio.h>
#include<stdlib.h>
struct tree {
    int key;             
    struct tree *left;  
    struct tree *right; 
};
typedef struct tree* treePtr;
treePtr root = NULL;
treePtr newNode(int n)
{
	treePtr ptr=root;
	if(root==NULL)
	{
		root=(treePtr)malloc(sizeof(struct tree));
		root->key=n;
		root->left=NULL;
		root->right=NULL;
		return 0 ;
	}
	while(ptr!=NULL)
	{
		if(ptr->key<n)
		{
			if(ptr->left==NULL)
			{
				ptr->left=(treePtr)malloc(sizeof(struct tree));
				ptr=ptr->left;
				break;
			}
			ptr=ptr->left;
		}
		else if(ptr->key>n)
		{
			if(ptr->right==NULL)
			{
				ptr->right=(treePtr)malloc(sizeof(struct tree));
				ptr=ptr->right;
				break;
			}
			ptr=ptr->right;
		}
		else
		{
			return 0;
		}
	}
	ptr->key=n;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
} 
int add(int n);
void inorder(treePtr ptr)
{
	if(ptr==NULL)
	{
		return ;
	}
	inorder(ptr->right);
	printf("%d ",ptr->key);
	inorder(ptr->left);
} 
void inordertwo(treePtr ptr)
{
	if(ptr==NULL)
	{
		return ;
	}
	printf("%d ",ptr->key);
	inordertwo(ptr->right);
	inordertwo(ptr->left);
} 
int main()
{
	
	int numb;
	treePtr ptr;
	while(1)
	{
		scanf("%d",&numb);
			if(numb<0)
		break;
		newNode(numb);
	
	}
	inordertwo(root);
} 
