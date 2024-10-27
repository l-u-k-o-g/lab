#include<stdio.h>
#include<string.h>
#include<ctype.h>
char tempvariables[]={'z','y','x','w','v','u','t'};
int length,top=-1,count=0,tvar=0;
char input[20],tempinput[20];
char prearray[20];
char stack[20];
char threeaddress[10][10];
char concatarray[20];
char * strrev(char * str)
{
	if(!str||!*str)return str;
	int i=strlen(str)-1,j=0;
	char ch;
	while(i>j)
	{
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
		i--;
		j++;
	}
	return str;
}
int prec(char op){
	switch(op){
	case '+':return 1;
	break;
	case '*':return 2;
	break;
	case '/':return 2;
	}
}
int isoperator(char sym){
	if(sym=='+'||sym=='-'||sym=='*'||sym=='/')
	return 1;
	else
	return 0;
}
void push(char sym){
	top++;
	stack[top]=sym;
}

char pop(){
	top--;
	return(stack[top+1]);
	}
void display(){
	int i;
	printf("\n stack");
	for(i=top;i>-1;i--)
		printf("%c\t",stack[i]);
	}
void del(char sym,int pas){
	int j,c=0,k;
	for(j=0;j<pas;j++)
	tempinput[j]=prearray[j];
	tempinput[j]=tempvariables[tvar-1];
	k=j+1;
	for(j=j+3;j<length;j++)
		tempinput[k++]=prearray[j];
	strcpy(prearray,tempinput);
	length=strlen(prearray);
}
void prefix()
{
	int i,k=0;
	char popval;
	for(i=0;i<length;i++)
	{
		if(isalpha(input[i])||isdigit(input[i]))
			prearray[k++]=input[i];
		else
		{
			if(top==-1)
				push(input[i]);
			else
			{
			while(prec(stack[top])>=prec(input[i]))
				prearray[k++]=pop();
			push(input[i]);
			}
		}
	}
	if(top!=-1)
		for(i=top;i>-1;i--)
		prearray[k++]=pop();
}
void generator(char op,char sym1,char sym2){
	int len=0;
	concatarray[len++]=tempvariables[tvar++];
	concatarray[len++]='=';
	concatarray[len++]=sym1;
	concatarray[len++]=op;
	concatarray[len++]=sym2;
	strcpy(threeaddress[count++],concatarray);
}
void main(){
	int i;
	printf("\n Enter  the input expression: ");
	scanf("%s",input);
	length=strlen(input);
	strcpy(input,strrev(input));
	prefix();
	strcpy(prearray,strrev(prearray));
	for(i=0;i<length;i++)
		if(isoperator(prearray[i]))
			if((isalpha(prearray[i+1])||isdigit(prearray[i+1]))&&(isalpha(prearray[i+2])||isdigit(prearray[i+2])))
			{
		generator(prearray[i],prearray[i+1],prearray[i+2]);
				del(prearray[i],i);
				i=-1;
			}
	printf("\n Three Address code for the expression:\n\n");
	for(i=0;i<count;i++)
		printf("%s\n",threeaddress[i]);
}
