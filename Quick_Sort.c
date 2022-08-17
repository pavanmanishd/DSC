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
int partition(int list[],int lo,int hi)
{
	int i,j,pivot,temp;
	i = lo;
	j = hi;
	 pivot = list[lo];
	while(i<j)
	{
		while(list[i]<=pivot)
			i++;
		while(list[j]>pivot)
			j--;
		if(i<j)
		{
			temp  = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
		else 
			break;
	}
	//i crossed j
	list[lo] = list[j];
	list[j] = pivot;
	return j; 
}
void QuickSort(int list[],int lo,int hi)
{
	int k;
	if(lo<hi)
	{
		k = partition(list,lo,hi);
		QuickSort(list,lo,k-1);
		QuickSort(list,k+1,hi);
	}
	else
		return;
}
int main(void)
{
	int list[100];
	//input
	readList(list,8);
	//output
	printf("List Before sorting :");
	printList(list,8);
	//sorting
	int lo = 0;
	int hi = 7;
	QuickSort(list,lo,hi);
	//output
	printf("List after sorting :");
	printList(list,8);
	return 0;
}
