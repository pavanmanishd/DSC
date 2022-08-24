#include<stdio.h>
#include<stdlib.h>
struct BSTreeNode
{
	struct BSTreeNode * lsTree;
	struct BSTreeNode * rsTree;
	int data;
};
typedef struct BSTreeNode BSTNode;
BSTNode * newNode(int data)
{
	BSTNode * pNew = NULL;
	pNew = (BSTNode*)malloc(sizeof(BSTNode));
	if(pNew==NULL)
	{
		perror("malloc");
		exit(1);
	}
	pNew -> data = data;
	pNew -> lsTree = NULL;
	pNew -> rsTree = NULL;
	return pNew;
}
BSTNode * insert(BSTNode * root,int elem)
{
	if(root == NULL)
		root =  newNode(elem);
	else if(elem < root->data)
		root -> lsTree = insert(root -> lsTree,elem);
	else if(elem> root-> data)
		root -> rsTree = insert(root -> rsTree,elem);
	return root;
}
BSTNode * FindMin(BSTNode * root)
{
	BSTNode * cursor;
	if(root == NULL)
		return NULL;
	cursor = root;
	while(NULL != cursor -> lsTree)
	{
		cursor = cursor -> lsTree;	
	}
	return cursor;
}
BSTNode * delete(BSTNode * root,int elem)
{
	BSTNode * pDel;
	BSTNode * minrs;
	//if root is NULL
	if(root == NULL)
		return NULL;
	//if elem is root
	if(elem == root -> data)
	{
		//root may be leaf
		if(root->lsTree == NULL && root->rsTree == NULL)
		{
			pDel = root;
			root = NULL;
			free(pDel);
			return root;
		}
		//root have one child left sub tree
		else if(root->lsTree != NULL && root->rsTree == NULL)
		{
			pDel = root;
			root = root->lsTree;
			free(pDel);
			return root;
		}
		//root have one child right sub tree
		else if(root->lsTree == NULL && root->rsTree != NULL)
		{
			pDel = root;
			root = root -> rsTree;
			free(pDel);
			return root;
		} 
		//root have two childs
		else if(root->lsTree != NULL && root->rsTree != NULL)
		{	
			pDel = root;
			minrs = FindMin(root -> rsTree);
			root -> data = minrs -> data;
			root -> rsTree = delete(root->rsTree,minrs->data);
			return root;
		}
	}
	if(elem < root -> data)
		root->lsTree = delete(root->lsTree,elem);
	if(elem > root -> data)
		root->rsTree = delete(root->rsTree,elem);
	return root;
}
void inOrder(BSTNode * root)
{
	if(NULL!=root)
	{
		inOrder(root->lsTree);
		printf("%4d",root->data);
		inOrder(root->rsTree);
	}
}
BSTNode * Search(BSTNode*root,int key)
{
	BSTNode * cursor = root;
	while(cursor!=NULL)
	{
		if(cursor->data == key)
			return cursor;
		else if(cursor->data > key)
			cursor = cursor->lsTree;
		else if(cursor -> data<key)
			cursor = cursor -> rsTree;
	}
	return NULL;
}
int main(void)
{
	int key;
	BSTNode * root = NULL;
	root = insert(root,7);
	root = insert(root,4);
	root = insert(root,6);
	root = insert(root,9);
	root = insert(root,55);	
	root = insert(root,1);
	root = insert(root,3);
	root = insert(root,10);
	root = insert(root,5);
	inOrder(root);
	
	int delElem;
	printf("Enter element to delete: ");
	scanf("%d", &delElem);
	root = delete(root, delElem);
	inOrder(root);
	printf("\nEnter a element to search : ");
	scanf("%d",&key);
	BSTNode * res;
	res = Search(root,key);
	if(NULL!=res)
		printf("\nKey found\n");
	else	
		printf("\nKey not found\n");
	return 0;
}
