#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 100
char Stack[SIZE];
int tos=-1;
void push(char op)
{
	Stack[++tos]=op;
}
char pop()
{
	return Stack[tos--];
}
bool isOperator(char token)
{
	switch(token)
	{
		case '+' : return true;
		case '-' : return true;
		case '*' : return true;
		case '/' : return true;
		case '%' : return true;
		default  : return false;
	}
}
float compute(float op1,char op,float op2)
{
	float res;
	switch(op)
	{
		case '+' : return op1+op2;
		case '-' : return op1-op2;
		case '*' : return op1*op2;
		case '/' : return op1/op2;
	}
}
float evaluate(char Postfix[])
{
	int i;
	char token;
	float res,op1,op2;
	for(i=0 ; '\0'!=Postfix[i] ; i++)
	{
		token = Postfix[i];
		if(true == isOperator(token))
		{
			
			op2 = pop();
			op1 = pop();
			res = compute(op1,token,op2);
			push(res);
			
		}
		else
		{
			push(token - '0');
		}
	}
	return pop();
}
int main(void)
{
	float answer;
	char Postfix[81];
	printf("Enter postfix expression : ");
	scanf("%s",Postfix);
	answer = evaluate(Postfix);
	printf("The solution is : %f\n",answer);
	return 0;
}
