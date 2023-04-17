#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void readList(int[],int);
void printList(int[],int);
void bubbleSort(int[],int);
int main(void)
{
	int list[100];
	//input
	readList(list,8);
	printf("List Before swapping :\n");
	printList(list,8);
	//process
	bubbleSort(list,8);
	//output
	printf("List after swapping : \n");
	printList(list,8);
	return 0;
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
void bubbleSort(int list[],int size)
{
	int pass,i,temp,a=1,b=0;
	for(pass=1;pass<size;pass++)
	{
		b=0;
		if(a == b)
			{
				break;
			}
		a=0;
		printf("pass number : %d\n",pass);
		for(i=0;i<size-pass;i++)
		{
			if(list[i]>list[i+1])
			{
				temp=list[i];
				list[i]=list[i+1];
				list[i+1]=temp;
				printList(list,8);
				a++;
			}
		}
	}
	return;
}
