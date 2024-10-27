#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void Tprime();
void Eprime();
void E();
void T();
void check();
char expression[10];
int count,flag;
int main()
{
	count=0;
	flag=0;
	printf("\nEnter an Algebraic expression: \t");
	scanf("%s",expression);
	E();
	if ((strlen(expression)==count)&&(flag==0))
		printf("\n the expression %s is valid\n",expression);
	else
		printf("\n the expression %s is invalid\n",expression);
}
void E()
{
 	T();
 	Eprime();
}
void T()
{
	 check();
 	Tprime();
}
void Tprime()
{
	if(expression[count]=='*')
	{
		count++;
		check();
		Tprime();
	}
}
void check()
{
	if(isalnum(expression[count]))
	{
		count++;
	}
	else if(expression[count]=='(')
	{
		count++;
		E();
		if (expression[count]==')')
			count++;
		else
			flag=1;
	}
	else
		flag=1;
}
void Eprime()
{
	if(expression[count]=='+')
	{
		count++;
		T();
		Eprime();
	}
}
