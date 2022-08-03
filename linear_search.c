#include<stdio.h>
void readList(int list[],int size)
{
	int i;
	printf("Enter %d elements : ",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&list[i]);
	}
	return;
}
void printList(int list[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d  ",list[i]);
	}
	printf("\n");
	return;
}
int LinearSearch(int list[],int size,int key)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(list[i] == key)
			return i;
	}
	return -1;
}
int main(void)
{
	int list[100];
	//input
	readList(list,8);
	//output
	printf("List Before sorting :");
	printList(list,8);
	//searching
	int key;
	printf("\nenter key to search : %d",key);
	scanf("%d",&key);
	int res;
	res = LinearSearch(list,8,key);
	if(res == -1)
	{
		printf("NOt found");
	}
	else
		printf("\nKey is at position : %d",res);
	return 0;
}
