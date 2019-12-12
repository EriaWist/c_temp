#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct tree {
    int key;             
    struct tree *left;  
    struct tree *right; 
    struct tree *back;//test
};
typedef struct tree* treePtr;
treePtr root = NULL;
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
treePtr pop(treePtr stack[],int* top)
{
    if(isEmpty(*top))
        printf("堆疊已空!\n");
    else
        return stack[(*top)--];
}
void push(treePtr stack[],int* top,treePtr item)
{
    if(isFull(*top))
        printf("堆疊已滿!\n");
    else
        stack[++(*top)]=item;
}


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
	treePtr stark[100];
	int top=-1;
  for (;;) {
  	     ptr= pop(stark,&top);  /* 自堆疊刪除節點 */
     if (!ptr) break;  /* 空堆疊 */
     printf("%d ", ptr->key);
     for (; ptr; ptr = ptr->right)
         push(stark,&top,ptr);  /* 將節點加入堆疊 */
     ptr = ptr->left;
  }
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
			inordertwo(root);
			printf("\n");
		}
		else if(n==2)
		{
			del(numb);
			printf("\n");
			inordertwo(root);
			printf("\n");
		}
		
		if(n==0)
		return 0;
	}
	
} 
