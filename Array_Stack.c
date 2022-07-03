#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct StackADT
{
	int * list;
	int tos;
	int capacity;
};
typedef struct StackADT Stack;
Stack * create (int cap)
{
	Stack * as = NULL;
	//allocate memory for whole
	as = (Stack*)malloc(sizeof(Stack*));
	//allocate memory for parts
	as -> list = (int*)malloc(cap*sizeof(int*));
	//initialize all members
	as -> tos = -1;
	as -> capacity = cap;
	//return
	return as;
}
void destroy(Stack * as)
{
	free(as -> list);
	free(as);
}
void display(Stack * as)
{
	int i;
	printf("Stack is as follows :\n");
	for(i=as -> tos;i>=0;i--)
	{
		printf("%d\n",as -> list[i]);
	}
}
bool push(Stack * as,int elem)
{
	//vaidate fullness
	if(as -> tos+1 == as -> capacity)
		return false;
	//increase tos
	as -> tos = as -> tos+1;
	//insert elem in list[tos]
	as -> list[as -> tos] = elem;
	//return
	return true;
}
bool pop(Stack * as,int *pDel)
{
	//validate emptyness
	if(-1 == as -> tos)
		return false;
	//copy list[tos+1] to pass by reference
	pDel = as -> list[as -> tos+1];
	//logical deletion
	as -> tos = as -> tos-1;
	//return
	return true;
}
bool peep(Stack * as,int *pDel)
{
	//validate emptyness
	if(-1 == as -> tos)
		return false;
	//copy list[tos+1] to pass by reference
	pDel = as -> list[as -> tos+1];
	//return
	return true;
}
int main(void)
{
	Stack * as = create(5);
	int choice,elem;
	bool res;
	do{
		printf("\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit");
		switch(choice)
		{
			case 1 : printf("Enter elem to push : ");
					 scanf("%d",&elem);
					 push(as,elem);
					 break;	
			case 2 : res = pop(as,&elem);
					 if(true == res)
				 		printf("%d got popped\n",elem);
					 else
					 	printf("Stack may be empty\n");
					 break;
			case 3 : res = peep(as,&elem);
					 if(true == res)
				 		printf("%d got peeped\n",elem);
					 else
					 	printf("Stack may be empty\n");
					 break;
			case 4 : display(as);
					 break;
			case 5 : destroy(as);
					 return 0;
			default: printf("Invalid choice\n");
			         break;
		}
	}while(true);
}
