#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct TreeType
{
	int data;
	struct TreeType * plst;
	struct TreeType * prst;
};
typedef struct TreeType Tree;
void Inorder(Tree * root)
{
	if(NULL != root)
	{
		Inorder(root -> plst);
		printf("%d",root -> data);
		Inorder(root -> prst);
	}
}
void Preorder(Tree * root)
{
	if(NULL != root)
	{
		printf("%d",root -> data);
		Preorder(root -> plst);
		Preorder(root -> prst);
	}
}
void Postorder(Tree * root)
{
	if(NULL != root)
	{
		Postorder(root -> plst);
		Postorder(root -> prst);
		printf("%d",root -> data);
	}
}
Tree * newTree(int elem)
{
	Tree * pNew;
	//dynamic memory allocation for whole
	pNew = (Tree*)malloc(sizeof(Tree*));
	//initialize elements
	pNew -> data = elem;
	pNew -> plst = NULL;
	pNew -> prst = NULL;
	return pNew;
}
int main(void)
{
	Tree * root = newTree(1);
	root -> plst = newTree(2);
	root -> prst = newTree(3);
	root -> plst -> plst = newTree(4);
	root -> plst -> prst = newTree(5);
	root -> plst -> plst = newTree(6);
	printf("Inorder expression is : \n");
	Inorder(root);
	printf("\n");
	printf("Preorder expression is : \n");
	Preorder(root);
	printf("\n");
	printf("Postorder expression is : \n");
	Postorder(root);
	printf("\n");
	return 0;
}
