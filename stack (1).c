#include<stdio.h>
#include<stdlib.h>
#define N 5
int val;
int s[N];
int top=-1,n,i;


void push(int s[],int *top,int val)
{
	if(*top<=(N-1))
	{
		(*top)++;
		s[*top]=val;
	}
	else
{
	printf("stack is full\n");
}

}

void pop(int s[],int *top)
{
	if(*top>-1)
	{
		val=s[*top];
		(*top)--;
		printf("%d\n",val);
	}
	else
{
	printf("stack is empty\n");
}

}

void read(int s[],int top)
{
		for(int i=0;i<top;i++)
		{

		printf("%d\n",s[top]);
		}
}

void main()
{
    printf("enter 1 to push\n");
	printf("enter 2 to pop\n");
	printf("enter 3 to display\n");
	printf("enter 4 to exit\n");

while(1)
{

	printf("enter 1/2/3/4\n");
	scanf("%d",&n);

		switch(n)
		{
			case 1:
			printf("enter the number\n");
			scanf("%d",&val);
			push(s,&top,val);
			//getchar();
			break;

			case 2:
			pop(s,&top);
			break;


			case 3:
			read(s,top);
			break;


			default:
			printf("not valid ");

		}


	}
return 0;
}
















































