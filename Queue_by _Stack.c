#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void push(int stack[],int val, int *top)
{


    if(*top==MAX-1)
    {
        printf("\nStack is full!!\n");
    }
    else
    {

        *top=*top+1;
        stack[*top]=val;
    }
}

int pop(int stack[], int *top)
{   int val;
    if(*top==-1)
    {
        printf("\nStack is empty!!");
    }
    else
    {   val=stack[*top];
        *top=*top-1;
    }
    return val;
}
void delete(int s1[],int s2[],int ts1,int ts2)
{
    int val=0;
    while(!isempty(s1,ts1))
    {	
        push(s2,pop(s1,&ts1),&ts2);
    }
    val=pop(s2,&ts2);
    printf("deleted value is%d\n",val);
}
void display(int s1[],int s2[],int ts1,int ts2)
{
    while(!isempty(s1,ts1))
    {	
        push(s2,pop(s1,&ts1),&ts2);
    }
    while(!isempty(s2,ts2))
    {
        printf("\n%d\n",pop(s2,&ts2));
    }
}
int isempty(char s[],int top)
{
    if(top==-1)
        return(1);
    else
        return(0);
}
int main()
{
    int i=0,val;
    int s1[MAX],s2[MAX];
    int ts1=-1,ts2=-1;
    while(i!=4)
    {
        printf("enter 1 to insert an Element \nenter 2 To delete\nenter 3 to dislpay\nenter 4 to exit\n");
        scanf("%d",&i);

        switch(i)
        {
            case 1:
                printf("\nEnter element to push:");
                scanf("%d",&val);
                push(s1,val,&ts1);
                break;
		
	    case 2:
		delete(s1,s2,ts1,ts2);
		while(!isempty(s1,ts1))
   		 {	
        		push(s2,pop(s1,&ts1),&ts2);
    		}
		pop(s2,&ts2);
		break;	

	    case 3:
		display(s1,s2,ts1,ts2);
		break;

            case 4: break;

            default: printf("\nWrong Choice\n!!");
        }
	
    }
    
    
}

