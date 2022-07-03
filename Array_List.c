#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ArrayListADT
{
	float *list;
	int size;
	int capacity;
};
typedef struct ArrayListADT ArrayList;
ArrayList * create(int cap)
{
	ArrayList * al = NULL;
	//allocate memory
	al = (ArrayList*)malloc(sizeof(ArrayList*));
	//initialize non pointer variables
	al -> size = 0;
	al -> capacity = cap;	
	//allocate memory for parts
	al -> list = (float*)malloc(al -> capacity * sizeof(float*));
	//return arraylist
	return al;
}
void destroy(ArrayList * al)
{
	//free parts
	free(al -> list);
	//free whole
	free(al);
}
void display(const ArrayList * al)
{
	int i = 0;
	for(i = 0;i < al -> size; i++ )
	{
		printf("list[%d] = %f\n",i,al -> list[i]);
	}
}
bool InsertBeg(ArrayList * al,float elem)
{
	int i=0;
	//validate list is full
	if(al -> size == al -> capacity)
		return false;
	//shift all the elements to right by one position
	for(i=al -> size-1;i>=0;i--)
	{
		al -> list[i+1]= al -> list[i];
	}
	//insert elem at 0th position
	al -> list[0] = elem;
	//increase size
	al -> size = al -> size + 1;
	return true;
}
bool append(ArrayList * al , float elem)
{
	//validate fullness
	if(al -> size == al -> capacity)
		return false;
	//insert at end
	al -> list[al -> size] = elem;
	//increase size
	al -> size = al -> size + 1;
	//return
	return true;
}
bool InsertAt(ArrayList * al,float elem,int pos)
{
	int i;
	//validate position
	if(pos<0 || pos > al -> size)
		return false;
	//validate fullness
	if(al -> size == al -> capacity)
		return false;
	//shift elements to right from pos to size-1
	for(i=al -> size-1;i>=0;i--)
		al -> list[i+1] = al -> list[i];
	//insert element at position
	al -> list[pos] = elem;
	//increase size
	al -> size ++;
	//return
	return true; 
}
bool DeleteBeg(ArrayList * al,float * pDel)
{
	int i;
	//validate emptyness
	if(0 == al -> size)
		return false;
	//copy list[0] elem to pass by reference pDel
	*pDel = al -> list[0];
	//shift all elements to left from 1 to size-1
	for(i = 1;i <= al -> size-1;i--)
		al -> list[i-1] = al -> list[i]; 
	//decrease size
	al -> size--;
	//return
	return true;
}
bool DeleteEnd(ArrayList * al,float * pDel)
{
	//validate emptyness
	if( 0 == al -> size)
		return false;
	//copy list[size-1] elem to pass by reference pDel
	*pDel = al -> list[al -> size-1];
	//decrease size 
	al -> size--;
	//return
	return true;
}
bool DeleteAt(ArrayList *al,float * pDel,int pos)
{
	int i;
	//validate position
	if(pos<0 || pos > al -> size)
	//validate emptyness
	if(0 == al -> size)
		return false;
	//copy list[pos] elem to pDel using pass by reference
	*pDel = al -> list[pos];
	//shift elem by one to left from pos+1 to size-1
	for(i = pos+1;i <= al -> size-1;i++)
		al -> list[i-1]=al -> list[i];
	//decrease size
	al -> size--;
	//return
	return true;
}
int main(void)
{
	ArrayList * al = create(5);
	int choice;
	int pos;
	float elem;
	do{
		printf(" 1.Insert \n 2.Delete \n 3.Display \n 4.Destroy");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1  : printf("Enter element : ");
					  scanf("%f",&elem);
					  printf("Enter position : ");
					  scanf("%d",&pos);
					  if(0 == pos)
					  {
					  	if(false == InsertBeg(al,elem))
					  		printf("List May be Full\n");
					  }
					  else if(al -> size == pos)
					  {
					  	if(false == append(al,elem))
					  		printf("List may be full\n");
					  }
					  else
					  {
					  	if(false == InsertAt(al,elem,pos))
					  		printf("List May be Full\n");
					  }
					  break;
			case 2  : printf("Enter position : ");
					  scanf("%d",&pos);
					  if(0 == pos)
					  {
					  	if(true == DeleteBeg(al,&elem))
					  		printf("%f got deleted\n",elem);
					  	else
					  		printf("List may be empty");
					  }
					  else if(al -> size-1 == pos)
					  {
					  	if(true == DeleteEnd(al,&elem))
					  		printf("%f got deleted\n",elem);
					  	else
					  		printf("List may be empty");
					  }
					  else
					  {
					  	if(true == DeleteAt(al,&elem,pos))
					  		printf("%f got deleted\n",elem);
					  	else
					  		printf("List may be empty");
					  }
					  break;
			case 3  : display(al);
					  break;
			case 4  : destroy(al);
					  break;
			default : printf("INVALID CHOICE");
					  break;
		}
	}while(true);
	printf("\n");
	return 0;
}
