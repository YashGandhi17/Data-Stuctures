#include<stdio.h>
#include<stdlib.h>
#define N 50
int q[N];

void insert(int q[],int *f,int *r,int val)
{
    if((*r)>=N-1)
        printf("queue is full");
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

int display(int q[N],int *f,int *r)
{int n;
    if((*f)==-1&&(*r)==-1)
        printf("queue is empty\n");
    else
        {
            for(n=(*f);n<=(*r);n++)
            {
                printf("%d\n",q[n]);
            }
        }
}

void main()
{
    int val,val1;
    int f,r,i;
    f=-1;r=-1;
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
            scanf("%d",&val1);
            insert(q,&f,&r,val1);
            break;

            case 2:
            val=qdelete(q,&f,&r);
            printf("deleted value is %d\n",val);
            break;

            case 3:
            display(q,&f,&r);
            break;
        }
    }
}
