#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 100
char Stack[SIZE];
int tos = -1;
void push(char op)
{
	Stack[++tos]=op;
}
char pop()
{
	return Stack[tos--];
}
char peep()
{
	return Stack[tos];
}
bool isOperator(char token)
{
	switch(token)
	{
		case '+' :
		case '-' :
		case '*' :
		case '/' :
		case '%' : return true;
		default  : return false;
	}
}
int getPriority(char op)
{
	if(op == '*' ||op == '/'||op=='%')
		return 2;
	if(op == '+' || op == '-' )
		return 1;
	if(op == '(')
		return 0;
}
void InfixtoPostfix(char Infix[],char Postfix[])
{
	int i=0,j=0;
	char token,x;
	//initialize stack
	for(i=0;'\0'!=Infix[i];i++)
	{
		token = Infix[i];
		if(token == '(')
		{
			push(token);
		}
		//if we get ) then print all the members in stack to output upto )
		else if(token == ')')
		{
			while((tos>-1) && ('(' != (x=pop())))
			{
				Postfix[j++]=x;
			}
		}
		//if token is operator
		else if(true == isOperator(token))
		{
			//pop all operators from stack with higher or equal prioriy
			while((tos>-1) && (getPriority(peep())>=getPriority(token)))
			{
				Postfix[j++] = pop();
			}
			push(token);
		}
		//if token is operand
		else
		{
			Postfix[j++]=token;
		}
	}
	//pop all remaining operators from stack
	while(tos>-1)
	{
		Postfix[j++] = pop();
	}
	//make postfix a string
	Postfix[j] = '\0';
}
int main(void)
{
	char Infix[81];
	char Postfix[81];
	printf("Enter infix expression : ");
	scanf("%s",Infix);
	InfixtoPostfix(Infix,Postfix);
	printf("Postfix expression is : %s\n",Postfix);
	return 0;
}
