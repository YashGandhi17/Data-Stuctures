#include<stdio.h>
#include<stdlib.h>
#define N 50

int top = -1;
int S[N];
int q[N];

struct node
{
    int data;
    struct node *link;
};

struct node *insertatfront(struct node *H,int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("malloc failed.\n");
		return H;
	}
	newnode->data=data;
	newnode->link=H;
	H=newnode;
	return H;
}

struct node *delet(struct node *H,int data)
{
	struct node *nodetobedeleted;
	struct node *temp;
	if(H==NULL)
	{
		printf("Np cars available.\n");
		return H;
	}
	if(H->data==data)
	{
		nodetobedeleted=H;
		H=H->link;
		free(nodetobedeleted);
		return H;
	}
	temp=H;
	while(temp->link!=NULL&&temp->link->data!=data)
	{
		temp=temp->link;
	}
	if(temp->link==NULL)
	{
		printf("\nCar not in stock.\n");
		return H;
	}
	else
	{
		nodetobedeleted=temp->link;
		temp->link=temp->link->link;
		free(nodetobedeleted);
	}
	return H;
}


void insert(int q[],int *f,int *r,int val)
{
    if((*r)>=N-1)
        printf("There are too many costumer.please come another day\n");
    else
    {
        q[++(*r)]=val;
        if((*f)==-1)
            *f=0;
    }
}

int qdelete(int q[],int *f,int *r)
{int val;
        if((*r)==-1)
        {
            printf("queue is empty");
            exit(-1);
        }
        else
        {
            val=q[*f];
            if((*f)==(*r))
               {
                    *r=-1;
                    *f=-1;
               }
            else
                (*f)++;
        }
        return val;
}


void push(int value)
{
	if(top<N-1)
	{
		top++;
		S[top]=value;
	}
	else
	{
		printf("Stack is full.\n");
	}
}

int pop()
{
	if(top>=0)
	{
	return S[top--];
	}
	else
	{
		printf("There are no history of any cars.\n");
	}
	return 0;
}

int main()
{
    struct node *H;
    H=NULL;
    int choice;
    int val=0;
    int var,val1,f=-1,r=-1;
    int i;

    H=insertatfront(H,5);H=insertatfront(H,4);H=insertatfront(H,3);H=insertatfront(H,2);H=insertatfront(H,1);
    H=insertatfront(H,5);H=insertatfront(H,4);H=insertatfront(H,3);H=insertatfront(H,2);H=insertatfront(H,1);
    H=insertatfront(H,5);H=insertatfront(H,4);H=insertatfront(H,3);H=insertatfront(H,2);H=insertatfront(H,1);

    printf("-------CAR LIST-------\n");
    printf("Enter 1 for MARUTI car :\n");
    printf("Enter 2 for AUDI car :\n");
    printf("Enter 3 for MARCIDESE car :\n");
    printf("Enter 4 for HONDA car :\n");
    printf("Enter 5 for FORD car :\n");
    printf("-----------------------\n");

    while(choice!=4)
    {
        printf("Enter 1 for BOOKING a car :\n");
        printf("Enter 2 to know LAST SOLD car :\n");
        printf("Enter 3 for EXIT :\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("enter value to enter\n");
                scanf("%d",&val1);
                insert(q,&f,&r,val1);
                val=qdelete(q,&f,&r);
                push(val);
                H=delet(H,val);
                break;
            case 2:
                var=pop();
                printf("last sold car is %d.\n",var);
                break;
            case 3:
                break;
            default :
                printf("Enter valid choice :\n");
                break;
        }
    }
}
