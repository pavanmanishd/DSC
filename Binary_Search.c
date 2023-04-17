#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
int Binary_Search(int list[],int lo,int hi,int key)
{
	int mid;
	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		if(key == list[mid])
			return mid;
		else if(key<list[mid])
			return Binary_Search(list,lo,mid-1,key);
		else if(key>list[mid])
			return Binary_Search(list,mid+1,hi,key);
	}
	return -1;
}
int main(void)
{
	int res;
	int list[100];
	int size,key;
	printf("Enter size:");
	scanf("%d",&size);
	readList(list,size);
	printf("Enter key element to search :");
	scanf("%d",&key);
	int lo,hi;
	lo=0;
	hi=size-1;
	res = Binary_Search(list,lo,hi,key);
	if(res == -1)
		printf("element not found");
	else
		printf("key found at position : %d ",res);
	return 0; 
}
