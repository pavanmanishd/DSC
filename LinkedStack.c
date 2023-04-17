#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct NodeType
{
	int data;
	struct NodeType * link;
};
typedef struct NodeType Node;
struct LinkedStackADT
{
	Node * tos;
};
typedef struct LinkedStackADT Stack;
Stack * create (void)
{
	Stack * pthis;
	//allocating memory for whole
	pthis = (Stack*)malloc(sizeof(Stack));
	//initializing members
	pthis -> tos = NULL;
	//return pthis value
	return pthis;
}
Node * newNode(int data)
{
	Node * pNew;
	//allocating memory for node
	pNew = (Node *) malloc (sizeof(Node));
	//initializing members
	pNew -> data = data;
	pNew -> link = NULL;
	//return value of pthis
	return pNew;
}
bool pop(Stack * pthis , int * pdata)
{
	Node * pDel;
	//validating emptyness
	if(pthis -> tos == NULL)
		return false;
	//logical deletion
	pDel = pthis -> tos;
	*pdata = pDel -> data;
	pthis -> tos = pthis -> tos -> link;
	//physical deletion 
	free(pDel);
	return true;
}
bool push(Stack * pthis , int * pdata)
{
	Node * pDel;
	//validating for emptyness
	if(pthis -> tos == NULL)
		return false;
	//attaching newnode link to top of stack
	pDel -> link = pthis -> tos;
	pthis -> tos = pDel;
	return true;
}
bool peep(Stack * pthis ,int * pdata)
{
	Node * pDel;
	//validating for emptyness
	if(pthis -> tos == NULL)
		return false;
	pDel = pthis -> tos;
	*pdata = pDel -> data;
	return true;
}
void display(Stack * pthis)
{
	Node *  cursor;
	
	printf("Stack is as follows: \n");
	for(cursor = pthis -> tos;cursor != NULL;cursor = cursor -> link)
	{
		printf("[%c]\n",cursor -> data);
		
	}
}
void destroy(Stack * pthis)
{	
	free(pthis);
}
int main(void)
{
	Stack *  ps = create();
	bool res;
	int choice,elem;
	do
	{
		printf("1.push\n2.pop\n3.peep\n4.display\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Enter element : ");
				 scanf("%d",&elem);
				 res = push(ps,&elem);
				 break;
			case 2 : res = pop(ps,&elem);
				 printf("%d got popped\n",elem);
				 break;
			case 3 : res = peep(ps,&elem);
				 printf("%d is peeped element\n",elem);
				 break;
			case 4 : display(ps);
				 break;
		}
	}while(true);
	return 0;	
}
