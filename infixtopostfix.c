#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 100
char stack[size];
int tos = -1;
void push(char op)
{
	stack[tos++] = op;
}
int pop()
{
	return stack[tos--];
}
int peep()
{
	return stack[tos];
}
bool isOperator(char token)
{
	switch(token)
	{
		case '+': return true;
		case '-': return true;
		case '*': return true;
		case '/': return true;
		case '%': return true;
		default : return false;
	}
}
int getPriority(char op)
{
	if(op == '*' || op == '/' || op == '%')
		return 2;
	else if(op == '+' || op == '-')
		return 1;
	else if(op == '(')
		return 0;
}
void InfixToPostfix(char infix[],char postfix[])
{
	int i=0,j=0;
	char token,x;
	for(i=0;'\0'!= infix[i];i++)
	{
		token = infix[i];
		if('('==token)
		{
			push(token);
		}
		else if(')'==token)
		{
			//send all elements upto ( to postfix
			while((tos>-1) && ('('!=(x=pop())))
			{
				postfix[j++] = x;
			}
		}
		else if(true == isOperator(token))
		{
			//send all operator of equal or higher priority to postfix
			while((tos>-1) && (getPriority(peep())>=getPriority(token)))
			{
				postfix[j++] = pop();
			}
			push(token);
		}
		else
		{
			postfix[j++] = token;
		}
    }
		//after all operators and operands are processed
		//pop all operators from stack to postfix
		while(tos>-1)
		{
			postfix[j++] = pop();
		}
		//make postfix a string
		postfix[j] = '\0';
}
int main(void)
{
	char infix[81];
	char postfix[81];
	printf("Enter the infix expression : ");
	scanf("%s",infix);
	InfixToPostfix(infix,postfix);
	printf("Postfix is : %s ",postfix);
	return 0;
}
