#include<stdio.h>
#include<stdlib.h>

int count=0;

struct btree
{
    int val;
    struct btree *l;
    struct btree *r;
};

struct btree *insert(struct btree *root,int val)
{
    struct btree *newbtree;
    newbtree=(struct btree*)malloc(sizeof(struct btree));
    if(newbtree==NULL)
    {
        printf("malloc filed");
        return;
    }
    count++;
    if(root==NULL)
    {
        newbtree->l=NULL;
        newbtree->r=NULL;
        newbtree->val=val;
        root=newbtree;
        return;
    }
    if(root->val>val)
    {
        root->l=insert(root->l,val);
    }
    else
    {
        root->r=insert(root->r,val);
    }
    return root;
    free(newbtree);
}
struct btree *ddelete(struct btree *root,int val)
{
    struct btree *temp,*node;
    temp=(struct btree*)malloc(sizeof(struct btree));
    if(root==NULL)
    {
        return;
    }
    if(root->val>val)
    {
        root->l=ddelete(root->l,val);
    }
    else if(root->val<val)
    {
        root->r=ddelete(root->r,val);
    }
    else
    {
        if(root->l!=NULL && root->r!=NULL)
        {
            temp=root->l;
            while(temp->r!=NULL)
            {temp=temp->r;}
            root->val=temp->val;
            root->l=ddelete(root->l,temp->val);
        }
        else
        {
            temp=root;
            if(temp->l==NULL)
                root=root->r;
            else if(temp->r==NULL)
                root=root->l;
        }
    }
    return root;
    free(temp);
}

int max(int a,int b)
{
    if(a==b)
        return a;
    else if(a>b)
        return a;
    else
        return b;
}

int height(struct btree *r)
{int h;
    if(r==NULL)
       h=-1;
    else
        h=max(height(r->l),height(r->r))+1;

    return h;
}

void display(struct btree *root)
{
    if(root!=NULL)
    {
        display(root->l);
        printf("\n%d\n",root->val);
        display(root->r);
    }
}


void main()
{
    struct btree *root;
    int i,n,val=0,h;
    root=NULL;
    printf("enter 1 to insert\n");
    printf("enter 2 to delete\n");
    printf("enter 3 to display\n");
    printf("enter 5 to exit\n");
    while(i!=6)
    {
        printf("enter 1/2/3/4/5 \n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            printf("eneter value to insert\n");
            scanf("%d",&n);
            root=insert(root,n);
            break;

            case 2:
            printf("enter value to delete\n");
            scanf("%d",&val);
            root=ddelete(root,val);
            printf("deleted value is %d\n",val);
            break;

            case 3:
            display(root);
            break;

            case 4:
            h=height(root);
            printf("height of tree is %d\n",h);

            case 5:
            break;
        }
    }
}
