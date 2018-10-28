#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *ptr;
};

struct node *insertatfront(struct node *h,int val)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("malloc failed");
        return h;
    }

    newnode->value=val;
    newnode->ptr=h;
    h=newnode;
    return h;
    
}

struct node *insertatend(struct node *h,int val)
{
    struct node *newnode;
    struct node *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("malloc failed");
        return h;
    }
    temp=h;
    while(temp->ptr!=NULL)
    {
	temp=temp->ptr;
    }
    newnode->value=val;
    temp->ptr=newnode;
    newnode->ptr=NULL;
    return h;
}

struct node *insert(struct node *h,int val,int val1)
{
    struct node *newnode;
    struct node *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("malloc failed");
        return h;
    }
    temp=h;
    while(temp->value!=val1)
    {
	temp=temp->ptr;
    }	
    newnode->value=val;
    newnode->ptr=temp->ptr;
    temp->ptr=newnode;
    return h;
}

struct node *ndelete(struct node *h,int val)
{
    struct node *temp;
    struct node *nodetobedeleted;
    if(h==NULL)
    {
        printf("list empty");
        return h;
    }
    if(h->value==val)
    {
        nodetobedeleted=h;
        h=h->ptr;
        free(nodetobedeleted);
	return h;
    }
    temp=h;
    while(temp->ptr!=NULL&&temp->ptr->value!=val)
    {
        temp=temp->ptr;}
        if(temp->ptr==NULL)
        {
            printf("not found");
            return h;
        }
        else
        {
            nodetobedeleted=temp->ptr;
            temp->ptr=temp->ptr->ptr;
            free(nodetobedeleted);
        }
        return h;
    
}

struct node *deletefront(struct node *h)
{	
	struct node *temp;
	temp=h;
	h=h->ptr;
	return h;	
}

struct node *deleteend(struct node *h)
{
	struct node *temp;
	temp=h;
	while(temp->ptr->ptr!=NULL)
	{
		temp=temp->ptr;
	}	
	temp->ptr=NULL;
	return h;
}

struct node *reverse(struct node *h)
{
	struct node *temp=NULL;
	struct node *temp1=NULL;
	temp=h->ptr;
	temp1=h->ptr->ptr;
	h->ptr=NULL;
	while(temp1->ptr!=NULL)
	{
		temp->ptr=h;
		h=temp;
		temp=temp1;
		temp1=temp1->ptr;
	}
	temp1->ptr=temp;
	temp->ptr=h;
	h=temp1;
	return h;
}

struct node * display(struct node *h)
{
	struct node *temp;
	temp=h;
	printf("head->");
	while(temp!=NULL)
	{
		printf("%d->",temp->value);
		temp=temp->ptr;
	}
	printf("NULL\n");
}

int main()
{
struct node *head;
head=NULL;

int i,val,val1;
printf("enter 1 to insert at front\n");
printf("enter 2 to insert at end\n");
printf("enter 3 to insert at anypoint\n");
printf("enter 4 to delete\n");
printf("enter 5 to delete at front\n");
printf("enter 6 to delete at end\n");
printf("enter 7 to reverse\n");
printf("enter 8 to display\n");
printf("enter 9 to exit\n");



while(i!=9)
{
	printf("enter 1/2/3/4/5/6/7/8\n");
	scanf("%d",&i);
 	switch(i)
        {
            	case 1:
            	printf("enter value to enter\n");
            	scanf("%d",&val);
            	head=insertatfront(head,val);
            	break;
		
		case 2:
            	printf("enter value to enter\n");
            	scanf("%d",&val);
            	head=insertatend(head,val);
            	break;

		case 3:
            	printf("enter value to enter\n");
            	scanf("%d",&val);
		printf("enter value that after node enter ");
		scanf("%d",&val1);
            	head=insert(head,val,val1);
            	break;
		
		case 4:
		printf("enter number to delete\n");
                scanf("%d",&val);
                head=ndelete(head,val);
                printf("deleted value is %d\n",val); 	
		break;	
		
		case 5:
                head=deletefront(head);
		break;

		case 6:
                head=deleteend(head);
		break;

		case 7:
		head=reverse(head);
		break;		
		
		case 8:
		display(head);
		break;
		
		case 9:
		break;
	}
}
}

