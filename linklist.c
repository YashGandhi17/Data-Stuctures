#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *ptr;
};

struct node *insert(struct node *h,int val)
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
    return newnode;
}

struct node *ndelete(struct node *h,int val)
{
    struct node *temp;
    struct node *nodetobedeleted;
    if(h==val)
    {
        printf("list empty");
        return h;
    }
    else if(h->value==val)
    {
        nodetobedeleted=h;
        h=h->ptr;
        free(nodetobedeleted);
    }
    temp=h;
    while(temp->ptr!=NULL&&temp->value!=val)
    {
        temp=temp->ptr;
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
}

void display(struct node *h)
{
        printf("\n%d\n",h->value);
        if(h->ptr==NULL)
        {
            return;
        }
        display(h->ptr);

}

int main()
{
    int val,i;
    struct node *head;
    head=NULL;
    printf("enter 1 to insert\n");
    printf("enter 2 to delete\n");
    printf("enter 3 to display\n");
    printf("enter 4 to exit\n");
    while(i!=4)
    {
        printf("enter 1/2/3\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            printf("enter value to enter\n");
            scanf("%d",&val);
            head=insert(head,val);
            break;

            case 2:
            printf("enter number to delete\n");
            scanf("%d",&val);
            head=ndelete(head,val);
            printf("deleted value is %d\n",val);
            break;

            case 3:
            display(head);
            break;
        }
    }
}
