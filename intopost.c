#include<stdio.h>
#include<stdlib.h>
#define N 25
#define M 25

char val;

int isoprator(char ch)
{
    if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
        return(1);
    else
        return(0);
}

int isoprand(char ch)
{
    if((ch>='0'&&ch<='9'
        )||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        return(1);
    else
        return(0);
}

int prac(char ch)
{
    if(ch=='^')
        return(3);
    else if(ch=='*'||ch=='/')
        return(2);
    else if(ch=='+'||ch=='-')
        return(1);
    else
        return(0);
}

void push(char s[],int *top,char val)
{
        if(*top<(N-1))
        {
            (*top)++;
            s[*top]=val;
        }
        else
            printf("stack is full\n");
        return;
}
char pop(char s[],int *top)
{
        if((*top)>-1)
        {
            val=s[*top];
            (*top)--;
            return val;
        }
        else
            printf("stack is empty\n");
        return(-1);
}

int read(char s[],int top,int i)
{
    if((top-i+1)>=0)
        return s[top-i+1];
    else
        printf("not found\n");

}

int isempty(char s[],int top)
{
    if(top==-1)
        return(1);
    else
        return(0);
}

void infixtopostfix(char *i,char *p)
{
    char s[N];int top=-1;
    while(*i!='\0')
    {
        if(isoprand(*i))
        {
            *p=*i;
            *i++;
            *p++;
        }

        else if (*i=='(')
        {
           push(s,&top,'(');
           *i++;
        }
        else if(*i==')')
        {
            while(read(s,top,1)!='(')
            {
                *p=pop(s,&top);
                *p++;
            }
            *i++;
	    pop(s,&top);
	
        }
        else if(isempty(s,top)||read(s,top,1)=='('||prac(*i)>prac(read(s,top,1)))
        {
            push(s,&top,*i);
            *i++;
        }



        else
        {
            *p=pop(s,&top);
            *p++;
        }
    }
    while(!isempty(s,top))
    {
        *p=pop(s,&top);
        *p++;
    }
}

void main()
{
    char infix[M];
    char postfix[M];
    printf("Enter an infix Equation:\n");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("postfix is %s",postfix);
}
