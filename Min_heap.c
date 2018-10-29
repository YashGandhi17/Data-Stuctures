#include<stdio.h>
#define N 100

int minheap[N];
int item,i;
int currentsize=0;

int minheapinsert(int minheap[],int currentsize,int item)
{
    int i;
    if(currentsize==N)
    {
        printf("size is full");
        return;
    }
    i=currentsize;
    while(i>0&&item<minheap[(i-1)/2])
    {
        minheap[i]=minheap[(i-1)/2];
        i=(i-1)/2;
    }
    minheap[i]=item;

}

int minheapdelete(int minheap[],int currentsize)
{
    int item,temp,parent,child;
    if(currentsize==0)
    {
        printf("heap is empty");
        return;
    }
    item=minheap[0];
    minheap[0]=minheap[currentsize-1];
    currentsize--;
    temp=minheap[0];
    parent=0;
    child=1;
    while(child<currentsize)
    {
        if(child+1<currentsize && minheap[currentsize]>minheap[currentsize+1])
            child++;
        if(temp<minheap[child])break;
        minheap[parent]=minheap[child];
        parent=child;
        child=2*parent+1;
    }
    minheap[parent]=temp;
    return item;
}

void display(int minheap[],int currentsize)
{
    int j;
    for(j=0;j<currentsize;j++)
    {printf("%d",minheap[j]);}
}

int main()
{
    int x;
    printf("enter 1 to insert in heap\n");
    printf("enter 2 to delete min in heap\n");
    printf("enter 3 to display heap\n");
    printf("enter 4 to exit\n");
    while(i!=5)
    {
        printf("enter 1/2/3/4\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            printf("enter value to insert\n");
            scanf("%d",&item);
            currentsize++;
            minheapinsert(minheap,currentsize,item);
            break;

            case 2:
            x=minheapdelete(minheap,currentsize);
            printf("deleted value is %d",x);
            break;

            case 3:
            display(minheap,currentsize);
            break;

            case 4:
            break;

            default:
            printf("invelid choice\n");
            break;

        }
    }
}
