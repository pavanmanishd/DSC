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
