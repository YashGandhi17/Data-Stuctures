#include<stdio.h>
#include<stdlib.h>

int count=1;

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
    if(root==NULL)
    {
        newbtree->l=NULL;
        newbtree->r=NULL;
        newbtree->val=val;
        ++count;
        root=newbtree;
        return;
    }
    if((count%2)==0)
    {
        root->l=insert(root->l,val);
    }
    else if(count%2==1)
    {
        root->r=insert(root->r,val);
    }
    return root;
    free(newbtree);
}

void preorder(struct btree *root)
{
    if(root!=NULL)
    {
        printf("\n%d\n",root->val);
        preorder(root->l);
        preorder(root->r);
    }
}

void inorder(struct btree *root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        printf("\n%d\n",root->val);
        inorder(root->r);
    }
}

void postorder(struct btree *root)
{
    if(root!=NULL)
    {
        postorder(root->l);
        postorder(root->r);
        printf("\n%d\n",root->val);

    }
}


void main()
{
    struct btree *root;
    int i,n;
    root=NULL;
    printf("enter 1 to insert\n");
    printf("enter 2 to preorder\n");
    printf("enter 3 to inorder\n");
    printf("enter 4 to postorder\n");
    printf("enter 5 to exit\n");
    while(i!=5)
    {
        printf("enter 1/2/3 \n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            printf("eneter value to insert\n");
            scanf("%d",&n);
            root=insert(root,n);
            break;

            case 2:
            preorder(root);

            case 3:
            inorder(root);

            case 4:
            preorder(root);
        }
    }
}
