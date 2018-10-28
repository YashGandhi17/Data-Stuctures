#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *lptr;
    struct node *rptr;
};

struct node *insertinorder(struct node **l,struct node **r,int val)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("malloc failed");
        return;
    }
    newnode->value=val;
    if(*l==NULL)
    {
        newnode->lptr=newnode->rptr=NULL;
        *l=*r=newnode;
        return;
    }
    if(val<=(*l)->value)
    {
        newnode->lptr=NULL;
        newnode->rptr=(*l);
        (*l)->lptr=newnode;
        (*l)=newnode;
        return;
    }
    if(val>=(*r)->value)
    {
        newnode->rptr=NULL;
        newnode->lptr=(*r);
        (*r)->rptr=newnode;
        (*r)=newnode;
        return;
    }
    temp=*l;
    while(temp->value<val)
    {
        temp=temp->rptr;
        newnode->lptr=temp->lptr;
        newnode->rptr=temp;
        temp->lptr->rptr=newnode;
        temp->lptr=newnode;
        return;
    }
}

struct node *ddelete(struct node **l,struct node **r,int val)
{
    struct node *temp;
    if(*l==NULL)
    {
        printf("list is empty");
        return;
    }
    if((*l)->value==val&&(*l)==(*r))
    {
        free(*l);
        *l=*r=NULL;
        return;
    }
    if((*l)->value==val)
    {
        temp=*l;
        *l=(*l)->rptr;
        (*l)->lptr=NULL;
        free(temp);
        return;
    }
    if((*r)->value==val)
    {
        temp=(*r);
        (*r)=(*r)->lptr;
        (*r)->rptr=NULL;
        free(temp);
        return;
    }
    temp=*l;
    while(temp!=NULL&&temp->value!=val)
    {
        temp=temp->rptr;
        (temp->lptr)->rptr=temp->rptr;
        (temp->rptr)->lptr=temp->lptr;
        free(temp);
        return;
    }
}

void display(struct node *l)
{
    printf("\n%d\n",l->value);
    if(l->rptr==NULL)
    {

        return;
    }
    display(l->rptr);

}

int main()
{
    int val,i;
    struct node *left,*right;
    left=right=NULL;
    printf("enter 1 to insert in order\n");
    printf("enter 2 to delete\n");
    printf("enter 3 to display\n");
    printf("enter 4 to exit\n");
    while(i!=4)
    {
        printf("enter 1/2/3/4\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            printf("enter value to enter\n");
            scanf("%d",&val);
            insertinorder(&left,&right,val);
            break;

            case 2:
            printf("enter value to delete\n");
            scanf("%d",&val);
            ddelete(&left,&right,val);
            break;

            case 3:
            display(left);
            break;
        }
    }
}
