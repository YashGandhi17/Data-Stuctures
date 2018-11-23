#include<stdio.h>
#include<stdlib.h>


struct AVLtree
{
    int val,height;
    struct AVLtree *left;
    struct AVLtree *right;
};

int max(int a,int b)
{
	return (a>b)?a:b;
}

int getheight(struct AVLtree *root)
{int height,htR,htL;
	if(root==NULL)
		return -1;
	else if(root->left==NULL && root->right==NULL)
		return 0;
	else
	{
		htL=getheight(root->left);
		htR=getheight(root->right);
		height=max(htL,htR)+1;
		return height;
	}
}

int getBalance(struct AVLtree *root)
{
	return getheight(root->left)-getheight(root->right);
}

struct AVLtree *singlerotateright(struct AVLtree *p)
{
	struct AVLtree *LC=p->left;
	p->left=LC->right;
	LC->right=p;
	p->height=getheight(p);
	LC->height=getheight(LC);
	return LC;
}

struct AVLtree *singlerotateleft(struct AVLtree *p)
{
	struct AVLtree *RC=p->right;
	p->right=RC->left;
	RC->left=p;
	p->height=getheight(p);
	RC->height=getheight(RC);
	return RC;
}

struct AVLtree *doublerotateleftright(struct AVLtree *p)
{
	struct AVLtree *temp;
	p->left=singlerotateleft(p->left);
	temp=singlerotateright(p);
	return temp;
}

struct AVLtree *doublerotaterightleft(struct AVLtree *p)
{
	struct AVLtree *temp;
	p->right=singlerotateright(p->right);
	temp=singlerotateleft(p);
	return temp;
}


struct AVLtree *insert(struct AVLtree *root,int val)
{
    struct AVLtree *newbtree;
    newbtree=(struct AVLtree*)malloc(sizeof(struct AVLtree));
    if(newbtree==NULL)
    {
        printf("malloc filed");
        return;
    }
    if(root==NULL)
    {
        newbtree->left=NULL;
        newbtree->right=NULL;
        newbtree->val=val;
        root=newbtree;
        return root;
    }
    if(root->val>val)
    {
        root->left=insert(root->left,val);
    }
    else
    {
        root->right=insert(root->right,val);
    }
    if(getBalance(root)==2)
    {
	if(getBalance(root->left)>=0)
		return singlerotateright(root);
	else
		return doublerotateleftright(root);
    }
    if(getBalance(root)==-2)
    {
    	if(getBalance(root->right)<=0)
		return singlerotateleft(root);
	else
		return doublerotaterightleft(root);
    }
    root->height=getheight(root);
    return root;
    free(newbtree);
}
struct AVLtree *ddelete(struct AVLtree *root,int val)
{
    struct AVLtree *temp;
    temp=(struct AVLtree*)malloc(sizeof(struct AVLtree));
    if(root==NULL)
    {
        return root;
    }
    if(root->val>val)
    {
        root->left=ddelete(root->left,val);
    }
    else if(root->val<val)
    {
        root->right=ddelete(root->right,val);
    }
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            temp=root->left;
            while(temp->right!=NULL)
            {temp=temp->right;}
            root->val=temp->val;
            root->left=ddelete(root->left,temp->val);
        }
        else
        {
            temp=root;
            if(temp->left==NULL)
                root=root->right;
            else if(temp->right==NULL)
                root=root->left;
        }
    }
    if(getBalance(root)==2)
    {
	if(getBalance(root->left)>=0)
		return singlerotateright(root);
	else
		return doublerotateleftright(root);
    }
    if(getBalance(root)==-2)
    {
    	if(getBalance(root->right)<=0)
		return singlerotateleft(root);
	else
		return doublerotaterightleft(root);
    }
    root->height=getheight(root);
    return root;
    free(temp);
}

void display(struct AVLtree *root)
{
    if(root!=NULL)
    {
	printf("\n%d\n",root->val);
        display(root->left);
        display(root->right);
    }
}


void main()
{
    struct AVLtree *root;
    int i,n,val=0;
    root=NULL;
    printf("enter 1 to insert\n");
    printf("enter 2 to delete\n");
    printf("enter 3 to display\n");
    printf("enter 4 to exit\n");
    while(i!=4)
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
            printf("enter value to delete\n");
            scanf("%d",&n);
            root=ddelete(root,n);
            printf("deleted value is %d\n",val);
            break;

            case 3:
            display(root);
            break;
        }
    }
}
/*output
enter 1 to insert
enter 2 to delete
enter 3 to display
enter 4 to exit
enter 1/2/3
1
eneter value to insert
40
enter 1/2/3
1
eneter value to insert
20
enter 1/2/3
1
eneter value to insert
10
enter 1/2/3
1
eneter value to insert
35
enter 1/2/3
1
eneter value to insert
50
enter 1/2/3
1
eneter value to insert
25
enter 1/2/3
1
eneter value to insert
30
enter 1/2/3
3

35

20

10

25

30

40

50
*/
