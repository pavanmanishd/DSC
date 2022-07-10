#include<stdio.h>
#include<stdlib.h>
void insert(int list[],int size,int elem)
{
	int i;
	for(i=size-1;elem<list[i];i--)
	{
		list[i+1] = list[i];
	}
	list[i+1]=elem;
	return;
}
void InsertionSort(int list[],int size)
{
	int pass,i,elem;
	for(pass=1;pass<size;pass++)
	{
		elem = list[pass];
		insert(list,pass,elem);
	}
	return;
}
void readList(int list[],int size)
{
	int i;
	printf("Enter %d elements : ",size);
	for(i=0;i<size;i++)
		scanf("%d",&list[i]);
	return;
}
void printList(int list[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",list[i]);
	}
	printf("\n");
	return;
}
int main(void)
{
	int list[100];
	//input
	readList(list,8);
	printf("List Before swapping :\n");
	printList(list,8);
	//process
	InsertionSort(list,8);
	//output
	printf("List after swapping : \n");
	printList(list,8);
	return 0;
}

