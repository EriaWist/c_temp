#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int isEmpty(int top)
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int isFull(int top)
{
	if(top>=MAX)
	return 1;
	else
	return 0;
}
int pop(char stack[],int* top)
{
    if(isEmpty(*top))
        printf("堆疊已空!\n");
    else
        return stack[(*top)--];
}
void push(char stack[],int* top,char item)
{
    if(isFull(*top))
        printf("堆疊已滿!\n");
    else
        stack[++(*top)]=item;
}
struct tree {
    int key;             
    struct tree *left;  
    struct tree *right; 
    struct tree *back;//test
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
		root->back=NULL;
		return 0 ;
	}
	while(ptr!=NULL)
	{
		if(ptr->key<n)
		{
			if(ptr->left==NULL)
			{
				ptr->left=(treePtr)malloc(sizeof(struct tree));
				ptr->left->back=ptr;
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
				ptr->right->back=ptr;
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
	char stark[100]={'/0'};
	if(ptr==NULL)
	{
		return ;
	}
	printf("%d ",ptr->key);
	inordertwo(ptr->right);
	inordertwo(ptr->left);
} 
void del_inorder(int numb,treePtr ptr)
{
	if(ptr==NULL)
	{
		return ;
	}
	del_inorder(numb,ptr->right);
	if(numb==ptr->key)
	{
		treePtr temp=ptr;
		if(temp->left==NULL&&temp->right==NULL)
		{
			if(ptr->back->right==ptr)
			{
				ptr->back->right=ptr->right;
			}
			else if(ptr->back->left==ptr)
			{
				ptr->back->left=ptr->left;
			}
			free(ptr);
		}
		else if(ptr->right!=NULL)
		{
			ptr=ptr->right;
			while(1)
			{
				if(ptr->left==NULL)
				{
					temp->key=ptr->key;
					if(ptr->back==temp)
					{
						temp->right=ptr->right;
					}
					else
					{
						ptr->back->left=ptr->left;
					}
					free(ptr);
					return ;
				}
				ptr=ptr->left;
			}
		}
		else if(ptr->left!=NULL)
		{
			ptr=ptr->left;
			while(1)
			{
				if(ptr->right==NULL)
				{
					temp->key=ptr->key;
					if(ptr->back==temp)
					{
						temp->left=ptr->left;
					}
					else
					{
						ptr->back->right=ptr->right;
					}
					free(ptr);
					return ;
				}
				ptr=ptr->right;
			}
		}
		return ;
	}
	del_inorder(numb,ptr->left);
}
void del(int numb)
{
	treePtr ptr=root;
	if(numb==root->key)
	{
		
		if(ptr->left==NULL&&ptr->right==NULL)
		{
			root=NULL;
		}
		else if(ptr->right!=NULL)
		{
			ptr=ptr->right;
			while(1)
			{
				if(ptr->left==NULL)
				{
					root->key=ptr->key;
					if(ptr->back==root)
					{
						root->right=ptr->right;
					}
					else
					{
						ptr->back->left=ptr->left;
					}
					
					free(ptr);
					return ;
				}
				ptr=ptr->left;
			}
		}
		else if(ptr->left!=NULL)
		{
			ptr=ptr->left;
			while(1)
			{
				if(ptr->right==NULL)
				{
					root->key=ptr->key;
					if(ptr->back==root)
					{
						root->left=ptr->left;
					}
					else
					{
						ptr->back->right=ptr->right;
					}
					free(ptr);
					return ;
				}
				
				ptr=ptr->right;
			}
		}
		return ;
	}
	else
	{
		del_inorder(numb,ptr);
	}
}
int main()
{
	
	int numb,n;
	treePtr ptr;
	while(1)
	{
		scanf(" %d",&n);
		scanf(" %d",&numb);
		if(n==1)
		{
			newNode(numb);
			printf("\n");
			inorder(root);
			printf("\n");
		}
		else if(n==2)
		{
			del(numb);
			printf("\n");
			inorder(root);
			printf("\n");
		}
		
		if(n==0)
		return 0;
	}
	
} 
