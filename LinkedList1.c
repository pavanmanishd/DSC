/*Date : 15-06-2022*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct NodeType
{
	int data;
	struct NodeType*link;	
};
typedef struct NodeType Node;
struct LinkedListADT
{
	Node*head;
};
typedef struct LinkedListADT LinkedList;

Node*NewNode(int data)
{
	Node*pNew=NULL;
	//allocate memory for node
	pNew=(Node*)malloc(sizeof(int));
	if(NULL==pNew)
	{
		perror("malloc");
		exit(1);
	}
		pNew -> data=data;
		pNew -> link=NULL;
		return pNew;
}

LinkedList*create(void)
{
	LinkedList*pthis=(LinkedList*)malloc(sizeof(LinkedList));
	if(NULL==pthis)
	{
		perror("malloc");
		exit(1);
	}
	pthis -> head=NULL;
	return pthis;
}

void display(LinkedList*pthis)
{
	Node*jump=pthis -> head;
	printf("Linked List is as follows :\n\n");
	do
	{
		printf("|%d %p|",jump->data,jump->link);
		if(NULL!=jump->link)
			printf("->");
		jump=jump->link;
	}while(NULL!=jump->link);
	printf("|%d NULL|\n\n",jump -> data);
}

bool InsertBeg(LinkedList*pthis,int data)
{
	Node*pNew;
	pNew=NewNode(data);
	pNew -> link=pthis -> head;
	pthis -> head =pNew;
	return true;
}

bool append(LinkedList*pthis,int data)
{
	Node *pNew,*last;
	//create a new node
	pNew=NewNode(data);
	//Linked List may be empty
	if(NULL==pthis -> head)
	{
		pthis -> head=pNew;
		return true;
	}
	//put pointer on last node then attach new node to last node
	last=pthis -> head;
	//after while loop last will point to last node of list
	while(NULL!=last -> link)
	{
		last = last -> link;
	}
	//attach new node to last node
	last -> link = pNew;
	return true;
}

int size(LinkedList*pthis)
{
	int count=0;
	Node*cursor=pthis -> head;
	while(NULL!=cursor)
	{
		count++;
		cursor=cursor -> link;
	}
	return true;
}

bool InsertAt(LinkedList *pthis,int data,int pos)
{
	Node*cursor,*pNew;
	int i;
	pNew = NewNode(data);
	if(pos<0||pos>size(pthis))
		return false;
	cursor = pthis -> head;
	for(i=0;i<pos-1;i++)
	{
		cursor=cursor -> link;
	}	
	pNew -> link = cursor -> link;
	cursor -> link = pNew;
	return true;
}

bool DeleteBeg(LinkedList *pthis,int* pData)
{
	Node*pDel;
	if(NULL==pthis->head)
		return false;
	pDel = pthis -> head;
	*pData = pDel -> data;
	pthis -> head = pthis -> head -> link;
	free(pDel);
}

bool DeleteEnd(LinkedList *pthis,int* pData)
{
	Node*pDel,*lbo;
	if(NULL==pthis -> head)
	{
		return false;
	}
	if(NULL == pthis -> head -> link)
	{
		*pData=pthis->head->link;
		free(pthis->head);
		pthis->head=NULL;
		return true;
	}
	lbo=pthis -> head;
	while(NULL!=lbo->link->link)
		lbo=lbo->link;
	pDel = lbo->link;
	*pData = pDel -> data;
	lbo -> link = NULL;
	free(pDel);
	return true;
}
int main(void)
{
	int elem;
	LinkedList*ll;
	ll=create();
	InsertBeg(ll,30);
	InsertBeg(ll,20);
	InsertBeg(ll,10);
	append(ll,40);
	append(ll,50);
	append(ll,60);
	display(ll);
	DeleteBeg(ll,&elem);
	printf("Deleted Element is %d \n\n",elem);
	DeleteEnd(ll,&elem);
	printf("Deleted Element is %d \n\n",elem);
	display(ll);
	return 0;
}
