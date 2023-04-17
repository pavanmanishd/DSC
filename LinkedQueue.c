#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct NodeType
{
	int data;
	struct NodeType * link;
};
typedef struct NodeType Node;
Node * newNode(int data)
{
	//allocating memory for node
	Node * newNode = (Node*)malloc(sizeof(Node));
	//initilaize mmbers
	newNode -> data = data;
	newNode -> link = NULL;
	return newNode;
}
struct QueueADT
{
	Node * rear;
	Node * front;
};
typedef struct QueueADT Queue;
Queue * create (void)
{
	Queue * pthis = NULL;
	pthis = (Queue*)malloc(sizeof(Queue));
	pthis -> front = NULL;
	pthis -> rear = NULL;
	return pthis;
}
bool enqueue(Queue * pthis,int elem)
{
	Node * pNew = newNode(elem);
	if(NULL==pthis -> front)
	{
		pthis -> front = pthis -> rear=pNew;
		return true;
	}
	pthis -> rear -> link = pNew;
	pthis -> rear = pNew;
	return true;
}
void display(Queue * pthis)
{
	Node * jump = pthis -> front;
	printf("Queue is as follows");
	while(NULL!=jump)
	{
		printf("%d\t",jump -> data);
		jump = jump -> link;
	}
}
bool dequeue(Queue * pthis , int *pelem)
{
	Node * pDel;
	if(NULL==pthis -> front)
		return false;
	pDel = pthis ->front;
	*pelem = pDel -> data;
	pthis -> front = pthis ->front->link;
	free(pDel);
	return true;	
}
int main(void)
{
	int elem;
	Queue * ps = create ();
	enqueue(ps,10);
	enqueue(ps,20);
	enqueue(ps,30);
	enqueue(ps,40);
	enqueue(ps,50);
	display(ps);
	dequeue(ps,&elem);
	printf("%d is dequeued \n",elem);
	display(ps);
	
}
