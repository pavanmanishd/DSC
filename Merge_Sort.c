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
void merge(int a[],int lo,int mid,int hi)
{
	int i,j,k;
	int *temp;
	temp = (int*)malloc(sizeof(int)*(hi-lo+1));
	i=lo;
	j=mid+1;
	k=0;
	while((i<=mid)&&(j<=hi))
	{
		if(a[i]<a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(j<=hi)
		temp[k++] = a[j++];
	while(i<=mid)
		temp[k++] = a[j++];
	for(k=0,i=lo;k<(hi-lo+1);k++,i++)
		a[i] = temp[k];
	free(temp);	
}
void MergeSort(int list[],int lo,int hi)
{
	int mid;
	while(lo<hi)
	{
		mid = (lo+hi)/2;
		MergeSort(list,lo,mid);
		MergeSort(list,mid+1,hi);
		merge(list,lo,mid,hi);
	}
}
int main(void)
{
	int list[100];
	//input
	readList(list,10);
	//output
	printf("List Before sorting :");
	printList(list,10);
	//sorting
	int lo = 0;
	int hi = 9;
	MergeSort(list,lo,hi);
	//output
	printf("List after sorting :");
	printList(list,10);
	return 0;
}
