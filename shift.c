#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
char ip_sym[15],stack[15];
int ip_ptr=0,st_ptr=0,len,i;
char temp[2],temp2[2];
char act[15];
void check();
void main()
{
	printf("\n\t\tSHIFT REDUCE PARSER\n");
	printf("\nGRAMMER\n");
	printf("\nE->E+E\nE->E/E");
	printf("\nE->E*E\nE->a/b\n");
	printf("enter the input symbol:\t");
	scanf("%s",ip_sym);
	printf("STACK IMPLEMENTATION TABLE\n");
	printf("\nSTACK\t\tINPUT SYMBOL\t\tACTION");
	printf("\n______\t\t_____\n");
	printf("\n$\t\t%s$\t\t\t__",ip_sym);
	strcpy(act,"shift");
	temp[0]=ip_sym[ip_ptr];
	temp[i]='\0';
	strcat(act,temp);
	len=strlen(ip_sym);
	for(i=0;i<len;i++)
	{
		stack[st_ptr]=ip_sym[ip_ptr];
		stack[st_ptr+1]='\0';
		ip_sym[ip_ptr]=' ';
		ip_ptr++;
		printf("\n$%s\t\t%s$\t\t%s",stack,ip_sym,act);
		strcpy(act,"shift");
		temp[0]=ip_sym[ip_ptr];
		temp[1]='\0';
		strcat(act,temp);
		check();
		st_ptr++;
	}
	st_ptr++;
	check();
}
void check()
{
	int flag=0;
	temp2[0]=stack[st_ptr];
	temp2[1]='\0';
	if((!strcmp(temp2,"a"))||(!strcmp(temp2,"b")))
	{
		stack[st_ptr]='E';
		if(!strcmp(temp2,"a"))
			printf("\n$%s\t\t%s$\t\tE->a",stack,ip_sym);
		else
			printf("\n$%s\t\t%s$\t\tE->b",stack,ip_sym);
              flag=1;
	}
	if((!strcmp(temp2,"+"))||(!strcmp(temp2,"*"))||(!strcmp(temp2,"/")))
	flag=1;
	if((!strcmp(stack,"E+E"))||(!strcmp(stack,"E/E"))||(!strcmp(stack,"E*E")))
	{
		strcpy(stack,"E");
		st_ptr=0;
		if(!strcmp(stack,"E+E"))
			printf("\n$%s\t\t%s$\t\tE->E+E",stack,ip_sym);
		else
		    if(!strcmp(stack,"E\E"))
                	printf("\n$%s\t\t%s$\t\tE->E\E",stack,ip_sym);
		    else
			printf("\n$%s\t\t%s$\t\tE->E*E",stack,ip_sym);
			flag=1;
	}
	if(!strcmp(stack,"E")&&ip_ptr==len)
	{
		printf("\n$%s\t\t%s$\t\tACCEPT\n",stack,ip_sym);
		getchar();
		exit(0);
	}
	if(flag==0)
	{
		 printf("\n$%s\t\t%s$\t\tREJECT\n",stack,ip_sym);
		exit(0);
	}
		return;
}
