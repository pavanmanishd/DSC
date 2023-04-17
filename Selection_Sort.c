#include<stdio.h>
#include<stdlib.h>
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
void Exchange(int *pa,int *pb)
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
	return;
}
int FindMaxIndex(int list[],int size)
{
	int i,maxindex;
	maxindex = 0;
	for(i=1;i<=size;i++)
	{
		if(list[maxindex]<list[i])
			maxindex=i;
	}
	return maxindex;
}
void SelectionSort(int list[],int size)
{
	int pass,maxindex;
	for(pass=1;pass<size;pass++)
	{
		maxindex = FindMaxIndex(list,size-pass);
		if(list[maxindex]!=list[size-pass])
		{
			Exchange(&list[maxindex] ,&list[size-pass]);
		}
	}
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
	SelectionSort(list,8);
	//output
	printf("List after swapping : \n");
	printList(list,8);
	return 0;
}

