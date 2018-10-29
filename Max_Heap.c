#include<stdio.h>
#define N 100

int maxheap[N];
int item,i;
int currentsize=0;

int maxheapinsert(int maxheap[],int currentsize,int item)
{
    int i;
    if(currentsize==N)
    {
        printf("size is full");
        return;
    }
    i=currentsize;
    while(i>0&&item>maxheap[(i-1)/2])
    {
        maxheap[i]=maxheap[(i-1)/2];
        i=(i-1)/2;
    }
    maxheap[i]=item;

}

int maxheapdelete(int maxheap[],int currentsize)
{
    int item,temp,parent,child;
    if(currentsize==0)
    {
        printf("heap is empty");
        return;
    }
    item=maxheap[0];
    maxheap[0]=maxheap[currentsize-1];
    currentsize--;
    temp=maxheap[0];
    parent=0;
    child=1;
    while(child<currentsize)
    {
        if(child+1<currentsize && maxheap[currentsize]<maxheap[currentsize+1])
            child++;
        if(temp>maxheap[child])break;
        maxheap[parent]=maxheap[child];
        parent=child;
        child=2*parent+1;
    }
    maxheap[parent]=temp;
    return item;
}

void display(int maxheap[],int currentsize)
{
    int j;
    for(j=0;j<currentsize;j++)
    {printf("%d",maxheap[j]);}
}

int main()
{
    int x;
    printf("enter 1 to insert in heap\n");
    printf("enter 2 to delete max in heap\n");
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
            maxheapinsert(maxheap,currentsize,item);
            break;

            case 2:
            x=maxheapdelete(maxheap,currentsize);
            printf("deleted value is %d",x);
            break;

            case 3:
            display(maxheap,currentsize);
            break;

            case 4:
            break;

            default:
            printf("invelid choice\n");
            break;

        }
    }
}
