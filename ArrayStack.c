/*Date : 22-06-2022*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct StackADT
{
	int *list;
	int tos;
	int capacity;
};
typedef struct StackADT Stack;
Stack * create(int);
bool push(Stack *,int);
bool pop(Stack *,int *);
bool peep(Stack *,int *);
void display(Stack *);
void destroy(Stack *);
int main(void)
{
	bool res;
	int elem;
	Stack * ps = create(5);
	push(ps,10);
	push(ps,20);
	push(ps,30);
	push(ps,40);
	push(ps,50);
	res = push(ps,60);
	if(res == false)
		printf("Stack may be full\n"); 
	display(ps);
	pop(ps,&elem);
	printf("Popped element is %d\n",elem);
	pop(ps,&elem);
	printf("Popped element is %d\n",elem);
	display(ps);
	peep(ps,&elem);
	printf("Peeped Element is %d\n",elem);
	return 0;
}
Stack * create(int cap)
{
	Stack * pthis = NULL;
	//allocate memory for whole
	pthis = (Stack*)malloc(sizeof(Stack*));
	//allocate memory for parts
	pthis -> list = (int*)malloc(cap*sizeof(int));
	//initialize
	pthis -> capacity = cap;
	pthis -> tos = -1;
	return pthis;
}
bool push(Stack * pthis,int elem)
{
	//validate for fullness
	if(pthis -> tos+1==pthis -> capacity)
		return false;
	//increment tos
	pthis -> tos=pthis -> tos+1;
	pthis -> list[pthis -> tos]=elem;
	return true;
}
bool pop(Stack * pthis,int * pDel)
{
	//validate for emptyness
	if(-1==pthis -> tos)
		return false;
	//copy elem to pDel by pass by ref 
	*pDel = pthis -> list[pthis -> tos];
	//decrement tos
	pthis -> tos = pthis -> tos-1;
	return true;
}
bool peep(Stack * pthis,int * pelem)
{
	//validate for emptyness
	if(-1==pthis -> tos)
		return false;
	//copy elem to pelem by pass by ref
	*pelem = pthis -> list[pthis -> tos];
	return true;		
}
void destroy(Stack * pthis)
{
	//release parts
	free(pthis -> list);
	//release whole
	free(pthis);
}
void display(Stack * pthis)
{
	int i;
	printf("Stack is as follows :\n");
	//display stack
	for(i = pthis -> tos ; i>=0;i--)
		printf("%d\n",pthis -> list[i]); 
}
