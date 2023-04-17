#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct QueueADT
{
	float * list;
	int capacity;
	int rear;
	int front;
};
typedef struct QueueADT Queue;
Queue * create(int cap)
{
	Queue * pthis;
	//allocate memory for whole
	pthis = (Queue*)malloc(sizeof(Queue*));
	//memory allocation for parts
	pthis -> list = (float *)malloc(cap * sizeof(float));
	pthis -> rear = -1;
	pthis -> front = 0;
	pthis -> capacity = cap;
}
bool enqueue(Queue * pthis , float elem)
{
	//validating the fullness of queue
	if(pthis -> rear+1 == pthis -> capacity)
	{	
		return false;
	}
	//increment the rear
	pthis -> rear = pthis -> rear+1;
	//assign element at position
	pthis -> list[pthis -> rear] = elem;
}
void display(Queue * pthis)
{
	int i;
	printf("Queue is as follows : \n");
	for(i=pthis -> front;i<=pthis -> rear;i++)
	{
		printf("%f\t",pthis -> list[i]);
	}
	
}
bool dequeue(Queue * pthis,int * pelem)
{
	//validate queue is empty
	if(pthis -> rear<pthis -> front)
		return false;
	//copy the front elem by pass by ref
	*pelem = pthis -> list[pthis -> front];
	//logical deletion
	pthis -> front =pthis -> front + 1;
	return true;
}
int main(void)
{
	int elem;
	Queue * ps = create(10);
	enqueue(ps,10);
	enqueue(ps,20);
	enqueue(ps,30);
	enqueue(ps,40);
	enqueue(ps,50);
	enqueue(ps,60);
	display(ps);
	dequeue(ps,&elem);
	printf("\nDequeued element is %d \n",elem);
	printf("Queue after Dequeue operation :\n");
	display(ps);
	return 0;
}
